#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_LEN 8

int main(int argc, char **argv) {
	ssize_t socket_id, sendto_id;
	unsigned char paquet[BUF_LEN] = "Coucou!\n";
	struct sockaddr_in adTo; // AddresseTo...
	int port;
	if (argc !=3 ) {
		printf ("Erreur arguments : %s <ip_addr> <port> \n", argv[0]);
		exit (-1);
	}
	else  sscanf (argv[2], "%d", &port);
	// From sys/socket: int socket(int domain, int type, int protocol);
	if ((socket_id = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("\nERREUR socket\n"); exit(-1);
	}
	adTo.sin_family = AF_INET;
	adTo.sin_port = htons(port);
	adTo.sin_addr.s_addr = inet_addr(argv[1]);
	// From sys/socket: ssize_t sendto(int socket, const void *buffer, size_t length, int flags, const struct sockaddr *dest_addr, socklen_t dest_len);
	if ((sendto_id = sendto(socket_id, paquet, BUF_LEN, 0, (struct sockaddr *)&adTo, sizeof(adTo))) < 0) {
		perror("\nERREUR sendto\n"); exit(-1);
	}
    close(socket_id);
    return(0);
}
