/*
* file readonly.c
* brief force une écriture sur une section en lecture seule
* author hugo descoubes
*/

/*
* program entry point
*/
int main(int argc, char **argv) {
	char *pfoo = "hello world";

    *pfoo = 'H';
 
return 0;
}
