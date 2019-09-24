/* Mesure le tps de commutation de Linux
 * Faire sudo sh -c "echo 0 > /sys/devices/system/cpu/cpu1/online"
 * pour désactiver 1 coeur.
 * temps trouvé : 8 ms sur HP core i7 2,6 GHz
 * le time slice se trouve dans un fichier linux-rc/kernel/sched.c
 * Il peut varier de 5ms à 800 ms avec un temps par défaut à 100 ms

*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAXCPT 2000000000

int cpt_commut = 0 ;
int flag =0 ;

void *my_thread_process1(void *arg) {
  int i ;
  int tmp ;
  for (i=0 ; i<MAXCPT ; i++) {
    if (flag!=1 ) {
		flag=1 ;
		cpt_commut++ ;
	}
	tmp = tmp*3 +7;
	tmp  = (tmp-7)/3 ;
  }
  pthread_exit (0) ;
}


void *my_thread_process2 (void *arg) {

  int i ;
  int tmp ;
  for (i=0 ; i<MAXCPT ; i++) {
    if (flag!=2 ) {
		flag=2 ;
		cpt_commut++ ;
	}
	tmp = tmp*3 +7;
	tmp  = (tmp-7)/3 ;
  }
  pthread_exit ((int)0) ; // Attention au cast, sinon retourne un long 64 bits
  
}

main (int ac, char **av) {
  pthread_t th1, th2 ;
  
  long long ret ;

	unsigned int tps2, tps1 = time(NULL) ;
	printf ("tps1 = %d\n", tps1);
  if (pthread_create (&th1, NULL, my_thread_process1, "1") < 0) {
    fprintf (stderr, "pthread_create error 1\n") ;
    exit (1) ;
  }
  if (pthread_create (&th2, NULL, my_thread_process2, "2") < 0) {
    fprintf (stderr, "pthread_create error 2\n") ;
    exit (1) ;
  }
  
  (void) pthread_join (th1, (void *)&ret) ;
  (void) pthread_join (th2, (void *)&ret) ;
  tps2 = time(NULL) ;
  	printf ("tps2 = %d\n", tps2);
  	printf ("tps1 = %d\n", tps1);

  printf ("tps = %d\n cpt_commut =  %d  quota = %.2f ms",(tps2-tps1),  cpt_commut, ((tps2-tps1)*1000.0)/cpt_commut);
}
