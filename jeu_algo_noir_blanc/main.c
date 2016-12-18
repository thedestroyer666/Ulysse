#include <stdio.h>
#include <time.h> //initialiser la variable qui choisi le joueur qui commence a jouer
#include <stdlib.h>
#include <string.h>//longueure de la chaine
#include <ctype.h>// pour mettre les directions en majuscules

//Mairesse Lancelot
//Mariacher Ulysse
#define TAILLE 5 //la taille du tableau
#define NB_LET 10 //le nombres de lettres max d un prenom

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int tab[TAILLE][TAILLE]; //le plateau de jeu (pion blanc: 1/B pion noir:-1/N case vide:0/_ )

char translate(int i)
{
    switch(i)
    {
    case -1:
        return 'B';
    case 1:
        return 'N';
    default:
        return '_';
    }
}

void display()
{
    int col;
    int row;
    printf("\n  ");
    for(col=0; col<TAILLE; col++)
    {
        printf("%2d ", col);
    }
    printf("\n");
    printf("\n");
    for(row=0; row<TAILLE; row++)
    {
        printf("%2d ",row);
        for (col=0; col<TAILLE; col++)
        {
            printf("%c  ", translate(tab[row][col]));
        }
        printf("\n"); //passer a la ligne
        printf("\n");
    }
}




int main()
{
    int ligneVide, colonneVide; //les coordonnees de la case vide
    int nbrecoups; //le nombre de coups
    int joueurcourant; //le joueur qui doit jouer : 1 ou 2
    char prenom1 [NB_LET+1]; //le prenom du 1 joueur
    char prenom2 [NB_LET+1]; //le prenom du 2 joueur
    char choixpossible[5];
    int cpt_choixpossible;
    int pion;//la couleur du pion à placer
    int cptrow;//compteur de lignes
    int cptcol;//compeur de colonnes
    int i;
    int j;
    int chiffre; // chiffre tire au sort
    int ligne;// numéro de la ligne
    int colonne;
    char direction, junk;
    srand(time(NULL)); // initialiser le generateur aleatoire

    /*initialisation des donnees joueur */
    //creer un tableau
    //remplir le tableau

    //se placer sur la 1 ere case
    cptrow=0;
    cptcol=0;
    //affecter noir au pion à placer
    pion=1;
    //Tant que pas fin de ligne faire
    while  (cptcol<5)
    {
        cptrow=0;
        //tant que pas fin de colonne faire
        while (cptrow<5)
        {
            //remplir la case avec le pion à placer
            tab[cptrow][cptcol]=pion;
            //changer la couleur du pion à placer
            pion=pion*-1;
            //passer à la ligne suivante
            cptrow=cptrow+1;
        }
        // passer à la colonne suivante
        cptcol++;
    }


    //demander et lire les prenoms des joueurs
    printf("Prenoms?");
    scanf("%s",&prenom1);
    scanf("%s",&prenom2);
    //tirer au sort le joueur blanc
    joueurcourant=(rand()%2);//0 ou 1
    if (joueurcourant==0)
    {
        joueurcourant=-1;
    }


//numerotez les lignes et les colonnes
    display();




    //demander et lire les coordonnees de la case vide, avec verifs
    if (joueurcourant==-1)
        printf("%s vous etes BLANC, a vous de jouer\n",prenom1);
    else printf("%s vous etes NOIR, a vous de jouer\n",prenom2);

    printf("taper la ligne puis la colonne de la case vide "); //demander et lire les coordonnees de la case vide, avec verifs
    if (joueurcourant==-1)
    {
        do
        {
            scanf("%d",&ligneVide);
            scanf("%d",&colonneVide);


            if (tab[ligneVide][colonneVide]==-1)
            {
                printf("Choix impossible, choisir une autre case vide");
            }


        }
        while (tab[ligneVide][colonneVide]==-1);
    }
    if (joueurcourant==1)
    {
        do
        {
            scanf("%d",&ligneVide);
            scanf("%d",&colonneVide);

            if (tab[ligneVide][colonneVide]==1)
            {
                printf("Choix impossible, choisir une autre case vide");
            }
        }


        while (tab[ligneVide][colonneVide]==1);
    }

    printf("ligne[%d] puis la colonne[%d] de la case vide\n", ligneVide, colonneVide);
    ligneVide = MIN(ligneVide,TAILLE-1);
    ligneVide = MAX(ligneVide,0);
    colonneVide = MIN(colonneVide,TAILLE-1);
    colonneVide = MAX(colonneVide,0);
    printf("ligne[%d] puis la colonne[%d] de la case vide\n", ligneVide, colonneVide);
    tab[ligneVide][colonneVide] = 0;

    //vider les cases
    nbrecoups=0; //affecter 0 au nombre de coups

    //affecter le joueur blanc au joueur courant*/

    //Traitement


    //Tant que le jeu n est pas termine faire
    //afficher le tableau
    display();
    scanf("%c",&junk); // purge le buffer de scanf
    do
    {
        // regarde les case possible et propose les
        cpt_choixpossible=0;
        printf("Joueur courant [%d] (BLANC[-1], NOIR[1]), ligneVide[%d], colonneVide[%d]\n",joueurcourant, ligneVide, colonneVide);
        printf("  N tab[%d][%d]=%d/%c\n", ligneVide-1, colonneVide, tab[ligneVide-1][colonneVide], translate(tab[ligneVide-1][colonneVide]));
        printf("  E tab[%d][%d]=%d/%c\n", ligneVide, colonneVide+1, tab[ligneVide][colonneVide+1], translate(tab[ligneVide][colonneVide+1]));
        printf("  S tab[%d][%d]=%d/%c\n", ligneVide+1, colonneVide, tab[ligneVide+1][colonneVide], translate(tab[ligneVide+1][colonneVide]));
        printf("  O tab[%d][%d]=%d/%c\n", ligneVide, colonneVide-1, tab[ligneVide][colonneVide-1], translate(tab[ligneVide][colonneVide-1]));
        printf("choisir parmi les cases ");
        if((ligneVide>0)&&(tab[ligneVide-1][colonneVide]==joueurcourant))
        {
            printf("N[ord] ");
            choixpossible[cpt_choixpossible]='N';
            cpt_choixpossible++;
        }
        if((colonneVide<TAILLE-1)&&(tab[ligneVide][colonneVide+1]==joueurcourant))
        {
            printf("E[st] ");
            choixpossible[cpt_choixpossible]='E';
            cpt_choixpossible++;
        }
        if((ligneVide<TAILLE-1)&&(tab[ligneVide+1][colonneVide]==joueurcourant))
        {
            printf("S[ud] ");
            choixpossible[cpt_choixpossible]='S';
            cpt_choixpossible++;
        }
        if((colonneVide>0)&&(tab[ligneVide][colonneVide-1]==joueurcourant))
        {
            printf("O[uest] ");
            choixpossible[cpt_choixpossible]='O';
            cpt_choixpossible++;
        }

        choixpossible[cpt_choixpossible] = (char)0; // ajouter une fin de ligne
        printf(" - choix possible pour vous [%s]\n",choixpossible);
        if(strlen(choixpossible)==0)
        {
            printf("Vous avez perdu.\n");
        }
        else
        {
            do
            {
                fflush(stdin);
                scanf("%c",&direction);
                printf("direction [%c]\n", toupper(direction));
                if(strchr(choixpossible,toupper(direction))==NULL)
                {
                    printf("Choix impossible, reessayez.\n", direction);
                }
            }
            while(strchr(choixpossible,toupper(direction))==NULL);

            printf("Bon choix!\n");



            //demander a lire la case a deplacer, avec verfif

            switch(toupper(direction))//deplace la case vide
            {
            case 'N':
                if(ligneVide>0)
                {
                    tab[ligneVide][colonneVide] = tab[ligneVide-1][colonneVide];
                    tab[ligneVide-1][colonneVide] = 0;
                    ligneVide=ligneVide-1 ;
                }
                break;
            case 'E':
                if(colonneVide<TAILLE-1)
                {
                    tab[ligneVide][colonneVide] = tab[ligneVide][colonneVide+1];
                    tab[ligneVide][colonneVide+1] = 0;
                    colonneVide=colonneVide+1 ;
                }
                break;
            case 'S':
                if(ligneVide<TAILLE-1)
                {
                    tab[ligneVide][colonneVide] = tab[ligneVide+1][colonneVide];
                    tab[ligneVide+1][colonneVide] = 0;
                    ligneVide=ligneVide+1 ;
                }
                break;
            default:
                if(colonneVide>0)
                {
                    tab[ligneVide][colonneVide] = tab[ligneVide][colonneVide-1];
                    tab[ligneVide][colonneVide-1] = 0;
                    colonneVide=colonneVide-1 ;
                }
                break;
            }
            printf("Joueur courant [%d] (BLANC[1], NOIR[-1]), ligneVide[%d], colonneVide[%d]\n",joueurcourant, ligneVide, colonneVide);
            display();//affiche le tableau
            //deplacer le pion
            //ajouter 1 au nombre de coups
            nbrecoups++;
            //changer de joueur courant
            joueurcourant=(-1)*joueurcourant ;
            //verifier si le joueur peut jouer*/
        }


    }
    while(strlen(choixpossible)!=0);
    /*Affichage des resultats

        designer le vainqueur*/
}
