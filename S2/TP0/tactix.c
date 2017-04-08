#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"tactix.h"

/**	@file tactix.c
*	@brief tactix functions
*/

Jeu creerJeu(void){
	Jeu nouveau;
	int i,j,k=0;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			nouveau.plateau[i][j]=k++;
		}
	}
	return nouveau;
}

void afficherJeu(Jeu j){
	int i;
	for(i=0; i<N ;i++){
		printf("%2d %2d %2d %2d\n", j.plateau[i][0],j.plateau[i][1], j.plateau[i][2], j.plateau[i][3]);
	}
}

bool coupPossible(Jeu game){
	int i, j, res=0;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(game.plateau[i][j] == VIDE){
				res++;
			}
		}
	}
	return (res==N*N)?0:1;
}

bool memeLigne(Jeu *pj, Coup cp){
	Position deb,fin;
	if(infosPosition(cp,&deb,&fin)){
		if(deb.y==fin.y){
			int min=deb.x,max=fin.x;
			minimumEtMaximum(min,max,&deb.x,&fin.x);
			int i=deb.x;
			while(pj->plateau[i][deb.y]!=VIDE && i<=fin.x){
				i++;
			}
			if(i-1==fin.x){
				for (i=deb.x; i<=fin.x; i++) {
					pj->plateau[i][deb.y]=VIDE;
				}
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

bool memeColonne(Jeu *pj, Coup cp){
	Position deb,fin;
	if(infosPosition(cp,&deb,&fin)){
		if(deb.x==fin.x){
			int min=deb.y,max=fin.y;
			minimumEtMaximum(min,max,&deb.y,&fin.y);
			int j=deb.y;
			while(pj->plateau[deb.x][j]!=VIDE && j<=fin.y){
				j++;
			}
			if(j-1==fin.y){
				for (j=deb.y; j<=fin.y; j++) {
					pj->plateau[deb.x][j]=VIDE;
				}
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

Position determinerPositionCase(int val){
	Position pos;
	int i;
	if(0 <= val && val <= N*N){
		for (i=0;i<N;i++){
			if(i <= val && val < (i+1)*N){
				pos.x=i;
				pos.y=val-i*N;
				return pos;
			}
		}
	}
	pos.x=-1;
	pos.y=-1;
	return pos;
}

bool infosPosition(Coup cp, Position *pdebut, Position *pfin){
	if (determinerPositionCase(cp.debut).x==-1 || determinerPositionCase(cp.fin).x==-1) {
		return 0;
	}
	else {
		*pdebut=determinerPositionCase(cp.debut);
		*pfin=determinerPositionCase(cp.fin);
		return 1;
	}
}

void minimumEtMaximum(int val1, int val2, int* minimum, int* maximum){
	if(val1<val2){
		*maximum=val2;
		*minimum=val1;
	}
	else {
		*maximum=val1;
		*minimum=val2;
	}
}

Jeu jouer(Jeu game, Joueur p){
	Coup cp;
	int cpt=0;
	do {
		if (cpt==0) {
			printf("Joueur %d > ",(int)p);
		}
		else{
			printf("Coup interdit... rejouer\n");
			afficherJeu(game);
			printf("Joueur %d > ",(int)p);
		}
		scanf("%d %d", &cp.debut, &cp.fin);
		cpt++;
	} while( !( memeLigne(&game,cp) || memeColonne(&game,cp) ) );
	return game;
}

bool tacTix(void){
	char choix;
	Joueur p=0;
	Jeu game=creerJeu();
	do{
		afficherJeu(game);
		game=jouer(game,p%2);
		p++;
	}while(coupPossible(game));
	printf("Joueur %d a gagne!\n", (p)%2);
	printf("rejouer(O/N)? ");
	scanf("%c\n", &choix);
	if(choix=='O' || choix=='o'){
		return 1;
	}
	else{
		return 0;
	}
}
