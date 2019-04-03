#include <stdio.h>
#include <stdlib.h>

typedef struct sColor {
    unsigned char r,g,b;
} Color;

typedef struct sImage{
    int largeur;
    int hauteur;
    Color *pixels;
}Image;

Image newImage(int l, int h){
    Image new;
    int i, j, k;
    new.pixels=malloc(sizeof(Color)*h*l);
    new.largeur=l;
    new.hauteur=h;
    return new;
}

/* Apropos de stat:
    taille fichier stat[0]
    @1er pixel : stat[2]);
    taille de l'entete : stat[3]
    largeur image : stat[4]
    hauteur image : stat[5]
    nb plans : stat[35]
    nb bits/pixel : stat[36]
    type compression : stat[7]
    taille image (pixels) : stat[8]
    resolution horizontale : stat[9]
    resolution verticale : stat[10]
    nb de couleur dans la palette : stat[11]
*/

int * statImage(char *nomFic){
	FILE *im;
	int *stat;
	stat=(int*)malloc(sizeof(int)*37);
    im=fopen(nomFic,"r");
    fseek(im,2,SEEK_SET);
    fread(stat,4,35,im);
    fseek(im,26,SEEK_SET);
    fread(stat+35,2,1,im);
    fread(stat+36,2,1,im);
    printf("Taille fichier : %d\n", stat[0]);
    printf("Adresse 1er pixel : %d\n", stat[2]);
    printf("Taille de l'entete : %d\n", stat[3]);
    printf("Largeur image : %d\n", stat[4]);
    printf("Hauteur image : %d\n", stat[5]);
    printf("Nombre de plans : %d\n", stat[35]);
    printf("Nombre de Bits/pixel : %d\n", stat[36]);
    printf("Hauteur image : %d\n", stat[5]);
    printf("Type de compression : %d\n", stat[7]);
    printf("Taille image(pixels) : %d\n", stat[8]);
    return stat;
}


Image lireImageBMP(char *nomFic){
    FILE *im;
    int *entete, i, j, k;
    entete=statImage(nomFic);
    im=fopen(nomFic,"r");
    Image BMP=newImage(entete[4],entete[5]);
    fseek(im,entete[2],SEEK_SET);
    for(i=0; i<entete[5]; i++){
        for(j=0; j<entete[4]; j++){
            for(k=0; k<3; k++){
                fread(&BMP.data[i][j][k],1,1,im);
                //printf("Pixel(%d,%d) : [ %d %d %d ]\n", i, j, BMP.data[i][j][0], BMP.data[i][j][1],BMP.data[i][j][2]);
            }
        }
    }
    return BMP;
}

void saveImageBMP(Image im, char *nomFic){

}

void affiImage (char *nom) {
     char commande [100] ;
     sprintf(commande, "/usr/bin/eog %s &", nom) ;
     system(commande);
}

int main(int argc, char *argv[]){
    statImage("SONIC2.bmp");

	return 0;
}
