#include<stdio.h>
int main(int argc, char* argv[]) {
	int a,b,c;
	printf("Donnez un nombre entier: ");
	scanf("%d", &a);
	printf("Donnez un 2eme nombre entier: ");
	scanf("%d", &b);
	printf("Donnez un 3eme nombre entier: ");
	scanf("%d", &c);
	if(a<=b && a<=c){
		printf("Le minimum est: %d", a);
	}
	else {
		if(b<=a && b<=c){
		printf("Le minimum est: %d", b);
		}
		else {
			if(c<=a && c<=b){
				printf("Le minimum est: %d", c);
			}
		}
	}
	return 0;
}
