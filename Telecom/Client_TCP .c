// @TITLE : Serveur d'echo sur le port passé en argument 
// @BRIEF : Répête ce qu'il reçoit et l'affiche. La connexion s'arrete apres reception de bye.
// @AUTHOR : Ph Lefebvre - ENSI de Caen

#include <errno.h>                 // biblio des erreurs
#include <sys/socket.h>            // biblio pour les socket
#include <sys/types.h>
#include <arpa/inet.h> 
#include <netinet/in.h>
#include <stdio.h>                 // biblio pour les E/S.
#include <stdlib.h> 

#define BUF_LEN 1000

int main(int argc, char **argv) {
	int s;                         // socket d'ecoute du port
	int index;	
	unsigned char paquet[BUF_LEN];             // paquet recu / envoye

	struct sockaddr_in adTo, adFrom;    // adresse au format internet
  
	unsigned int ladd=sizeof (struct sockaddr_in);  // longueur de l'adresse de reception
	int port;						// port de connexion

	if (argc !=3 ) {
		printf ("Erreur arguments : %s <ip_addr> <port> \n", argv[0]); exit (-1);
	}
	else  sscanf (argv[2], "%d", &port); 
	
	/* On ouvre la socket  Internet en mode connecte. 6 est le numéro de TCP , cf. le fichier /etc/protocols*/
	if ((s = socket(AF_INET, SOCK_STREAM, 6)) < 0) {
		perror("\nERREUR socket\n"); exit(-1);
	}
  
	adTo.sin_family = AF_INET;           // adresses de type internet
	adTo.sin_port = htons (port);        // numero de port du serveur
	adTo.sin_addr.s_addr = inet_addr(argv[1]);   

    printf("Escape character is '^]'.\n");
    do {
		char *str=fgets(paquet,BUF_LEN,stdin);
		if(!str){ printf("Buffer non valide!"); close (s); return(-1);}
		printf("Sending \" %s \"...", paquet);	
		send (s, paquet, BUF_LEN, 0);          // reemission du paquet recu.
	} while ( 1 );
    close (s);							// fermeture de la socket d'écoute
    return(0) ;
}

