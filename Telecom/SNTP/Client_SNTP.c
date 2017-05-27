#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define NTP_TIMESTAMP_DELTA 2208988800ull

void error(char* msg){
    perror(msg); // Print the error message to stderr.
    exit(0); // Quit the process.
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
*   |                                                               |
*   |                    Reference Timestamp (64)                   |
*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*   |                                                               |
*   |                    Originate Timestamp (64)                   |
*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*   |                                                               |
*   |                     Receive Timestamp (64)                    |
*   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*   |                                                               |
*   |                     Transmit Timestamp (64)                   |
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

} ntp_packet;                // Total: 384 bits ou 48 octets.

int main(int argc, char const *argv[]) {
    ssize_t socket_fd, fd;
    // char *host = "ntp.ecole.ensicaen.fr";
    char *host = "pool.ntp.org";

    // Init paquet vide
    ntp_packet packet = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	memset(&packet, 0, sizeof(ntp_packet));
    // Mettre LI = 00, VN = 011 et MODE = 011
    *((char *)&packet + 0) = 0x1b;

    // UDP socket init
    socket_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(socket_fd < 0)
        error("ERROR opening socket");

    // Server data
    struct hostent *server;
    server = gethostbyname(host);
    if(server == NULL)
        error("ERROR, no such host");

    // Server address data
    struct sockaddr_in serv_addr;
    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(123);
    // Connecting...
    if(connect(socket_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		error("ERROR connecting");
    // Writing...
    fd = write(socket_fd, (char*)&packet, sizeof(ntp_packet));
    if(fd < 0)
    	error( "ERROR writing to socket" );
    // Reading...
    fd = read(socket_fd, (char*)&packet, sizeof(ntp_packet));
    if(fd < 0)
        error( "ERROR reading from socket" );

    // Adapting Transmit Timestamp...
    packet.txTm_s = ntohl(packet.txTm_s);
    packet.txTm_f = ntohl(packet.txTm_f);

    time_t txTm = (time_t)(packet.txTm_s - NTP_TIMESTAMP_DELTA);

    printf("Time: %s", ctime((const time_t*)&txTm));

    return 0;
}
