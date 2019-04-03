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

char home[] = "index.html";
char send_200[100];
char send_404[] = "HTTP/1.1 404 ERROR\n\n";

char* extractpagename(char *request){
	const char delim[2] = " ";
	char *req = malloc(strlen(request));
	memcpy(req,request,strlen(request));
	char* filename = strtok(req+5,delim);
	return filename;
}

char* extractcontent_type(char *request){
	const char delim[2] = ",";
	char *req = malloc(strlen(request));
	memcpy(req,request,strlen(request));
	char* Acceptline = strstr(req,"Accept");
	strtok(Acceptline + 8,delim);
	return strtok(Acceptline + 8,"\n");
}

int getSizeFile(FILE *fd){
	int size, pos=ftell(fd);
	fseek(fd,0,SEEK_END);
	size=ftell(fd);
	fseek(fd,pos,SEEK_SET);
	return size;
}

void *Thread (void *p) {
	int lgr, sd = *(int *)p;
	unsigned char paquet[BUFF_LEN];
    lgr = recv(sd, paquet, BUFF_LEN, 0);
	paquet[lgr-1]= '\0';
	// printf("%s\n", paquet);
    char *pagename = extractpagename((char*)paquet), *type = extractcontent_type((char*)paquet);
	sprintf(send_200,"HTTP/1.1 200 OK \n content-type: %s \n\n",type);
	if (!strncmp(pagename,"HTTP/1.1\nHost:",5))
		memcpy(pagename,home,strlen(pagename));
	printf("\nRequesting %s \ncontent-type %s\n", pagename, type);
	FILE * webpage = fopen(pagename,"r");
	if(!webpage){
		printf("\nERROR 404 %s Not found!\n", pagename);
    	send(sd, send_404, strlen(send_404),0);
		FILE * E404 = fopen("404.html", "r");
		int size = getSizeFile(E404);
    	char* page = malloc(size);
		fread(page, 1, size, E404);
		send(sd, page, strlen(page),0);
		fclose(E404);
		free(page);
	} else {
		printf("\nSending %s\n", pagename);
    	send(sd, send_200, strlen(send_200),0);
		int size = getSizeFile(webpage);
    	char* page = malloc(size);
		fread(page, 1, size, webpage);
    	send(sd, page, strlen(page),0);
		fclose(webpage);
		free(page);
    }
	close (sd);
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
	if (err < 0) {perror ("bind : "); exit(-1);}

	/* On fixe le nombre maximum de clients simultanes en attente. Ici 1 seule*/
	err = listen (sockfd, 1);
	if (err < 0) { perror ("listen : "); exit(-1); }

	printf("Starting localhost at %d\n", port);

	while(1) {
		sd = accept(sockfd, (struct sockaddr *)&adFrom, (unsigned int *)&ladd);    /* attente d'une connexion. La fonction accept est boquante et cree une socket de dialogue si un client se connecte.*/
		ret = pthread_create(&thread, NULL, Thread, (void *)&sd);
	}
	return 0;
}
