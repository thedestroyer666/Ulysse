#include <stdio.h>
#include <stdlib.h>

#define LETTRE 3 //Nombre de lettre d'un �lement

#include "isotop.h"
#include <ctype.h>
/* AVANCEE
-mail de la prof , une correction non faite
-est il possible de v�rifier que la valeur rentr�e est un entier et non une chaine de caract�re?
-pouvoir sauvegarder une partie et la reprendre ult�rieurement (id�alement pouvoir en sauvegarder plusieurs: OBLIGATOIRE
- la disparition des �l�metnzs instables ne fonctionne pas
- la possibilit� de relancer la partie ne contionne pas
-le WIN fonctionne, le game over non

/*Id�es a coder :

-Clignottements rouge lorsque qu'il ne reste plus aucune case de d�placement
-Musique de victoire
-Tableau des meilleurs scores (palmar�s)
-Fichier texte sur les r�gles
-Rendre plus clair les boutons (exemple choix OUI NON pour les r�gles, id�e: mettre 1 et 2 plus �loign�s des choix et les mettres en blanc sur fond noir)

*/

//char nomj[NBRE_LETTRE];//Nom



/*
void AFFICHER_TAB (struct square **tab,int taille) ; //Sous programme d'affichage du tableau
void POP_NBRE_ALEATOIRE(struct square**tab,int taille,int *casevide); //Sous programme d'apparitition al�atoire d'un nouvel �l�ment
void GAME_OVER(struct square**tab,int taille,int*indice); //Condition de fin de partie
void YOU_WIN(struct square**tab, int taille, int massemax, int *indice2);//Condition de gain de la partie
void COULEUR (int texte,int fond); //Sous programme d'affichage de couleurs
void SOUND_END(); //Musique de game over
void REGLES(char nomj[NBRE_LETTRE]); //Affichage des r�gles du jeu
void MVMT_DROITE (struct square **tab, int taille, int *casevide); //D�placement droite
void MVMT_BAS (struct square **tab, int taille, int *casevide); //D�placement bas
void MVMT_HAUT(struct square **tab, int taille, int *casevide); // D�placement haut
void MVMT_GAUCHE (struct square **tab, int taille, int *casevide); //D�placement gauche
void SAUVEGARDE(struct square **tab,  int taille, int massemax, int casevide);
void CHARGEMENT(struct square **tab,int massemax, int casevide);
*/
int main()
{

    /*char nomj[NBRE_LETTRE];//Nom du joueur
    int regle;//affichage r�gles
    int taille; //Taille du tableau


    int ligne;//ligne
    int colonne;//colonne tableau
    int element;
    int cptligne; //Compteur ligne de remplissage du tableau
    int cptcolonne; //Compteur colonne de remplissage du tableau
    int cptaffc; //compteur d'affichage colonne tableau
    int cptaffl; //compteur d'affichage ligne tableau
    int massemax; //Score que le joueur souhaite atteindre
    int casevide;//Compteur de cases vides
    int indice; //Indice de possibilit� de jouer
    int indice2; //Inidice de gain de la partie
    int i; //Compteur
    int direction; //Sens de d�placement des �lements
    int fin; //Lorsque le jeu est fini
    int keepplay; // rejouer ou s'arr�ter

    int change; //changer masse max
    //int indic;
    int tamp;
    int coups; //compteur de coups jou�s
    struct square **tab; //Tableau de jeu*/
    keepplay=0;



    //Initialistaion
    printf("Bienvenue sur Isotopic 256, quel est ton nom ? \n"); //Demander et lire le nom du joueur
    scanf("%s",&nomj);
    system("CLS");
    regle=0;
    printf("Bonjour %s, souhaites tu avoir un rappel des r%cgles du jeu avant \nde d%cbuter une partie?\n",&nomj,138,130);
    COULEUR(4,15);
    while(regle!=2 && regle!=1)
    {
        printf("1. OUI \n2. NON \n");
        scanf("%d",&regle);
        if (regle!=2 && regle!=1)
        {
            printf("Erreur, choix non disponible \n");
        }
    }


    if (regle==1)
    {
        REGLES(nomj);

    }
    printf("Sur quelle taille de grille souhaites tu jouer (grille carr%ce)? \n",130);
    scanf("%d",&taille);
    while (taille<3||taille>12)
    {
        printf("Erreur,la taille minimum est de 3 et celle maximum de 12 \n Saisis une autre taille. \n");
        scanf("%d",&taille);//Demander et lire la taille de la grille
    }


    indiceloose=0; //Indice de conditions fin de jeu (cas de perte)
    indicewin=0; // Indice de conditions de fin de jeu (cas de victoire)
    coups=0; //Initialisation du compteur de coups

    //D�finir la taille du tableau
    tab=malloc(taille*sizeof(struct square*)); //Cr�er un tableau dynamique
    for (i=0; i<taille; i++)
    {
        tab[i]=malloc(taille*sizeof(struct square));
    }


    printf("Quel score souhaites tu atteindre ?\n");
    COULEUR(4,15);
    printf("1. 32\n2. 64\n3. 128\n4. 256\n5. 512\n6. 1024\n"); //Score vis�
    COULEUR(0,15);
    scanf("%d",&massemax);
    while (massemax<1||massemax>6)
    {
        printf("Le score demand%c n'existe pas.\nQuel score souhaites tu atteindre ?\n",130);
        scanf("%d",&massemax);
    }
    switch(massemax) //Redonner la bonne valeur � la variable massemax
    {
    case 1 :
        massemax=32;
        break;
    case 2 :
        massemax=64;
        break;
    case 3 :
        massemax=128;
        break;
    case 4 :
        massemax=256;
        break;
    case 5 :
        massemax=512;
        break;
    case 6 :
        massemax=1024;
        break;
    }

    while (keepplay==0)

    {
        REMPLISSAGE_TABLEAU_DEBUT(tab,taille); //SP de remplissage par des 0 et apparition d'un premier �lement al�atoirement
        POP_NBRE_ALEATOIRE(tab,taille,&casevide); //SP d'apparition d'un nombre al�atoire
        casevide=(taille*taille)-2; //Nombre initial de cases vides sur la grille

        while(indiceloose!=1 && indicewin!=1) //Tant qu'il reste des possibilit�s de jeu
        {
            if(casevide==0) //Si il n'y a plus de cases disponibles
            {
                COULEUR(15,4);
                AFFICHER_TAB(tab,taille); //SP d'affichage tableau
                COULEUR(0,15);
            }
            else
            {
                AFFICHER_TAB(tab,taille);   //SP D'affichage tableau
            }
            printf("Cases vides : %d\n",casevide); //Affichage du nombre de cases vides restantes
            printf("Coups jou%cs :%d\n",130,coups); //Affichage du nombre de coups jou�s
            printf("2.H  4.He  8.Be  16.0  32.P  64.Ni  128.Sn  256.No  512.Ra  1024.Xe"); //Rappel des valeurs

            COULEUR(15,0);
            printf("\n\n HAUT:8 BAS:2 DROITE:6 GAUCHE:4\n"); //Quelle direction voulue
            COULEUR(0,15);
            scanf("%d",&direction); //Incr�ment directions
            while(direction!=2 && direction!=4 && direction!=6 && direction!=8) //V�rification de validit� de la direction
            {
                COULEUR(15,0);
                printf("Erreur de direction\n");
                COULEUR(4,15);
                printf("HAUT:8 \nBAS:2 \nDROITE:6 \nGAUCHE:4 ");
                scanf("%d",&direction);
                COULEUR(0,15);
            }
            printf("\n\n");
            if(direction==8) //Haut
            {
                MVMT_HAUT(tab,taille,&casevide); //SP de d�placement
            }
            else if(direction==4) //Gauche
            {
                MVMT_GAUCHE(tab,taille,&casevide); //SP de d�placement

            }

            else if (direction==6) //Droite
            {
                MVMT_DROITE(tab,taille,&casevide); //SP de d�placement

            }
            else if (direction==2) //Bas
            {
                MVMT_BAS(tab,taille,&casevide); //SP de d�placement

            }
            DUREE_DE_VIE(tab,taille,&casevide);

            coups++; //Nombre de coups jou�s

            if (coups>=10) //Impossible d'obtenir le score vis� avant 10 coups
            {
                YOU_WIN(tab,taille,massemax,&indicewin); //SP de v�rification du plus grand �l�ment obtenu dans le tableau
            }

            if (casevide!=0 && indicewin!=1) //indicewin vaut 1 si le score vis� est atteint
            {
                POP_NBRE_ALEATOIRE(tab,taille,&casevide); //SP d'apparition d'un nombre al�atoire
            }
            else if (casevide==0) //plus de case vide
            {
                GAME_OVER(tab,taille,&indiceloose); //V�rifier si il reste des possibilit�s de jouer
            }


        }






        if(indicewin==1) //Lorsque la partie est gagn�e
        {
            system("CLS");
            AFFICHER_TAB(tab,taille);
            COULEUR(4,8);
            printf("YOU WIN BRO\n");
            //Son de fin
            system("PAUSE");
            system("CLS");
            printf("Encore une partie?\n");
            printf("0.OUI\n1.NON\n");
            scanf("%d",&keepplay);
            while(keepplay!=0 && keepplay!=1) //V�rfification de saisie
            {
                printf("Erreur dans la saisie\n0=OUI    1=NON");
                scanf("%d",&keepplay);
            }
            if (keepplay==0)
            {
                printf("Besoin d'un objectif plus dur?\n");
                printf("0.OUI\n1.NON\n");
                scanf("%d",&change);
                while(change!=0 && change!=1)//V�rfification de saisie
                {
                    printf("Erreur dans la saisie\n0=OUI      1=NON");
                    scanf("%d",&change);
                }
                if (change==0)
                {
                    massemax=massemax*2;

                }
                printf("Le nouveau score %c atteindre est %d\n ",133,massemax);
                printf("Si tu en veux un autre, appuies sur 0, sinon, saisis un autre nombre\n");
                scanf("%d",&change);
                if(change==0)
                {
                    printf("Quel nouveau score vises tu ?\n");
                    scanf("%d",&massemax);
                }

            }
            else if(keepplay==1)
            {
                printf("Merci d'avoir jou� %c Isotopic 256,%c bient%ct\n",133,133,147);
                //sleep(5000);
            }
        }

        if(indiceloose==1) //Lorsque la partie est perdue
        {
            system("CLS");
            AFFICHER_TAB(tab,taille);
            COULEUR(4,8);
            printf("GAME OVER\nRETRY\n");
            SOUND_END(); //SP de musique de fin
            system("PAUSE");
            system("CLS");
            COULEUR(0,15);
            printf("Encore une partie?\n");
            COULEUR(4,15);
            printf("0.OUI\n1.NON\n");
            COULEUR(0,15);
            scanf("%d",&keepplay);
            while(keepplay!=0 && keepplay!=1)
            {
                printf("0=OUI    1=NON");
                scanf("%d",&keepplay);
            }
            if (keepplay==0)
            {
                printf("Besoin d'un objectif plus faible?\n");
                printf("0.OUI\n 1.NON\n");
                scanf("%d",&change);
                while(change!=0 && change!=1)
                {
                    printf("0=OUI      1=NON");
                    scanf("%d",&change);
                }
                if (change==0)
                {
                    massemax=massemax/2;

                }
                printf("Le nouveau score %c atteindre est %d\n",133,massemax);

            }
            else if (keepplay==1)
            {
                printf("Merci d'avoir jou� %c Isotopic 256,%c bient%ct\n",133,133,147);
                _sleep(5000);
            }

        }



    }


    return 0;
}



