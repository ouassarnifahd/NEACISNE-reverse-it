/*
* file nullptr.c
* brief pointeur nul déréférencé (cas de beaucoup de systèmes)
* author hugo descoubes
*/

#include <stdio.h>

/*
* program entry point
*/
int main(int argc, char **argv) {
	char *pfoo = NULL;

    *pfoo = 'a';
	
return 0;
}
