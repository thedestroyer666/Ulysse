#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<time.h>
#include "SousProgrammes.h"


int main()
{
    struct artiste *tabArtistes;
    struct producteur *tabProducteurs;
    struct projet *tabProjets;
    int nbArtistes=0;
    int nbProducteurs=0;
    int nbProjets=0;


    int a; //l'utilisateur a un compte ou pas
    int b; //l'utilisateur veut s'inscrire ou non
    int c; //l'utilisateur est un artiste ou un producteur
    int d; //Les projets que le visiteur veux voir
    COULEUR(0,7);
    printf("\n                           BIENVENUE SUR CENTZER  \n ",7);
    printf("\n                       Le label de musique participatif :) \n");
    a=666;
    b=666;
    c=666;
    d=666;
    while(a!=0 && a!=1)
    {
        printf("\n\n   Avez vous deja un compte ? 0: oui 1: non\n");
        scanf("%d",&a);
    }
    if(a==0)
    {

    }
    else if(a==1)
    {
        while(b!=0 && b!=1)
        {
            printf("\nVoulez-vous vous inscrire ? 0: Oui 1: Non\n");
            scanf("%d",&b);

        }
        if(b==0)
        {
            while(c!=0 && c!=1)
            {
                printf("\nEtes vous artiste ou producteur ? 0: Artiste 1: Producteur\n");//artiste ou producteur ?
                scanf("%d",&c);


            }
            if(c==0)//si artiste
            {
                printf("Quel nom d'artiste voulez-vous utiliser?\n");
                scanf("%s",&(tabArtistes[nbArtistes].nom));
                printf("Quelle est votre adresse mail ?\n");
                scanf("%s",&(tabArtistes[nbArtistes].adressemail));
                printf("Choisissez un mot de passe.\n");
                scanf("%s",&(tabArtistes[nbArtistes].mdp));
                nbProjets=0;//on initialise le nombre de projet à 0
                nbArtistes=nbArtistes+1;//on rajoute 1 au nombre d'artistes
            }


            if(c==1) //si producteur
            {
                printf("Quel nom de producteur voulez-vous utiliser?\n");
                scanf("%s",&(tabProducteurs[nbProducteurs].nom));
                printf("Quelle est votre adresse mail ?\n");
                scanf("%s",&(tabProducteurs[nbProducteurs].adressemail));
                printf("Choisissez un mot de passe.\n");
                scanf("%s",(&tabProducteurs[nbProducteurs].mdp));
                nbProducteurs=nbProducteurs+1;//on rajoute 1 au nombre de producteurs
            }
        }
        if(b==1)
        {
            while(d!=1 && d!=2 && d!=3 && d!=4)
            {
                printf("\nBienvenue sur la plateforme de recherche de projet. Quels projets voulez vous voir?\n 1:Les 5 derniers projets \n  2:Les projets les plus chers\n 3: Les projets les moins chers\n 4:Quitter");
                scanf("%d",&d);
            }
            if(d==1)
            {

            }
            else if(d==2)
            {

            }
            else if(d==3)
            {

            }
            else if(d==4)
            {

            }
        }
    }

    /*time_t t1;
    t1=time(NULL); //date et heure qu'il est
    printf("%s\n",ctime(&t1));
    time_t t2;
    t2=time(NULL);
    double tps_ecoule;
    tps_ecoule=difftime(t2,t1); //nbre de secondes écoulées
    printf("%f\n",tps_ecoule);*/

    return 0;
}


