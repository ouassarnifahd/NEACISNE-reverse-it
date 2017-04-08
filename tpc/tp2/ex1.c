#include<stdio.h>
int main(int argc, char* argv[]) {
	int a,b,c,s;
	printf("Donnez un nombre entier: ");
	scanf("%d", &a);
	printf("Donnez un 2eme nombre entier: ");
	scanf("%d", &b);
	printf("Donnez un 3eme nombre entier: ");
	scanf("%d", &c);
	s=(a+b+c)/3;
	printf("La moyenne entiere des nombres %d, %d et %d est: %d", a, b, c, s);
	return 0;
}
