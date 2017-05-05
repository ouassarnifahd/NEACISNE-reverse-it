#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/** @file pile.c
*   @brief Definition des fonctions utiles pour gerer les piles.
*/
#include"../inc/pile.h"
#include"../inc/Elements/element.h"

PTPile TPile_Creer(int maxSize){
	PTPile pPile=malloc(sizeof(TPile));
	if(!pPile) return NULL;
	pPile->TailleMax=maxSize;
	pPile->NumElems=0;
	pPile->Table=(TElement*)malloc(pPile->TailleMax*sizeof(TElement));
	return pPile;
}

bool TPile_EstVide(const PTPile this){
	return (this->NumElems)?0:1;
}

int TPile_Taille(const PTPile this){
	return this->NumElems;
}

TElement TPile_Top(const PTPile this){
	if(TPile_EstVide(this))
		return (TElement)0;
	return this->Table[this->NumElems-1];
}

PTPile TPile_Empiler(const PTPile this, TElement newElt){
	PTPile uthis=this;
	if(TPile_EstVide(uthis)){
		uthis->Table[uthis->NumElems]=newElt;
		uthis->NumElems++;
		return uthis;
	}
	else {
		if(uthis->NumElems>=uthis->TailleMax){
			uthis->TailleMax=2*uthis->TailleMax*sizeof(TElement);
			uthis->Table=(TElement*)realloc(uthis->Table,uthis->TailleMax);
		}
		uthis->Table[uthis->NumElems]=newElt;
		uthis->NumElems++;
		return uthis;
	}
}

bool TPile_Depiler(const PTPile this, PTElement pElement){
	if(TPile_EstVide(this)) return 0;
	*pElement=this->Table[this->NumElems-1];
	this->Table[this->NumElems-1]=this->Table[this->NumElems];
	this->NumElems--;
	return 1;
}

void TPile_Effacer(const PTPile this){
	TElement tmp;
	while(TPile_Depiler(this,&tmp));
}

void TPile_Detruire(const PTPile this){
	TPile_Effacer(this);
	free(this);
}

void TPile_Afficher(const PTPile this){
	int i;
	printf(" Taille: %d\n",this->TailleMax);
	printf("Contenu: ");
	for(i=0; i<this->NumElems; i++){
		if(i==this->NumElems-1){
			TElement_Afficher(this->Table[i]);
		}
		else{
			TElement_Afficher(this->Table[i]);
			printf(" -> ");
		}
	}
	printf("\t(%d Elems)\n",this->NumElems);
}
