/* Fallion Mariacher 02/11/2017
Le jeu du Bonneteaux */

#include <stdio.h>
#include <stdlib.h>
#define CARTES_NIV1 3// nbre de cartes des niveaux 1,2,3
#define CARTES_NIV2 4
#define CARTES_NIV3 5
#define CAVES_NIV1 150// montant des caves des niveaux 1,2,3
#define CAVES_NIV2 300
#define CAVES_NIV3 500
#include <time.h>
int main ()
{

    //INITIALISATION DES DONNEES

    int m; //la mise
    int cavej; //la cave du joueur
    int cavem; //la cave du maitre
    int v; //la vérif
    char D;// la carte Dame
    char R;// la carte Roi
    int cj;//  carte du joueur
    int n;// Le niveau
    int nc;// nombre de cartes
    int cm;// carte du maitre
    int cpt; //le compteur
    int gg;//le joueur a trouvé la bonne carte
    int tampon;
    int num1, num2;
    int i; // quequefois ca sert
    srand(time(NULL)); //init des generateurs de nb aleatoires

    do //le joueur choisit un niveau avec vérif
    {
        printf("choisissez votre niveau de jeu 1, 2, ou 3\n");
        scanf("%d",&n);
    }
    while(n<1 || n>3);
    if(n==1) //definir le nbr de cartes et la cave en fonction du niveau de jeu
    {
        nc=CARTES_NIV1;
        cavej=CAVES_NIV1;
        cavem=CAVES_NIV1;
    }
    else if(n==2)
    {
        nc=CARTES_NIV2;
        cavej=CAVES_NIV2;
        cavem=CAVES_NIV2;
    }
    else
    {
        nc=CARTES_NIV3;
        cavej=CAVES_NIV3;
        cavem=CAVES_NIV3;
    }
    printf("niveau: %d, nombrecarte: %d, cavej: %d, cavem: %d\n",n,nc,cavej,CAVES_NIV1);

//creer un tableau avec les cartes
    char tableau[CARTES_NIV3];
    //TRAITEMENT
    do //tant que les caves sont supérieurs à 0 faire
    {
        gg=0;
        tableau[0]='D';
        for (cpt=1; cpt<=nc-1; cpt++)
        {
            tableau[cpt]='R';
        }

//afficher le tableau
        printf("\n");
        for (cpt=0; cpt<nc; cpt++)
        {
            printf(" %c ",tableau[cpt]);
        }
//demander et lire la mise avec verif
        do
        {
            printf("\nchoisissez votre mise \n");
            scanf("%d", &m);
        }
        while(m<=0||m>cavej);
//retourner les cartes
        for (cpt=0; cpt<=nc-1; cpt++)
        {
            printf("[%d]X ",cpt);
        }
//mélanger les cartes
        for(cpt=0; cpt<10; cpt++)
        {
            num1=rand()%nc;
            num2=rand()%nc;
            tampon=tableau[num1];
            tableau[num1]=tableau[num2];
            tableau[num2]=tampon;
/*afficher le tableau
            printf("\n    cpt: %d",cpt);
            for (i=0; i<nc; i++)
            {
                printf(" %c ",tableau[i]);
            }*/

        }

//demander & lire la carte choisie
        do
        {
            printf("\ntrouvez la dame! \n");
            scanf("%d", &cpt);
        }
        while(cpt<0);
        printf("\n");
        for (i=0; i<nc; i++)
        {
            printf(" [%d]%c ",i,tableau[i]);
        }
        printf("\nVous avez choisi %d\n", cpt);
//si la carte choisie est celle que l'on doit trouver
        if(tableau[cpt]=='D')
        {
            gg=1;
            printf("vous avez trouve la dame!\n");
        }
        if(gg==1)
//alors la mise est doublée et on retire la mise au maitre du jeu
        {
            cavej=cavej+(2*m);
            cavem=cavem-(2*m);
            printf("la cave du joueur est %d, la cave du maitre du jeu est %d\n", cavej, cavem);
        }
//sinon elle est perdue et la mise est ajouté à la cave du maitre du jeu
        else
        {
            cavem=cavem+m;
            cavej=cavej-m;
            printf("la cave du joueur est %d, la cave du maitre du jeu est %d\n", cavej, cavem);
        }
//afficher le montant des caves
    }
    while(cavej>0 && cavem>0);

    //AFFICHAGE DES RESULTATS
    if(cavej>cavem)//designer le gagnant

    {
        printf("Vous avez gagné, le maitre du jeu est NUL !\n");
    }
    else
    {
        printf("Vous avez perdu, le maitre du jeu est FORT !\n");
    }
    //while(1);
    return 0;

}
