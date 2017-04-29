#include <stdio.h>
#include <stdlib.h>
#include "isotop.h"
#include <windows.h>


void AFFICHER_TAB (struct square **tab,int taille) //sous programme permettant de remplir un tableau
{

    int cptaffl,cptaffc; //compteur
    for (cptaffl=0; cptaffl<taille; cptaffl++) //Parcourir le tableau de haut en bas
    {
        for(cptaffc=0; cptaffc<taille; cptaffc++) //Parcourir le tableau de gauche � droite

        {
            switch(tab[cptaffl][cptaffc].valeur)
            {
            case 0 :
                printf("   %c   ",254);
                break;
            case 2 :
                printf("   H   ");
                break;
            case 4 :
                printf("   He  ");
                break;
            case 8 :
                printf("   Be  ");
                break;
            case 32 :
                printf("   P   ");
                break;
            case 128 :
                printf("   Sn  ");
                break;
            case 256 :
                printf("   No  ");
                break;
            case 512 :
                printf("   Ra  ");
                break;
            case 1024 :
                printf("   Xe  ");
                break;
            }
            if(tab[cptaffl][cptaffc].valeur==16)
            {
                COULEUR(12,15);
                printf("   O   ");
                COULEUR(0,15);
            }
            else if(tab[cptaffl][cptaffc].valeur==64)
            {
                COULEUR(12,15);
                printf("   Ni  ");
                COULEUR(0,15);
            }


        }
        printf("\n\n");
    }
    printf("\n\n");
}

void REMPLISSAGE_TABLEAU_DEBUT(struct square **tab,int taille)
{
    int element;
    int cptligne,cptcolonne;
    int ligne,colonne;
    srand(time(NULL)); //Initialiser le g�n�r�rateur d'al�atoire
        for (cptligne=0; cptligne<=(taille-1); cptligne++)//Boucle de remplissage du tableau par des 0
        {
            for (cptcolonne=0; cptcolonne<=(taille-1); cptcolonne++)
            {
                tab[cptligne][cptcolonne].valeur=0;
            }
        }
        //Premier remplissage al�atoire
        ligne=rand()%(taille); //Ligne al�atoire
        colonne=rand()%(taille);//Colonne al�atoire
        element=rand()%2;//Element al�atoire
        if (element==0)

        {
            tab[ligne][colonne].valeur=tab[ligne][colonne].valeur+2;//Remplir avec un atome d'Hydrog�ne
        }
        else tab[ligne][colonne].valeur=tab[ligne][colonne].valeur+4; //Remplir avec un atome d'h�lium

}

void MVMT_GAUCHE (struct square **tab, int taille,int *casevide) //Mouvement gauche
{
    int cptligne,cptcolonne; //Compteur de lignes & colonnes
    int tampon; //Tampon de valeur
    int cpt; //Compteur
    int indic; //Indicateur du nombre d'�lements qu'il reste � classer
    for(cptligne=0; cptligne<taille; cptligne++)//Parcourir le tableau de haut en bas
    {
        indic=0;
        for(cptcolonne=0; cptcolonne<taille; cptcolonne++) //Parcourir tableau de gauche � droite
        {
            if (tab[cptligne][cptcolonne].valeur!=0) //Contenu de la case diff�rent de 0
            {
                indic++; //Compte le nombre de cases non vides
            }
        }
        tampon=indic;
        if (indic==0) //Si la ligne ne comporte que des 0
        {
            continue; // Passer � la ligne suivante
        }
        cptcolonne=0; //Initialisation
        while( cptcolonne<taille && indic>0) // Parcourir le tableau de gauche � droite tant qu'il reste des �lements � classer
        {
            while(tab[cptligne][cptcolonne].valeur==0) //Si la case est un 0

            {
                for(cpt=(cptcolonne+1); cpt<taille; cpt++) //D�calage de toutes les cases vers la gauche.
                {
                    tab[cptligne][cpt-1]=tab[cptligne][cpt];

                }
                tab[cptligne][taille-1].valeur=0; // Remplir la derni�re case par un 0.
                tab[cptligne][taille-1].decompte=NBRE_DECOMPTE; // R�initialiser le d�compte de la derni�re case du tableau


            }
            cptcolonne++;
            indic--;

        }
        indic=tampon; //R�initialisation du nomre d'�lements � classer
        cptcolonne=0; //Initialisation
        while (cptcolonne<taille && indic>0) //Parcourir le tableau de gauche � droite tant que l'on est pas � la fin du tableau et qu'il reste des �lements � trier
        {
            if(tab[cptligne][cptcolonne].valeur==16 || tab[cptligne][cptcolonne].valeur==64) //Si la case est un isotope instable
            {
                tab[cptligne][cptcolonne].decompte=(tab[cptligne][cptcolonne].decompte)-1; //Le d�compte diminue d'un
            }
            if((cptcolonne+1)<taille && tab[cptligne][cptcolonne].valeur!=0 && tab[cptligne][cptcolonne].valeur==tab[cptligne][cptcolonne+1].valeur)//Si le nombre � droite est le m�me et est diff�rent de 0
            {
                tab[cptligne][cptcolonne].valeur=(2*tab[cptligne][cptcolonne].valeur);//Fusion des deux (multiplication par deux)
                if(tab[cptligne][cptcolonne].valeur!=16 || tab[cptligne][cptcolonne].valeur!=64)  //Si l'�lement n'est pas un isotope instable
                {
                    tab[cptligne][cptcolonne].decompte=NBRE_DECOMPTE; //R�initialiser le d�compte
                }
                tab[cptligne][cptcolonne+1].valeur=0;//Remplacement du deuxi�me nombre par une case vide
                tab[cptligne][cptcolonne+1].decompte=NBRE_DECOMPTE;
                *casevide=*casevide+1;//Compteur de cases vides

                for(cpt=(cptcolonne+2); cpt<taille; cpt++) //D�calage de toutes les cases vers la gauche.
                {
                    tab[cptligne][cpt-1]=tab[cptligne][cpt];

                }
                tab[cptligne][taille-1].valeur=0; // Remplir la derni�re case par un 0.
                tab[cptligne][taille-1].decompte=NBRE_DECOMPTE;
            }
            cptcolonne++;

            indic=(indic-2);
        }

        for(cptcolonne=0;cptcolonne<taille;cptcolonne++)
        {
            if(tab[cptligne][cptcolonne].decompte==0) //Si l'isotope instable arrive en fin de vie
            {
                tab[cptligne][cptcolonne].valeur=0; //Faire disparaitre cet isotope
                tab[cptligne][cptcolonne].decompte=NBRE_DECOMPTE;//R�initialiser le d�compte
                *casevide=(*casevide)+1;
            }
        }
    }


}

void MVMT_DROITE(struct square **tab, int taille,int *casevide)
{
    int cptligne,cptcolonne; //Compteur de lignes & colonnes
    int tampon; //Tampon de valeur
    int cpt; //Compteur
    int indic; //Indicateur du nombre d'�lements qu'il reste � classer
    for(cptligne=0; cptligne<taille; cptligne++)//Parcourir le tableau de haut en bas
    {
        indic=0;
        for(cptcolonne=0; cptcolonne<taille; cptcolonne++) //Parcourir tableau de gauche � droite
        {
            if (tab[cptligne][cptcolonne].valeur!=0) //Contenu de la case diff�rent de 0
            {
                indic++; //Compte le nombre de cases non vides
            }
        }
        tampon=indic;
        if (indic==0) //Si la ligne ne comporte que des 0
        {
            continue; // Passer � la ligne suivante
        }
        cptcolonne=(taille-1); //Initialisation
        while(cptcolonne>=0 && indic>0)
        {
            while(tab[cptligne][cptcolonne].valeur==0)
            {
                for ((cpt=cptcolonne-1); cpt>=0; cpt--) //D�calage de toutes les cases vers la droite
                {
                    tab[cptligne][cpt+1]=tab[cptligne][cpt];
                }
                tab[cptligne][0].valeur=0; //Remplir la premi�re case de la ligne par un 0
                tab[cptligne][0].decompte=NBRE_DECOMPTE; //R�initialiser le d�compte
            }
            cptcolonne--;
            indic--;

        }
        indic=tampon; //R�initialisation de la valeur
        cptcolonne=(taille-1); //Initialisation de la boucle
        while (cptcolonne>=0 && indic>0) //Parcourir le tableau de droite � gauche tant que l'on est pas � la fin du tableau et qu'il reste des �lements � trier
        {
            if(tab[cptligne][cptcolonne].valeur==16 || tab[cptligne][cptcolonne].valeur==64) //Si la case est un isotope instable
            {
                tab[cptligne][cptcolonne].decompte=(tab[cptligne][cptcolonne].decompte)-1; //Le d�compte diminue d'un
            }
            if((cptcolonne-1)>=0 && tab[cptligne][cptcolonne].valeur!=0 && tab[cptligne][cptcolonne].valeur==tab[cptligne][cptcolonne-1].valeur) //Si le nombre � gauche est le m�me
            {
                tab[cptligne][cptcolonne].valeur=(2*tab[cptligne][cptcolonne].valeur); //Fusion des deux �lements (multiplication par deux
                if(tab[cptligne][cptcolonne].valeur!=16 || tab[cptligne][cptcolonne].valeur!=64)  //Si l'�lement n'est pas un isotope instable
                {
                    tab[cptligne][cptcolonne].decompte=NBRE_DECOMPTE; //R�initialiser le d�compte
                }
                tab[cptligne][cptcolonne-1].valeur=0;
                tab[cptligne][cptcolonne-1].decompte=NBRE_DECOMPTE;
                *casevide=*casevide+1; //Compteur de cases vides
                for ((cpt=cptcolonne-2); cpt>=0; cpt--) //D�calage de toutes les cases vers la droite
                {

                    tab[cptligne][cpt+1]=tab[cptligne][cpt];
                }
                tab[cptligne][0].valeur=0;  //Remplir la premi�re case de la ligne par un 0
                tab[cptligne][0].decompte=NBRE_DECOMPTE; // R�initialiser la premi�re case de la ligne par un 0

            }
            cptcolonne--;
            indic=(indic-2);
        }
        for(cptcolonne=(taille-1);cptcolonne>=0;cptcolonne--)
        {
            if(tab[cptligne][cptcolonne].decompte==0) //Si l'isotope instable arrive en fin de vie
            {
                tab[cptligne][cptcolonne].valeur=0; //Faire disparaitre cet isotope
                tab[cptligne][cptcolonne].decompte=NBRE_DECOMPTE;//R�initialiser le d�compte
                *casevide=(*casevide)+1;
            }

        }

    }



}
void MVMT_BAS(struct square **tab, int taille, int *casevide)
{
    int cptligne,cptcolonne; //Compteur de lignes & colonnes
    int tampon; //Tampon de valeur
    int cpt; //Compteur
    int indic; //Indicateur du nombre d'�lements qu'il reste � classer
    for(cptcolonne=0; cptcolonne<taille; cptcolonne++)//Parcourir le tableau de haut en bas
    {
        indic=0;
        for(cptligne=0; cptligne<taille; cptligne++) //Parcourir tableau de haut en bas
        {
            if (tab[cptligne][cptcolonne].valeur!=0) //Contenu de la case diff�rent de 0
            {
                indic++; //Compte le nombre de cases non vides
            }
        }
        tampon=indic;
        if (indic==0) //Si la colonne ne comporte que des 0
        {
            continue; // Passer � la colonne suivante
        }
        cptligne=(taille-1); //Initialisation
        while(cptligne>=0 && indic>0)
        {
            while(tab[cptligne][cptcolonne].valeur==0)
            {
                for ((cpt=cptligne-1); cpt>=0; cpt--) //D�calage de toutes les cases vers le bas
                {
                    tab[cpt+1][cptcolonne]=tab[cpt][cptcolonne];
                }
                tab[0][cptcolonne].valeur=0; //Remplir la premi�re case de la colonne par un 0
                 tab[0][cptcolonne].decompte=NBRE_DECOMPTE;
            }
            cptligne--;
            indic--;

        }
        indic=tampon; //R�initialisation de la valeur
        cptligne=(taille-1); //Initialisation de la boucle
        while (cptligne>=0 && indic>0)//Parcourir le tableau de bas en haut tant que l'on est pas � la fin du tableau et qu'il reste des �lements � trier
        {
            if(tab[cptligne][cptcolonne].valeur==16 || tab[cptligne][cptcolonne].valeur==64) //Si la case est un isotope instable
            {
                tab[cptligne][cptcolonne].decompte=(tab[cptligne][cptcolonne].decompte)-1; //Le d�compte diminue d'un
            }
            if((cptligne-1)>=0 && tab[cptligne][cptcolonne].valeur!=0 && tab[cptligne][cptcolonne].valeur==tab[cptligne-1][cptcolonne].valeur) //Si le nombre au dessus est le m�me
            {
                tab[cptligne][cptcolonne].valeur=(2*tab[cptligne][cptcolonne].valeur); //Fusion des deux �lements (multiplication par deux)
                if(tab[cptligne][cptcolonne].valeur!=16 || tab[cptligne][cptcolonne].valeur!=64)  //Si l'�lement n'est pas un isotope instable
                {
                    tab[cptligne][cptcolonne].decompte=NBRE_DECOMPTE; //R�initialiser le d�compte
                }
                tab[cptligne-1][cptcolonne].valeur=0;
                tab[cptligne-1][cptcolonne].decompte=NBRE_DECOMPTE;
                *casevide=*casevide+1; //Compteur de cases vides
                for ((cpt=cptligne-2); cpt>=0; cpt--) //D�calage de toutes les cases sup�rieurs vers le bas
                {
                    tab[cpt+1][cptcolonne]=tab[cpt][cptcolonne];
                }
                tab[0][cptcolonne].valeur=0; //Remplir la premi�re case de la ligne par un 0
                tab[0][cptcolonne].decompte=NBRE_DECOMPTE;
            }
            cptligne--;
            indic=(indic-2);

        }


        for(cptligne=(taille-1); cptligne>=0; cptligne--)
        {
            if(tab[cptligne][cptcolonne].decompte==0) //Si l'isotope instable arrive en fin de vie
            {
                tab[cptligne][cptcolonne].valeur=0; //Faire disparaitre cet isotope
                tab[cptligne][cptcolonne].decompte=NBRE_DECOMPTE;//R�initialiser le d�compte
                *casevide=(*casevide)+1;
            }

        }


    }

}
void MVMT_HAUT(struct square **tab, int taille, int *casevide)
{

    int cptligne,cptcolonne; //Compteur de lignes & colonnes
    int tampon; //Tampon de valeur
    int cpt; //Compteur
    int indic; //Indicateur du nombre d'�lements qu'il reste � classer
    for(cptcolonne=0; cptcolonne<taille; cptcolonne++)//Parcourir le tableau de haut en bas
    {
        indic=0;
        for(cptligne=0; cptligne<taille; cptligne++) //Parcourir tableau de haut en bas
        {
            if (tab[cptligne][cptcolonne].valeur!=0) //Contenu de la case diff�rent de 0
            {
                indic++; //Compte le nombre de cases non vides
            }
        }
        tampon=indic;
        if (indic==0) //Si la colonne ne comporte que des 0
        {
            continue; // Passer � la colonne suivante
        }
        cptligne=(0); //Initialisation
        while(cptligne<=(taille-1) && indic>0)
        {
            while(tab[cptligne][cptcolonne].valeur==0)
            {
                for ((cpt=cptligne+1); cpt<=(taille-1); cpt++) //D�calage de toutes les cases vers le haut
                {
                    tab[cpt-1][cptcolonne]=tab[cpt][cptcolonne];
                }
                tab[taille-1][cptcolonne].valeur=0; //Remplir la premi�re case de la colonne par un 0
                tab[taille-1][cptcolonne].decompte=NBRE_DECOMPTE; // R�initialiser le d�compte de la premi�re cas de la colonne
            }
            cptligne++;
            indic--;

        }
        indic=tampon; //R�initialisation de la valeur
        cptligne=0; //Initialisation de la boucle
        while (cptligne<=(taille-1) && indic>0) //Parcourir le tableau de tant que l'on est pas � la fin du tableau et qu'il reste des �lements � trier
        {
            if(tab[cptligne][cptcolonne].valeur==16 || tab[cptligne][cptcolonne].valeur==64) //Si la case est un isotope instable
            {
                tab[cptligne][cptcolonne].decompte=(tab[cptligne][cptcolonne].decompte)-1; //Le d�compte diminue d'un
            }
            if((cptligne+1)<=(taille-1) && tab[cptligne][cptcolonne].valeur!=0 && tab[cptligne][cptcolonne].valeur==tab[cptligne+1][cptcolonne].valeur) //Si le nombre du dessous est le m�me
            {
                tab[cptligne][cptcolonne].valeur=(2*tab[cptligne][cptcolonne].valeur); //Fusion des deux �lements (multiplication par deux)
                if(tab[cptligne][cptcolonne].valeur!=16 || tab[cptligne][cptcolonne].valeur!=64)  //Si l'�lement n'est pas un isotope instable
                {
                    tab[cptligne][cptcolonne].decompte=NBRE_DECOMPTE; //R�initialiser le d�compte
                }
                tab[cptligne+1][cptcolonne].valeur=0;
                tab[cptligne+1][cptcolonne].decompte=NBRE_DECOMPTE;
                *casevide=*casevide+1;  //Compteur de cases vides
                for ((cpt=cptligne+2); cpt<=(taille-1); cpt++) //D�calage de toutes les cases sup�rieurs vers le bas
                {
                    tab[cpt-1][cptcolonne]=tab[cpt][cptcolonne];
                }
                tab[taille-1][cptcolonne].valeur=0; //Remplir la premi�re case de la ligne par un 0
                tab[taille-1][cptcolonne].decompte=NBRE_DECOMPTE;
            }
            cptligne++;
            indic=(indic-2);



        }

        for(cptligne=0; cptligne<taille; cptligne++)
        {
            if(tab[cptligne][cptcolonne].decompte==0) //Si l'isotope instable arrive en fin de vie
            {
                tab[cptligne][cptcolonne].valeur=0; //Faire disparaitre cet isotope
                tab[cptligne][cptcolonne].decompte=NBRE_DECOMPTE;//R�initialiser le d�compte
                *casevide=(*casevide)+1;
            }

        }

    }
}

void POP_NBRE_ALEATOIRE(struct square**tab,int taille,int *casevide)
{
    int ligne, colonne,element;

    do //Remplissage al�atoire
    {
        ligne=rand()%(taille);
        colonne=rand()%(taille);
        element=rand()%2;
    }
    while (tab[ligne][colonne].valeur!=0); //V�rification case diff�rente de 0.
    if (element==0)
    {
        tab[ligne][colonne].valeur=2;
    }
    else (tab[ligne][colonne].valeur=4);
    *casevide=*casevide-1;
    //V�rification case vide
}
void GAME_OVER(struct square**tab, int taille,int*indice) // Sous programme de v�rificatin de fin de jeu
{
    int cptligne,cptcolonne;
    int indic ; //indice du num�ro de la premi�re colonne de d�marrage
    *indice=1; //Initialisation de l'indice
    for(cptligne=0; cptligne<taille; cptligne++) //Parcourir les lignes du tableau
    {
        indic=cptligne%2;
        for(cptcolonne=0; cptcolonne<(taille-1); cptcolonne=cptcolonne+1) //Parcourir les colonnes du tableau
        {
            if(cptcolonne+1<taille && tab[cptligne][cptcolonne].valeur==tab[cptligne][cptcolonne+1].valeur) //Si la case vis�e peut �tre fusionn�e avec la case de droite (avec v�rification)
            {
                *indice=0 ; //Indice de "non fin de jeu"
                return; // sortir de la boucle
            }
            else if(cptligne+1<taille && tab[cptligne][cptcolonne].valeur==tab[cptligne+1][cptcolonne].valeur)//Si la case vis�e peut �tre fusionn�e avec la case du dessous
            {
                *indice=0 ;
                return;
            }
            /*  else if(cptcolonne-1>=0 && tab[cptligne][cptcolonne].valeur==tab[cptligne][cptcolonne-1].valeur) //Si la case vis�e peut �tre fusionn�e avec la case de gauche
              {
                  *indice=0;
                  return;
              }*/
            /* if (indice==0)
             {
                 printf("GAME OVER, YOU SUCK");
             }*/
        }

    }
}
void YOU_WIN(struct square**tab, int taille, int massemax, int *indice2)//Condition de gain de la partie
{
    int cptligne,cptcolonne;

    for(cptligne=0; cptligne<taille; cptligne++) //Parcourir les lignes du tableau
    {
        for(cptcolonne=0; cptcolonne<taille; cptcolonne++) //Parcourir les colonnes du tableau
        {
            if(tab[cptligne][cptcolonne].valeur==massemax)//Si le nombre est �gal � la masse max d�cid�e au par avant
            {
                *indice2=1;
            }
        }
    }
}

void COULEUR (int texte,int fond)
{
    /*  15 blanc, 0 noir
    1 bleu fonc�, 2 vert fonc�, 3 turquoise fonc�, 4 rouge fonc�, 5 violet fonc�, 6 kaki fonc�, 7 gris clair,
    8 gris fonc�, 9 bleu fluo, 10 vert fluo, 11 turquoise fluo, 12 rouge fluo, 13 violet fluo, 14 jaune  */
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,fond*16+texte);

}
void SOUND_END()
{
    int C; //Do
    int D; //R�
    int E; //Mi
    int F; //Fa
    int time1; //Dur�e son
    C=261; //Fr�quence Do
    F=350; //Fr�quence Fa
    E=330; //Fr�quence Mi
    D=294; //Fr�quence R�
    time1=300; //0,3s
    Beep(C,time1);
    Beep(F,600);
    Beep(F,time1);
    Beep(F,time1);
    Beep(E,time1);
    Beep(D,time1);
    Beep(C,500);
}
void REGLES(char nomj[NBRE_LETTRE])
{
    system("CLS");
    printf(" REGLES DE ISOTOPIC 256\n\n");
    system("PAUSE");//Appuies sur une touche pour afficher la suite!
    system("CLS");
    COULEUR(15,0);
    printf("BUT DU JEU \n\n");
    COULEUR(0,15);
    printf("R%cussir %c atteindre un %cl%cment d\'une masse d%ctermin%ce au debut du jeu.\nPlus la masse %c atteindre est %clev%ce, plus la difficult%c est importante. \n\n",130,133,130,130,130,130,133,130,130,130);
    system("PAUSE");
    system("CLS");
    COULEUR(15,0);
    printf("DEBUT DE LA PARTIE \n\n");
    COULEUR(0,15);
    printf("Le jeu se d%croule sur une grille carr%ce. \nL\'utilisateur choisit la taille de la grille, et la masse %c atteindre pour gagner.\nDeux cases de la grille sont remplies al%catoirement par un 2 ou un 4, les autres cases sont vides. \n\n",130,130,133,130);
    system("PAUSE");
    system("CLS");
    COULEUR(15,0);
    printf("DEROULEMENT DU JEU \n\n");
    COULEUR(0,15);
    printf("Le joueur choisit ensuite un d%cplacement (gauche, droite, bas ou haut)\nTous les %cl%cments de la grille sont d%cplac%cs simultan%cment dans la direction choisie, aussi loin que possible. \nSi au cours du d%cplacement, 2 tuiles contenant le m%cme %cl%cment rentrent en contact, elles sont fusionn%ces en une tuile contenant un %cl%cment de masse doubl%ce. \nPar exemple, deux tuiles de 2 qui fusionnent donnent une tuile de 4. \n\nDe plus, %c chaque mouvement effectu%c, une nouvelle tuile contenant une masse de 2 ou 4 apparait de mani%cre al%catoire dans une case vide de la grille.\n\n",130,130,130,130,130,130,130,136,130,130,130,130,130,130,133,130,138,130);
    system("PAUSE");
    system("CLS");
    COULEUR(15,0);
    printf("ELEMENTS INSTABLES \n\n");
    COULEUR(0,15);
    printf("Certains %cl%cments chimiques sont instables, ils sont marqu%cs en rouge.\nCes %cl%cments ont une dur%ce de vie limit%ce, il faut les fusionner avant qu\'ils ne disparaissent de la grille.\n\n",130,130,130,130,130,130,130);
    system("PAUSE");
    system("CLS");
    COULEUR(15,0);
    printf("FIN DE PARTIE \n\n");
    COULEUR(0,15);
    printf("Si le score d%ctermin%c en d%cbut de partie est atteint, tu as gagn%c.\nSi tu ne peux plus te d%cplacer sur la grille, tu as perdu.\n\n %s es-tu enfin pr%ct pour ta premi%cre partie ?!\n\n",130,130,130,130,130,nomj,136,138);
    system("PAUSE");
    system("CLS");
}
void SAUVEGARDE_SCORE(int taille, int massemax, char nomj[NBRE_LETTRE])
{

    FILE *fichier;
    char nomFichier2[100]="Tableau des scores";
    strcat(nomFichier2,".txt"); //rajouter l'extension ".txt")
    fichier=fopen(nomFichier2,"w");  //pour ouvrir un fichier en �criture
    fprintf(fichier,"%d\n",taille);
    fprintf(fichier,"%d\n",massemax);
    fprintf(fichier,"%s\n",nomj);
    fclose(fichier); //fermer le fichier
}
void CHARGEMENT_SCORE(int *taille, int *massemax, char *nomj[NBRE_LETTRE])
{
    int tabscores[10][3]; //le tableau des scores
    int cpt; //Compteur
    FILE *fichier;
    char nomFichier2[100]="Tableau des scores";
    strcat(nomFichier2,".txt"); //rajouter l'extension du fichier
    fichier=fopen(nomFichier2,"r"); //pour ouvrir un fichier en lecture
    if(fichier==NULL)
    {
        printf("le fichier n'existe pas\n");

    }

    /*else {
            for(cpt=0;cpt<=10;cpt++)
            {
                if(tabscores[cpt][1]<massemax && tabscores[])
                {
                    tabscores[cpt]
                }
            }

    }*/

}
void CHARGEMENT_PARTIE(struct square ***tab,int*taille,int *massemax, int *casevide, char *nomj[NBRE_LETTRE])
{
    int cpt;
    int cpt2;
    FILE*fichier;
    char nomFichier [100];
    printf("Nom du fichier ?\n");
    scanf("%s",&nomFichier);
    strcat(nomFichier,".txt"); //rajouter l'extension du fichier
    fichier=fopen(nomFichier,"r"); //pour ouvrir un fichier en lecture
    if(fichier==NULL)
    {
        printf("le fichier n'existe pas\n");
        *tab=NULL;
    }
    else
    {
        fscanf(fichier,"%d",&*taille);
        *tab=malloc((*taille)*sizeof(int));
        for(cpt=0; cpt<taille; cpt++)
        {
            for(cpt2=0; cpt2<taille; cpt2++)
            {
                fscanf(fichier,"%d",&((*tab)[cpt][cpt2].valeur));
            }
        }
        fscanf(fichier,"%d\n",&*massemax);
        fscanf(fichier,"%d\n",&*casevide);
        fscanf(fichier,"%s\n",&*nomj);
        fclose(fichier);
    }
}


void SAUVEGARDE_PARTIE(struct square **tab, int taille, char nomj[NBRE_LETTRE], int massemax, int casevide)
{
    int cpt;
    int cpt2;
    FILE *fichier;
    char nomFichier[100];
    printf("Nom du fichier de sauvegarde ?\n");
    scanf("%s",&nomFichier);
    strcat(nomFichier,".txt"); //rajouter l'extension ".txt")
    fichier=fopen(nomFichier,"w");  //pour ouvrir un fichier en �criture
    fprintf(fichier,"%d\n",taille);
    fprintf(fichier,"%s\n",nomj);
    fprintf(fichier,"%d\n",massemax);
    fprintf(fichier,"%d\n",casevide);
    for(cpt=0; cpt<taille; cpt++);
    {
        for(cpt2=0; cpt2<taille; cpt2++)
        {
            fprintf(fichier,"%d\n",tab[cpt][cpt2].valeur);
        }

    }
    fclose(fichier); //fermer le fichier
}

