/*
* file function.c
* brief programme d'analyse des m�canismes de gestion de la pile
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
 * function incr�mentant la valeur d'entr�e
 */
//inline int inc(int bar) {
int inc(register int bar) {
return bar+1;
}

