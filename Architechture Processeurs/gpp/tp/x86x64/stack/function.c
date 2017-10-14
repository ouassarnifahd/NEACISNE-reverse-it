/*
* file function.c
* brief programme d'analyse des mécanismes de gestion de la pile
* author 
*/

/* privates prototypes */
//inline int inc(int bar) __attribute__((always_inline));
int inc(int bar);

/*
* program entry point
*/
int main(void){
	int foo;

	foo = inc(1);

return 0;
}

/*
 * function incrémentant la valeur d'entrée
 */
//inline int inc(int bar) {
int inc(register int bar) {
return bar+1;
}

