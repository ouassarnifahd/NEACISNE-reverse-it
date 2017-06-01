/* Adapted from https://github.com/lettier/ntpclient */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define NTP_TIMESTAMP_DELTA 2208988800ull // 70 years worth of seconds

void error(char* msg) {
    perror(msg);
    exit(0);
}

/* NTP packet
*                        1                   2                   3
*    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*   |LI | VN  |Mode |    Stratum    |     Poll      |   Precision   |
*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*   |                           Root Delay                          |
*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*   |                        Root Dispertion                        |
*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*   |                      Reference Identifier                     |
*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*   |                  Reference Timestamp seconds                  |
*   |            Reference Timestamp fraction of a second           |
*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*   |                  Originate Timestamp seconds                  |
*   |            Originate Timestamp fraction of a second           |
*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*   |                   Receive Timestamp seconds                   |
*   |             Receive Timestamp fraction of a second            |
*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*   |                   Transmit Timestamp seconds                  |
*   |             Transmit Timestamp fraction of a second           |
*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*/
typedef struct {

    unsigned li   : 2;       // 2 bits  - Leap indicator.
    unsigned vn   : 3;       // 3 bits  - Version number of the protocol.
    unsigned mode : 3;       // 3 bits  - Mode.

    uint8_t stratum;         // 8 bits  - Stratum level of the local clock.
    uint8_t poll;            // 8 bits  - Maximum interval between successive messages.
    uint8_t precision;       // 8 bits  - Precision of the local clock.

    uint32_t rootDelay;      // 32 bits - Total round trip delay time.
    uint32_t rootDispersion; // 32 bits - Max error aloud from primary clock source.
    uint32_t refId;          // 32 bits - Reference clock identifier.

    uint32_t refTm_s;        // 32 bits - Reference time-stamp seconds.
    uint32_t refTm_f;        // 32 bits - Reference time-stamp fraction of a second.

    uint32_t origTm_s;       // 32 bits - Originate time-stamp seconds.
    uint32_t origTm_f;       // 32 bits - Originate time-stamp fraction of a second.

    uint32_t rxTm_s;         // 32 bits - Received time-stamp seconds.
    uint32_t rxTm_f;         // 32 bits - Received time-stamp fraction of a second.

    uint32_t txTm_s;         // 32 bits - Transmit time-stamp seconds.
    uint32_t txTm_f;         // 32 bits - Transmit time-stamp fraction of a second.

} ntp_packet;                // Total: 384 bits or 48 bytes.

int main(int argc, char const *argv[]) {
    ssize_t socket_fd, fd;

    // Init paquet vide
    ntp_packet packet = {0};
	memset(&packet, 0, sizeof(ntp_packet));
    // Mettre LI = 00, VN = 011 et MODE = 011
    *((char *)&packet + 0) = 0x1b; // 0001_1011

    // UDP socket init
    socket_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(socket_fd < 0)
        error("ERROR opening socket");

    struct sockaddr_in serv_addr;

    serv_addr.sin_addr.s_addr = inet_addr("193.49.200.16"); // ntp.ensicaen.fr
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(123);

    // Connect
    if(connect(socket_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		error("ERROR connecting");
    // Writing (same as sendto)
    fd = write(socket_fd, (char*)&packet, sizeof(ntp_packet));
    if(fd < 0)
    	error( "ERROR writing to socket" );
    // Reading (same as recvfrom)
    fd = read(socket_fd, (char*)&packet, sizeof(ntp_packet));
    if(fd < 0)
        error( "ERROR reading from socket" );

    // Adapting Transmit Timestamp...
    packet.txTm_s = ntohl(packet.txTm_s);
    packet.txTm_f = ntohl(packet.txTm_f);

    time_t txTm_s = (time_t)(packet.txTm_s - NTP_TIMESTAMP_DELTA);

    //Printing time in format Day Month DD hh:mm:ss Year
    printf("Time: %s", ctime((const time_t*)&txTm_s));

    return 0;
}
