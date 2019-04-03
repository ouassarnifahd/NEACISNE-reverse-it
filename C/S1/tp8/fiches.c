#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sFiche {
    char nom[20];
    char prenom[20];
    int num[5];
} Fiche;

typedef struct sRep {
    Fiche **rep;
    int contacts;
} Repertoire;

Fiche * creerFiche(char *n, char *p, int *t){
    Fiche *new;
    new=(Fiche*)malloc(sizeof(Fiche));
    int i;
    for(i=0; i<20; i++){
        new->nom[i]=*(n+i);
        new->prenom[i]=*(p+i);
    }
    for(i=0; i<5; i++){
        new->num[i]=t[i];
    }
    return new;
}

int * getNum(char *tel){
    int *t;
    t=(int*)malloc(5*sizeof(int));
    sscanf(tel,"%d %d %d %d %d",&t[0],&t[1],&t[2],&t[3],&t[4]);
    return t;
}

int getsize(FILE *fd){
    int size, pos=ftell(fd);
    fseek(fd,0,SEEK_END);
    size=ftell(fd);
    fseek(fd,pos,SEEK_SET);
    return size;
}

int nbLigne(FILE *fd){
    int i=0, cpt=0, pos=ftell(fd), size=getsize(fd);
    char *chaine;
    chaine=(char*)malloc(size);
    fread(chaine,size,size,fd);
    fseek(fd,pos,SEEK_SET);
    while(chaine[i]!='\0'){
        if(chaine[i]=='\n'){
            cpt++;
        }
        i++;
    }
    return cpt;
}

void afficherFiche(Fiche f){
    printf("[ %s %s ", f.nom ,f.prenom);
    int i;
    for(i=0; i<5; i++){
        printf("%d ", f.num[i]);
    }
    printf("]\n");
}

Repertoire creerRep(int n){
    Repertoire new;
    new.contacts=n;
    new.rep=(Fiche**)malloc(sizeof(Fiche*)*n);
    int i;
    for(i=0; i<n; i++){
        new.rep[i]=(Fiche*)malloc(sizeof(Fiche));
        new.rep[i]=NULL;
    }
    return new;
}

void afficherRep(Repertoire r){
    int i;
    printf("Repertoire :\n");
    for(i=0; i<r.contacts; i++){
        if(r.rep[i]!=NULL){
            afficherFiche(*r.rep[i]);
        }
    }
}

void ajouterFiche(Repertoire r, Fiche *f ){
    int i=0;
    while(r.rep[i]!=NULL){
        i++;
    }
    if(i<=r.contacts){
        r.rep[i]=f;
    }
}

void supprimerFiche(Repertoire r, int id){
    if(id>0){
        r.rep[id]=NULL;
    }
}

int rechercherFiche(Repertoire r, char *nom, char *prenom){
    int i=0;
    while(r.rep[i]!=NULL){
        if(strcmp(r.rep[i]->nom, nom)==0 && strcmp(r.rep[i]->prenom, prenom)==0){
            return i;
        }
        i++;
    }
    return -1;
}

Repertoire lireRep(char *nomFic){
    FILE *fr;
    fr=fopen(nomFic,"r");
    Repertoire imp;
    imp.contacts=nbLigne(fr);
    int test, i=0;
    imp.rep=(Fiche**)malloc(sizeof(Fiche*)*imp.contacts);
    while(test!=-1){
        imp.rep[i]=(Fiche*)malloc(sizeof(Fiche));
        test=fscanf(fr,"%s %s %d %d %d %d %d\n", imp.rep[i]->nom, imp.rep[i]->prenom, &imp.rep[i]->num[0], &imp.rep[i]->num[1], &imp.rep[i]->num[2], &imp.rep[i]->num[3], &imp.rep[i]->num[4]);
        i++;
    }
    imp.rep[i-1]=NULL;
    fclose(fr);
    return imp;
}

void sauveRep(Repertoire r, char *nomFic){
    FILE *fw;
    fw=fopen(nomFic, "w");
    int i;
    for(i=0; i<r.contacts; i++){
        fprintf(fw, "%s %s %d %d %d %d %d\n", r.rep[i]->nom, r.rep[i]->prenom, r.rep[i]->num[0], r.rep[i]->num[1], r.rep[i]->num[2], r.rep[i]->num[3], r.rep[i]->num[4]);
    }
    fclose(fw);
}

int main(int argc, char *argv[]){
    Repertoire home=creerRep(10),test=lireRep("test.txt");
    ajouterFiche(home,creerFiche("Ouassarni","Fahd",getNum("07 37 80 13 04")));
    ajouterFiche(home,creerFiche("Ouassarni","Hamid",getNum("05 37 40 33 10")));
    int id=rechercherFiche(home,"Ouassarni","Hamid");
    afficherRep(test);
    afficherRep(home);
    sauveRep(home,"home.txt");
}
