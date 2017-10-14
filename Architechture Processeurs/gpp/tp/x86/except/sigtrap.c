/*
* file sigtrap.c
* brief exception #BP et signal UNIX SIGTRAP
* author hugo descoubes
*/

#include <stdio.h>

/*
* program entry point
*/
int main(int argc, char **argv) {
    __asm__("int3");
return 0;
}
