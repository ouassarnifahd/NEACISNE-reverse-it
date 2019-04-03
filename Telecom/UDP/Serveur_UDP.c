#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_LEN 1000

int main(int argc, char **argv) {
	ssize_t socket_id, recvfrom_id;
	unsigned char paquet[BUF_LEN];
	struct sockaddr_in adTo, adFrom; // Addresses :To/From...
	int port, lenAdFrom = sizeof(adFrom);
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
	if ((recvfrom_id = recvfrom(socket_id, paquet, BUF_LEN, 0, (struct sockaddr *)&adFrom, (socklen_t *)&lenAdFrom)) < 0) {
		perror("\nERREUR recvfrom\n"); exit(-1);
	}
	paquet[recvfrom_id]='\n';
	printf("From: %s\n", inet_ntoa(adFrom.sin_addr));
	printf("Data: %s\n", paquet);
    close(socket_id);
    return(0);
}
