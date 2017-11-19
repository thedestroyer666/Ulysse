/* Mariacher Leistikow 8/11
  jeu du marathon */

#include <stdio.h>
#include <stdlib.h>
#include<time.h>


#define DISTANCE 42195 // distance totale � parcourir
#define NB_DES 5 // nombre initial de d�s
#define NB_TOURS 10// nombre de tours

int main()
{
//INITIALISATION DES DONNEES

    int dist; //initialiser la distance � parcourir
    int nbtours; // "" le nombres de tours
    int nbdes; // "" le nombre de d�s
    int cpt; //compteur
    int dist2; //distance parcourue en un tour
    //variable pour la v�rification des chiiffres
    int num;
    int verif;
    int reste;
    srand(time(NULL));
    dist=DISTANCE;
    nbdes=NB_DES;
    nbtours=NB_TOURS;

    printf("\n                         JEU DU MARATHON\n");

//TRAITEMENT

    do
    {
        // tant que  distance >0 et que le nombre de tours est inferieur au nb de tours a faire
        printf("\n        distance= %d\n        tours restants=%d\n", dist, nbtours); // afficher la distance qu'il reste a parcourir et le nb de tours
        int tab[nbdes];
        printf("voici les chiffres :\n");
        for(cpt=0; cpt<nbdes; cpt++) // tirer au sort les chiffres tableau avec 5 chiffres tir�s au sort
        {
            tab[cpt]=rand()%7;

            printf(" %d ",tab[cpt]);// afficher les chiffres
        }


        do // demander au joueur quel nombre il choisit ( 0 s il passe son tour) avec v�rification
        {

            printf("\nchoisissez votre nombre ou passez votre tour (0)\n");
            scanf("%d", &dist2);
            verif=1;//on initialise la v�rification
            num=dist2;
            do
            {
                reste=num%10;
                printf("0 %d\n",reste );
                for(cpt=0; cpt<nbdes; cpt++)
                {
                    printf("1 tab[%d](%d)==%d\n",cpt,tab[cpt],reste );
                    if(tab[cpt]==reste)
                    {
                        printf("2 tab[%d](%d)==%d\n",cpt,tab[cpt],reste );
                        break;
                    }

                }
                if (cpt==nbdes)
                {
                    printf("mauvais nombre\n");
                    //verif=0;
                }

            }
            while (verif==0 && num>0);

        }
        while (dist2<0 || dist2>dist);
        dist=dist-dist2;// retrancher le nombre a la distance a parcourir
        nbtours=nbtours-1;// ajouter 1 au nombre de tours
        if(dist>=10000)
        {
            nbdes=5;
        }
        else if(dist<10000)//si distance est < seuil (1000) alors retirer 1 au nb de d�s diviser le seuil par 10
        {
            nbdes=4;
        }
        else if(dist<1000)
        {
            nbdes=3;
        }
        else if (dist<100)
        {
            nbdes=2;
        }
        else
        {
            nbdes=1;
        }

        //AFFICHAGE DES RESULTATS
        // indiquer au joueur s il a perdu ou gagn�

    }
    while (dist>0 && nbtours>0 );
    if(dist==0)
    {
        printf("vous avez gagne, vous courez tres vite\n");
    }
    else
    {
        printf("vous etes nul, perdez du gras\n");
    }
    return 0;
}
