#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define lentab 30

//Eratosthene(EX1)
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

//TABLES(EX2)
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

//EX4
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

//EX5 MATRICE3x3
void saisir(int table[3][3]){
    int i;
    for(i=0; i<3; i++){
        printf("Donnez les valeurs de la ligne %d : ", i);
        scanf("%d %d %d", &table[i][0],&table[i][1],&table[i][2]);
    }
}

void transpose(int table[3][3]){
     int i;
    for(i=0; i<3; i++){
        printf("Voici la colonne %d : %d %d %d\n", i, table[0][i], table[1][i], table[2][i]);
     }
}

void afficher (int tableau[], int taille) {
    int i ;
    printf("tab=[ ");
    for (i = 0 ; i<taille ; i++ )
        printf ("%d ", tableau[i] ) ;
    printf("]\n");
    return ;
}

//EX6 caracteres
int nbEspaces(char *chaine){
    int i=0, cpt=0;
    while(chaine[i]!='\0'){
        if(chaine[i]==' '){
            cpt++;
        }
        i++;
    }
    return cpt;
}

int parseMots(char chaine[], char tabMots[20][15]){
    int i=0,j=0,k=0;
    while(j<nbEspaces(chaine)+1){
        if(chaine[i]==' ' || chaine[i]=='\0'){
            tabMots[j][k]='\0';
            j++;
            k=0;
        }
        else{
            tabMots[j][k]=chaine[i];
            k++;
        }
        i++;
    }
    return nbEspaces(chaine)+1;
}

int parenTest(char chaine[]){
    int i=0,test=0;
    while(chaine[i]!='\0'){
        if(chaine[i]=='('){
            test+=1;
        }
        if(chaine[i]==')'){
            test-=1;
        }
        i++;
    }
    return (test==0)?1:0;
}

int main(int argv, char **argc){
    char mots[20][15], chaine[100]="une fonction qui retourne le nombre d'espaces dans une chaine de caracteres";
    /*
    int matrice[3][3];
    int rndm[lentab], trier[lentab], N;
    int premier[lentab];
    init(premier,lentab);
    eratosthene(premier,lentab);
    translate(premier, lentab);
    afficher(premier, lentab);
    N=effacerzero(premier, lentab);
    afficher(premier, N);
    printf("la somme des nombres premier <= %d : %d\n", lentab, somtab(premier,N));
    randtable(rndm, lentab);
    afficher(rndm, lentab);
    tritab(rndm, trier, lentab);
    afficher(trier, lentab);
    printf("nbespaces=%d",nbEspaces(chaine));
    saisir(matrice);
    transpose(matrice);
    char ph1[100]="(cette) ((chaine est) ( ) (correctement) parenthesee ).";
    char ph2[100]="Cet)te (chaine) ne (l'est pas) .";
    char ph3[100]="(Celle-(ci (non)) () (plus) .";
    printf("ph1par = %d\n",parenTest(ph1));
    printf("ph2par = %d\n",parenTest(ph2));
    printf("ph3par = %d\n",parenTest(ph3));
    */
    int i;
    for(i=0;i<parseMots(chaine,mots);i++)
        printf("mot %d est : %s\n",i,mots[i]);
    return 0;
}
