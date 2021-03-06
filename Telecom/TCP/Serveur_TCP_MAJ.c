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

int main( int argc, char **argv) {
	int er, lgr;                   // gestion des erreurs
	int s;                         // socket d'ecoute du port
	int sd;                        // socket de dialogue avec le client.
	int index;
	unsigned char paquet[64];             // paquet recu / envoye

	struct sockaddr_in adTo, adFrom;    // adresse au format internet

	unsigned int ladd=sizeof (struct sockaddr_in);  // longueur de l'adresse de reception
	int port;						// port de connexion

	if (argc !=2 ) {
		printf ("Erreur argument 1 : %s no_port \n", argv[0]); exit (-1);
	}
	else  sscanf (argv[1], "%d", &port);

	/* On ouvre la socket  Internet en mode connecte. 6 est le numéro de TCP , cf. le fichier /etc/protocols*/
	if ((s = socket(AF_INET, SOCK_STREAM, 6)) < 0) {
		perror("\nERREUR socket\n"); exit(-1);
	}

	adTo.sin_family = AF_INET;           // adresses de type internet
	adTo.sin_port = htons (port);        // numero de port du serveur
	adTo.sin_addr.s_addr = INADDR_ANY;   // accepte les connexions de n'importe quelle interface ethernet, wifi...

	/* On attache la socket au port d'ecoute */
	er = bind (s, (struct sockaddr *) &adTo, sizeof (struct sockaddr_in));
	if (er < 0) {
		perror ("bind : "); exit(-1);
	}

  /* On fixe le nombre maximum de clients simultanes en attente. Ici 1 seule*/
	er = listen (s, 1);
	if (er < 0) {
		perror ("listen : "); exit(-1);
	}

    sd = accept( s, (struct sockaddr *) &adFrom, &ladd);             /* attente d'une connexion. La fonction accept est boquante et cree une socket de dialogue si un client se connecte.*/
    printf ("1 client !\n");
    do {
		lgr = recv( sd, paquet, 64, 0 );     // on lit au maximum 64 octets venant du client.
		if (lgr == 0 ) {printf("Deconnexion par le client !\n\n") ; exit(0) ;}
		if (lgr < 0 ) {perror ("pb recv") ; exit(-1) ;}
	  	paquet[lgr]= '\0';						// le paquet reçu n'est pas une chaine de caractère => ajout de "\0" à la fin
		printf ("paquet de longueur %d recu : %s\n",lgr,paquet);
		for(index=0; paquet[index]!='\0'; index++){
			paquet[index]=toupper(paquet[index]);
		}
		send (sd, paquet, lgr, 0);          // reemission du paquet recu.
	}
	while ((strncmp ((char *)paquet, "BYE", 3)));      // on compare les 3 premiers octets recus a "bye"
    printf (" Mon client s'est deconnecte.\n");
	close (sd);                         // fermeture de la socket de dialogue
    close (s);							// fermeture de la socket d'écoute
    return(0) ;
}
