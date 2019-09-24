#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

// Code d'exemple sur l'initialisation d'un semaphore et une opération de rendre.


void rendre (int semid, int no) {
    struct 	sembuf op[1]; int er ;
    op[0].sem_num=no; /*semaphore no */
 	op[0].sem_op=1; /*restitution*/
 	op[0].sem_flg=0; /*operation bloquante*/
	er=semop (semid,op,1);
	if (er==-1) {perror ("erreur semop\n"); exit (1);}
}	      

main (int ac, char **argv) {
	key_t cle;
	int er;	
	
	union semun {
               int val;
               struct semid_ds *buf;
               ushort *array;
  } arg;

	int semid ;
  int ret ;
  cle=ftok(argv[0],0);
  if (cle==(key_t) -1) { perror ("erreur ftok\n"); exit(1); }
  semid=semget(cle,1,IPC_CREAT|0600);
  if (semid==-1) {perror("erreur semget\n"); exit (1);}
  arg.val=1;
  er=semctl(semid,0,SETVAL,arg);
  if (er==-1) {perror("erreur semctl\n"); exit (1);} 
  rendre(semid, 0) ; // rendre le sémaphore n° 0 du groupe semid
  // Penser à faire "ipcs -t" dans un shell pour voir le semaphore créé
}
