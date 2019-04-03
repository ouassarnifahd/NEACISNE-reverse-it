#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float surfaceCorporelle (float p, float t){
    return 0.2*powf(p,0.4)*powf(t,0.7);
}

float metaBase (float sc, int a){
    if(10<=a && a<15)
        return 24*45*sc;
    if(15<=a && a<20)
        return 24*40*sc;
    if(20<=a && a<60)
        return 24*35*sc;
    if(60<=a)
        return 24*30*sc;
}

void metaBaseSexe (float *mb, int sexe, int alaitmt){
    *mb=*mb*(1-0.1*sexe)+alaitmt*600;
}

float metaActivite (int hSommeilRepos, int hActiviteSedentaire, int hActiviteLegere, int hSport){
    return 0*hSommeilRepos+50*hActiviteSedentaire+100*hActiviteLegere+200*hSport;
}

int main(void){
    float p, t, sc, mb, ma, rc;
    int a, sexe=0, alaitmt=0;
    char test1, test2;
    int hSommeilRepos, hActiviteSedentaire, hActiviteLegere, hSport;
    printf("Cher Utilisateur,\nCe programme calcul de facon simplifier, a travers quelques questions, votre ration calorifique :\n");
    printf("Quel est votre taille (en metre) ? ");
    scanf("%f", &t);
    printf("Quel est votre poids (en Kg) ? ");
    scanf("%f", &p);
    sc=surfaceCorporelle(p, t);
    printf("Quel est votre age ? ");
    scanf("%d", &a);
    mb=metaBase(sc, a);
    printf("Quel est votre sexe (H/F)? ");
    scanf("%s", &test1);
    if(test1=='F'){
        printf("Etes vous enceinte (ou allaitement) (O/N)? ");
        scanf("%s", &test2);
        sexe=1;
        if(test2=='O'){
            alaitmt=1;
        }
        metaBaseSexe(&mb, sexe, alaitmt);
    }
    while(hSommeilRepos+hActiviteSedentaire+hActiviteLegere+hSport!=24){
        printf("Rq: Veuillez bien vous assurer que vous avez au total 24h sinon le programme va vous redemander de les rentrer\n");
        printf("Combien d'heures etes vous au repos ? ");
        scanf("%d", &hSommeilRepos);
        printf("Combien d'heures etes vous assis(e) ? ");
        scanf("%d", &hActiviteSedentaire);
        printf("Combien d'heures faites vous une activite legere ? ");
        scanf("%d", &hActiviteLegere);
        printf("Combien d'heures faites vous du sport ? ");
        scanf("%d", &hSport);
    }
    ma=metaActivite(hSommeilRepos, hActiviteSedentaire, hActiviteLegere, hSport);
    rc=mb+ma;
    printf("Votre ration calorifique est %f Calories.\n", rc);
    return 0;
}
