#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
// A compiler avec : gcc exTh.c -o exTh.exe -lpthread
void *my_thread_process (void *arg) {
  int i ;
  for (i=0 ; i<10 ; i++)
	printf ("i = %d\n ", i);
  pthread_exit (0) ;
}

main (int ac, char **av) {
  pthread_t th1 ;
  int ret ;
  if (pthread_create (&th1, NULL, my_thread_process, "2") < 0) {
    perror ( "pb thread_create\n") ;
    exit (1) ;
  }
  pthread_join (th1, (void *)&ret) ;
}
