#include <stdio.h>
#include <stdlib.h>
#include "tableauxdyn.h"

int main()
{
    int *tab;
    int taille=0;
    int nbre;
    int cpt;


     CHARGEMENT(&tab,&taille);
     if(tab==NULL){
     printf("Vous devez remplir le tableau vous-meme pour pouvoir l'afficher");
     REMPLIR_TABLEAU_DYN(&tab,&taille);}
     AFFICHER_TABLEAU_DYN(tab,taille);
    /*for(cpt=0; cpt<taille; cpt++) //Afficher le tableau
    {
        printf("%d\n",*(tab+cpt));
    }*/
    printf("combien de cases voulez-vous ajouter ?\n"); //demander le nombre de cases à ajouter au tableau
    scanf("%d",&nbre);

    //modifier la taille du tableau
    int *tab2;
    tab2=realloc(tab,(taille+nbre)*sizeof(int));
    if(tab2==NULL)
    {
        printf("Impossible de cr%cer le tableau \n",130); //Vérification de création du tableau
        exit(0);
    }
    for(cpt=taille; cpt<taille+nbre; cpt++)     //Remplir l'extension du tableau
    {
        printf("Quel est l'%clement %d du tableau?\n",130,cpt+1);
        scanf("%d",&*(tab2+cpt)); //ou "%d",&tab2[cpt]
        printf("\n");
    }
     AFFICHER_TABLEAU_DYN(tab2,taille+nbre); //Aller chercher le sous programme rangé en bibliothèque. (Affichage tableau)

SAUVEGARDE(tab2,taille+nbre);
    return 0;
}
