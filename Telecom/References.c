// http://broux.developpez.com/articles/c/sockets/

/* INCLUDES    */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

/* DEFINITIONS */
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
// int close(int fd); from unistd.h

/* TYPES       */
typedef int SOCKET;

typedef struct sockaddr_in SOCKADDR_IN; // def in sys/socket.h as ==>
// struct sockaddr_in {
//     uint8_t         sin_len;       /* longueur totale      */
//     sa_family_t     sin_family;    /* famille : AF_INET    */
//     in_port_t       sin_port;      /* le numéro de port    */
//     struct in_addr  sin_addr;      /* l'adresse internet   */
//     unsigned char   sin_zero[8];   /* un champ de 8 zéros  */
// };

typedef struct sockaddr SOCKADDR; // def in sys/socket.h as ==>
// struct sockaddr {
    // unsigned char   sa_len;         /* longueur totale 		*/
    // sa_family_t     sa_family;      /* famille d'adresse 	*/
    // char            sa_data[14];    /* valeur de l'adresse	*/
// };

typedef struct in_addr IN_ADDR; // def in sys/socket.h as ==>
// struct in_addr {
//     in_addr_t	s_addr;
// };

typedef struct hostent HOSTINFO; //def in netdb.h as ==>
// struct hostent {
//     char    *h_name;        /* official name of host */
//     char    **h_aliases;    /* alias list */
//     int     h_addrtype;     /* host address type */
//     int     h_length;       /* length of address */
//     char    **h_addr_list;  /* list of addresses from name server */
// };
// #define h_addr h_addr_list[0] /* address, for backward compatibility */

// Création du socket avec: int socket(int domain, int type, int protocol);
SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
if(sock == INVALID_SOCKET){
    perror("socket()");
    exit(errno);
}

// Connexion au serveur avec gethostbyname: struct hostent * gethostbyname(const char *name); same as nslookup
HOSTINFO *hostinfo = NULL;
SOCKADDR_IN sin = {0};                          /* initialise la structure avec des 0 */
const char *hostname = "theWebSiteHere";

hostinfo = gethostbyname(hostname);             /* on récupère les informations de l'hôte auquel on veut se connecter */
if (hostinfo == NULL) {
    fprintf (stderr, "Unknown host %s.\n", hostname);
    exit(EXIT_FAILURE);
}

sin.sin_addr = *(IN_ADDR *)hostinfo->h_addr;    /* l'adresse se trouve dans le champ h_addr de la structure hostinfo */
sin.sin_port = htons(PORT);                     /* on utilise htons pour le port */
sin.sin_family = AF_INET;

// Initialisation de la connexion sur la socket: int connect(int socket, const struct sockaddr *address, socklen_t address_len);
if(connect(sock,(SOCKADDR *)&sin, sizeof(SOCKADDR)) == SOCKET_ERROR) {
    perror("connect()");
    exit(errno);
}

// bind() assigns a name to an unnamed socket.
// When a socket is created with socket it exists in a name space (address family) but has no name assigned.
// bind() requests that address be assigned to the socket.
int bind(int socket, const struct sockaddr *address, socklen_t address_len);

// listen for connections on a socket
int listen(int socket, int backlog);

// UNTILL this line:
// The argument socket is a socket that has been created with socket(), bound to an address with bind(), and is listening for connections after a listen().
//
// accept() extracts the first connection request on the queue of pending connections,
//          creates a new socket with the same properties of socket, and
//          allocates a new file descriptor for the socket.
//
// If no pending connections are present on the queue, and the socket is not marked as non-blocking, accept() blocks the caller until a connection is present.
// If the socket is marked non-blocking and no pending connections are present on the queue, accept() returns an error as described below.(man 2 accept for more)
// The accepted socket may not be used to accept more connections. The original socket socket, remains open.
int accept(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);

// Envoie d'un message a travers une socket
ssize_t send(int socket, const void *buffer, size_t length, int flags);
ssize_t sendto(int socket, const void *buffer, size_t length, int flags, const struct sockaddr *dest_addr, socklen_t dest_len);

// Reception d'un message par une socket
ssize_t recv(int socket, void *buffer, size_t length, int flags);
ssize_t recvfrom(int socket, void *restrict buffer, size_t length, int flags, struct sockaddr *restrict address, socklen_t *restrict address_len);
