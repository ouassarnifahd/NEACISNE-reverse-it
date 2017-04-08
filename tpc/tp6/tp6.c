#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define lentab 40

//Eratosthene
void init(int *table, int N){
    int i;
    for(i=0; i<N; i++){
        table[i]=1;
    }
}

void eratosthene(int *table, int N){
    int j=2, k;
    table[0]=0;
    table[1]=0;
    while(j<=N){
        if(table[j]==1){
            for(k=j*j; k<N; k=k+j){
                table[k]=0;
            }
        }
        j++;
    }
    return ;
}

void translate(int *table, int N){
    int i;
    for(i=0; i<N; i++){
        if(table[i]==1){
            table[i]=i;
        }
    }
}

//random table
void randtable(int *table, int N){
    srand(time(NULL));
    int i;
    for(i=0; i<N; i++){
        table[i]=rand()%100;
    }
}

int somtab(int *table, int N){
    int som=0, i;
    for(i=0; i<N; i++){
        som+=table[i];
    }
    return som;
}

int maxtab(int *table, int N){
    int max=table[0], i;
    for(i=0; i<N; i++){
        if(table[i]>=max){
            max=table[i];
        }
    }
    return max;
}

int minadr(int *table, int N){
    int min=0, i;
    for(i=0; i<N; i++){
        if(table[i]<=table[min]){
            min=i;
        }
    }
    return min;
}

void tritab(int *tablein, int *tableout, int N){
    int i, tmp[N];
    for(i=0; i<N; i++){
        tmp[i]=tablein[i];
    }
    for(i=0; i<N; i++){
        tableout[i]=tmp[minadr(tmp,N)];
        tmp[minadr(tmp,N)]=maxtab(tmp,N);
    }
}

int effacerzero(int *tab, int N){
	int i,k;
	for(i=0; i<N; i++){
		if(tab[i]==0){
			for(k=i; k<N; k++){
				tab[k]=tab[k+1];
			}
			N=N-1;
			i=i-1;
		}
	}
	return N;
}

void afficher (int tableau[], int taille) {
    int i ;
    printf("tab=[ ");
    for (i = 0 ; i<taille ; i++ )
        printf ("%d ", tableau[i] ) ;
    printf("]\n");
    return ;
}

int main(int argv, char **argc){
    int rndm[lentab], trier[lentab], N;
    int premier[lentab];
    init(premier,lentab);
    eratosthene(premier,lentab);
    translate(premier, lentab);
    N=effacerzero(premier, lentab);
    afficher(premier, N);
    printf("la somme des nombres premier <= %d : %d\n", lentab, somtab(premier,N));
    randtable(rndm, lentab);
    afficher(rndm, lentab);
    tritab(rndm, trier, lentab);
    afficher(trier, lentab);
    return 0;
}
