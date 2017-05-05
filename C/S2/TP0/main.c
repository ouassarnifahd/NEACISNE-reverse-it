#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"tactix.h"

int main(int argc, char const *argv[]){
	bool play=1;
	while (play) {
		play=tacTix();
	}
	return EXIT_SUCCESS;
}
