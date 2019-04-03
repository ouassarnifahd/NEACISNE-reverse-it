#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <pthread.h>


void rendre (int semid, int no);
void prendre (int semid, int no);

// union
union semun {
	int val;
	struct semid_ds *buf;
	ushort *array;
} arg;


int main (int argc, char* argv[]) {
    char c;
    int pid, ret, shmid, i, er;
    key_t cle;
    int semid;
	
	cle=ftok("fichier.txt" ,0);
	if (cle==(key_t) -1) { perror ("erreur ftok\n");exit (1); }
    
    semid=semget(cle,2,IPC_CREAT|0666);
    if (semid==-1) { perror("erreur semget\n");exit(1); }
    
    // initialisation à 1 du semaphore	
	arg.val = 1 ;
	er=semctl(semid,1,SETVAL,arg);
	if (er==-1) {perror("erreur semctl\n");exit(1);}
    
    shmid=shmget(cle,sizeof(char),IPC_CREAT|0666);
    
    char *tab ;
	tab = shmat(shmid, NULL, 0);
	tab[0] = 1;
    
    pid = fork() ;
    if (pid == 0) 
    {  // code du fils 
        for(c='a'; c<='z'; c++) 
        {
		    prendre(semid, 0);
		    tab[tab[0]] = c;
		    tab[0] ++;
		    rendre(semid, 1);	        		    
        }
        _exit(EXIT_SUCCESS);
    }
    else {
        for(c='A'; c<='Z'; c++) 
        {            
	        prendre(semid, 1);
	        tab[tab[0]] = c;
		    tab[0] ++;
		    rendre(semid, 0);	                
        }
                       
    }    	
	
	wait(&ret);

	tab[tab[0]]=0;
	
	printf("%s\n", tab+1);
	fflush(stdout);
	
	semctl(semid,0,IPC_RMID);
	shmctl(shmid,IPC_RMID,0);
        
    return EXIT_SUCCESS;
    
}


void rendre (int semid, int no) {
	struct sembuf op[1];
	int er ;
	op[0].sem_num=no; // semaphore no
	op[0].sem_op=1; // libération (à mettre à –1 pour une prise)
	op[0].sem_flg=0; // operation bloquante
	er=semop (semid,op,1);
	if (er==-1) {perror("erreur semop rendre\n");exit(1);}
}

void prendre (int semid, int no) {
	struct sembuf op[1];
	int er ;
	op[0].sem_num=no; // semaphore no
	op[0].sem_op=-1; // libération (à mettre à –1 pour une prise)
	op[0].sem_flg=0; // operation bloquante
	er=semop (semid,op,1);
	if (er==-1) {perror("erreur semop prendre\n");exit(1);}
}
