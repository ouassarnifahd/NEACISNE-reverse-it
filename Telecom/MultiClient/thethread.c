#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

void *runDuThread (void *p) {
	int i ;
	if (!strcmp((char *)p,"1")) {
		for (i=0 ; i<10 ; i++ ) {
			printf ("je suis le thread n° 1\n");
			usleep(1000000);
		}
	} else {
		for (i=0 ; i<20 ; i++ ){
			printf ("je suis le thread n° 2\n");
			usleep(1000000);
		}
	}
	pthread_exit(0);
}

int main (int argc, char **argv) {
	pthread_t th1, th2 ; int ret ;
	ret = pthread_create (&th1, NULL, runDuThread, (void *)"1") ;
	ret = pthread_create (&th2, NULL, runDuThread, (void *)"2") ;

	if (ret != 0) {
		perror ("Pb creation du thread\n") ; exit(0) ;
	}
	pthread_join(th1, (void **)&ret);
	pthread_join(th2, (void **)&ret);
	printf ("Fin main") ;
	return 0 ;
}
