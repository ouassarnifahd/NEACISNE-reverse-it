#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define BUFF_LEN 1024

void *Thread (void *p) {
	int lgr, sd = *(int *)p;
	unsigned char paquet[BUFF_LEN];       // paquet recu / envoye
	printf("Nouveau Client !\n");

		lgr = recv(sd, paquet, BUFF_LEN, 0);  // on lit au maximum 64 octets venant du client.
		paquet[lgr-1]= '\0';					// le paquet reçu n'est pas une chaine de caractère => ajout de "\0" à la fin
		printf ("%s\n", paquet);

	close (sd);                         // fermeture de la socket de dialogue
	pthread_exit(0);
}

int main (int argc, char **argv) {
	pthread_t thread;
	ssize_t ret, err, sockfd /* socket d'ecoute du port */, sd /* socket de dialogue avec le client */;
	struct sockaddr_in adTo, adFrom;    // adresse au format internet
	size_t ladd = sizeof(struct sockaddr_in);  // longueur de l'adresse de reception
	int port;
	if (argc !=2 ) {
		printf ("Erreur argument 1 : %s no_port \n", argv[0]); exit (-1);
	}
	else  sscanf (argv[1], "%d", &port);

	/* On ouvre la socket  Internet en mode connecte. 6 est le numéro de TCP , cf. le fichier /etc/protocols*/
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 6)) < 0) {
		perror("\nERREUR socket\n"); exit(-1);
	}

	adTo.sin_family = AF_INET;           // adresses de type internet
	adTo.sin_port = htons(port);         // numero de port du serveur
	adTo.sin_addr.s_addr = INADDR_ANY;   // accepte les connexions de n'importe quelle interface ethernet, wifi...

	/* On attache la socket au port d'ecoute */
	err = bind (sockfd, (struct sockaddr *)&adTo, sizeof(struct sockaddr_in));
	if (err < 0) { perror ("bind : "); exit(-1); }

	/* On fixe le nombre maximum de clients simultanes en attente. Ici 1 seule*/
	err = listen (sockfd, 1);
	if (err < 0) { perror ("listen : "); exit(-1); }

	while(1) {
		sd = accept(sockfd, (struct sockaddr *)&adFrom, (unsigned int *)&ladd);    /* attente d'une connexion. La fonction accept est boquante et cree une socket de dialogue si un client se connecte.*/
		ret = pthread_create(&thread, NULL, Thread, (void *)&sd) ;
	}
	return 0;
}
