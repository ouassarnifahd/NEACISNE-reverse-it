#include <stdio.h>
#include <unistd.h>

main () {
    char c;
    int pid ;
    pid = fork() ;
    if (pid == 0) {  // code du fils 
        printf ("pid  = %d \n", pid) ;
        for(c='a'; c<='z'; c++) {
            printf ("%c ", c);
        }
    }
    else {
        printf ("pid fils  = %d\n ", pid) ;
        for(c='A'; c<='Z'; c++) {
            printf ("%c ", c);
        } 
    }
    printf ("Exécuté par les 2\n") ;
    for(;;) ;
}

