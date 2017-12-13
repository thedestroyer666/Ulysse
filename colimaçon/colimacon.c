/*Fortuna Pierre-Antoine
Mariacher Ulysse tableau colimaçon*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //INITIALISATION DES DONNEES
    int j; //compteur
    int i; //compteur
    int nbcol; //nombre de colonnes
    int nblig; //nombre de lignes
    int ligcour; //ligne courante
    int colcour; // colonne courante
    int caseligdepart; // ligne de la case de départ
    int casecoldepart; //colonne de la case de départ
    int nbplace; //nombre à placer dans la case courante



    //TRAITEMENT
// Demander le nombre de lignes (nblig) avec vérification
    do
    {
        printf("Rentrer le nombre de lignes desirees\n");
        scanf("%d",&nblig);
// Demander le nombre de colones (nbcol) avec vérification
        printf("Rentrer le nombre de colonnes desirees\n");
        scanf("%d",&nbcol);
    }
    while (nblig<0 || nbcol<0);
// Créer un tableau et remplir le tableau de 0
    int tab[nblig][nbcol];
    for(j=0; j<=nbcol-1; j++)
    {
        for(i=0; i<=nblig-1; i++)
        {
            tab[i][j]=0;
        }
    }
// Demander et lire les coordonnées de la case de départ
    do
    {
        printf("choisissez la case a partir de laquelle vous voulez commencer\n");
        scanf("%d",&ligcour);
        ligcour=ligcour-1;
        scanf("%d",&colcour);
        colcour=colcour-1;
    }
    while(ligcour<0 || colcour<0 || ligcour>nblig || colcour>nbcol);
// affecter la ligne de la case de départ à la ligne courante
// affecter la colonne de la case de départ à la colonne courante
    nbplace=1;
    // for(nbplace=1; nbplace<nblig*nbcol; nbplace++)
    {
        //affecter 2 au nombre à placer
        tab[ligcour][colcour]=nbplace;//mettre 1 dans la case courante
        nbplace=nbplace+1;
    }

    //tant que l'on peut continuer à remplir le tableau faire
    while(colcour<nbcol-1  && tab[ligcour][colcour+1]==0 || ligcour<nblig-1 && tab[ligcour+1][colcour]==0 || colcour>=0 && tab[ligcour][colcour-1]==0 || ligcour>=0 && tab[ligcour-1][colcour]==0)
    {
        //tant que la colonne courante <nbre de colonnes -1 et que la case de droite est vide
        while(colcour<nbcol-1  && tab[ligcour][colcour+1]==0)
        {
            colcour=colcour+1;       // faire ajouter 1 à la colonne courante
            tab[ligcour][colcour]=nbplace;  //mettre le nombre à placer dans la case courante
            nbplace=nbplace+1; //ajouter 1 au nombre à placer
        }
        //s'il y a une ligne en dessous et que la case est vide
        //ajouter 1 à la ligne courante

        while(ligcour<nblig-1 && tab[ligcour+1][colcour]==0)//tant que la ligne courante< nbre de ligne -1 et que la case du dessous est vide

        {
            ligcour=ligcour+1;// faire ajouter 1 à la ligne courante
            tab[ligcour][colcour]=nbplace;//mettre le nombre à placer dans la case courante
            nbplace=nbplace+1;//ajouter 1 au nombre à placer
        }

        //s'il y a une colonne à gauche et que la case est vide
        //retirer 1 à a colonne courante

        while(colcour>=0 && tab[ligcour][colcour-1]==0)//tant que la colonne courante > 0 et que la case de gauche est vide

        {
            colcour=colcour-1;
            tab[ligcour][colcour]=nbplace;
            nbplace=nbplace+1;

        }



        //s'il y a une ligne au dessus et que la case est vide
        //retirer 1 à la ligne courante

        //tant que la ligne courante > 0 et que la case du dessus est vide faire

        while(ligcour>=0 && tab[ligcour-1][colcour]==0)//tant que la colonne courante > 0 et que la case de gauche est vide

        {
            ligcour=ligcour-1;
            tab[ligcour][colcour]=nbplace;
            nbplace=nbplace+1;

        }

    }
//AFFICHAGE DES RESULTATS
//afficher le tableau
    printf("   ");
    for(j=0; j<=nbcol-1; j++)
    {
        printf(" %c ",j+'A');
    }
    printf("\n\n");
    for(i=0; i<=nblig-1; i++)
    {
        printf(" %d ",i+1);
        for(j=0; j<=nbcol-1; j++)
        {
            printf(" %d ",tab[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}
