#include <stdio.h>
#include <stdlib.h>
#include "isotop.h"
#include <windows.h>


void AFFICHER_TAB (struct square **tab,int taille) //sous programme permettant de remplir un tableau
{

    int cptaffl,cptaffc; //compteur
    for (cptaffl=0; cptaffl<taille; cptaffl++) //Parcourir le tableau de haut en bas
    {
        for(cptaffc=0; cptaffc<taille; cptaffc++) //Parcourir le tableau de gauche à droite

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
    srand(time(NULL)); //Initialiser le générérateur d'aléatoire
        for (cptligne=0; cptligne<=(taille-1); cptligne++)//Boucle de remplissage du tableau par des 0
        {
            for (cptcolonne=0; cptcolonne<=(taille-1); cptcolonne++)
            {
                tab[cptligne][cptcolonne].valeur=0;
            }
        }
        //Premier remplissage aléatoire
        ligne=rand()%(taille); //Ligne aléatoire
        colonne=rand()%(taille);//Colonne aléatoire
        element=rand()%2;//Element aléatoire
        if (element==0)

        {
            tab[ligne][colonne].valeur=tab[ligne][colonne].valeur+2;//Remplir avec un atome d'Hydrogène
        }
        else tab[ligne][colonne].valeur=tab[ligne][colonne].valeur+4; //Remplir avec un atome d'hélium

}

void MVMT_GAUCHE (struct square **tab, int taille,int *casevide) //Mouvement gauche
{
    int cptligne,cptcolonne; //Compteur de lignes & colonnes
    int tampon; //Tampon de valeur
    int cpt; //Compteur
    int indic; //Indicateur du nombre d'élements qu'il reste à classer
    for(cptligne=0; cptligne<taille; cptligne++)//Parcourir le tableau de haut en bas
    {
        indic=0;
        for(cptcolonne=0; cptcolonne<taille; cptcolonne++) //Parcourir tableau de gauche à droite
        {
            if (tab[cptligne][cptcolonne].valeur!=0) //Contenu de la case différent de 0
            {
                indic++; //Compte le nombre de cases non vides
            }
        }
        tampon=indic;
        if (indic==0) //Si la ligne ne comporte que des 0
        {
            continue; // Passer à la ligne suivante
        }
        cptcolonne=0; //Initialisation
        while( cptcolonne<taille && indic>0) // Parcourir le tableau de gauche à droite tant qu'il reste des élements à classer
        {
            while(tab[cptligne][cptcolonne].valeur==0) //Si la case est un 0

            {
                for(cpt=(cptcolonne+1); cpt<taille; cpt++) //Décalage de toutes les cases vers la gauche.
                {
                    tab[cptligne][cpt-1]=tab[cptligne][cpt];

                }
                tab[cptligne][taille-1].valeur=0; // Remplir la dernière case par un 0.
                tab[cptligne][taille-1].decompte=NBRE_DECOMPTE; // Réinitialiser le décompte de la dernière case du tableau


            }
            cptcolonne++;
            indic--;

        }
        indic=tampon; //Réinitialisation du nomre d'élements à classer
        cptcolonne=0; //Initialisation
        while (cptcolonne<taille && indic>0) //Parcourir le tableau de gauche à droite tant que l'on est pas à la fin du tableau et qu'il reste des élements à trier
        {
            if(tab[cptligne][cptcolonne].valeur==16 || tab[cptligne][cptcolonne].valeur==64) //Si la case est un isotope instable
            {
                tab[cptligne][cptcolonne].decompte=(tab[cptligne][cptcolonne].decompte)-1; //Le décompte diminue d'un
            }
            if((cptcolonne+1)<taille && tab[cptligne][cptcolonne].valeur!=0 && tab[cptligne][cptcolonne].valeur==tab[cptligne][cptcolonne+1].valeur)//Si le nombre à droite est le même et est différent de 0
            {
                tab[cptligne][cptcolonne].valeur=(2*tab[cptligne][cptcolonne].valeur);//Fusion des deux (multiplication par deux)
                if(tab[cptligne][cptcolonne].valeur!=16 || tab[cptligne][cptcolonne].valeur!=64)  //Si l'élement n'est pas un isotope instable
                {
                    tab[cptligne][cptcolonne].decompte=NBRE_DECOMPTE; //Réinitialiser le décompte
                }
                tab[cptligne][cptcolonne+1].valeur=0;//Remplacement du deuxième nombre par une case vide
                tab[cptligne][cptcolonne+1].decompte=NBRE_DECOMPTE;
                *casevide=*casevide+1;//Compteur de cases vides

                for(cpt=(cptcolonne+2); cpt<taille; cpt++) //Décalage de toutes les cases vers la gauche.
                {
                    tab[cptligne][cpt-1]=tab[cptligne][cpt];

                }
                tab[cptligne][taille-1].valeur=0; // Remplir la dernière case par un 0.
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
                tab[cptligne][cptcolonne].decompte=NBRE_DECOMPTE;//Réinitialiser le décompte
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
    int indic; //Indicateur du nombre d'élements qu'il reste à classer
    for(cptligne=0; cptligne<taille; cptligne++)//Parcourir le tableau de haut en bas
    {
        indic=0;
        for(cptcolonne=0; cptcolonne<taille; cptcolonne++) //Parcourir tableau de gauche à droite
        {
            if (tab[cptligne][cptcolonne].valeur!=0) //Contenu de la case différent de 0
            {
                indic++; //Compte le nombre de cases non vides
            }
        }
        tampon=indic;
        if (indic==0) //Si la ligne ne comporte que des 0
        {
            continue; // Passer à la ligne suivante
        }
        cptcolonne=(taille-1); //Initialisation
        while(cptcolonne>=0 && indic>0)
        {
            while(tab[cptligne][cptcolonne].valeur==0)
            {
                for ((cpt=cptcolonne-1); cpt>=0; cpt--) //Décalage de toutes les cases vers la droite
                {
                    tab[cptligne][cpt+1]=tab[cptligne][cpt];
                }
                tab[cptligne][0].valeur=0; //Remplir la première case de la ligne par un 0
                tab[cptligne][0].decompte=NBRE_DECOMPTE; //Réinitialiser le décompte
            }
            cptcolonne--;
            indic--;

        }
        indic=tampon; //Réinitialisation de la valeur
        cptcolonne=(taille-1); //Initialisation de la boucle
        while (cptcolonne>=0 && indic>0) //Parcourir le tableau de droite à gauche tant que l'on est pas à la fin du tableau et qu'il reste des élements à trier
        {
            if(tab[cptligne][cptcolonne].valeur==16 || tab[cptligne][cptcolonne].valeur==64) //Si la case est un isotope instable
            {
                tab[cptligne][cptcolonne].decompte=(tab[cptligne][cptcolonne].decompte)-1; //Le décompte diminue d'un
            }
            if((cptcolonne-1)>=0 && tab[cptligne][cptcolonne].valeur!=0 && tab[cptligne][cptcolonne].valeur==tab[cptligne][cptcolonne-1].valeur) //Si le nombre à gauche est le même
            {
                tab[cptligne][cptcolonne].valeur=(2*tab[cptligne][cptcolonne].valeur); //Fusion des deux élements (multiplication par deux
                if(tab[cptligne][cptcolonne].valeur!=16 || tab[cptligne][cptcolonne].valeur!=64)  //Si l'élement n'est pas un isotope instable
                {
                    tab[cptligne][cptcolonne].decompte=NBRE_DECOMPTE; //Réinitialiser le décompte
                }
                tab[cptligne][cptcolonne-1].valeur=0;
                tab[cptligne][cptcolonne-1].decompte=NBRE_DECOMPTE;
                *casevide=*casevide+1; //Compteur de cases vides
                for ((cpt=cptcolonne-2); cpt>=0; cpt--) //Décalage de toutes les cases vers la droite
                {

                    tab[cptligne][cpt+1]=tab[cptligne][cpt];
                }
                tab[cptligne][0].valeur=0;  //Remplir la première case de la ligne par un 0
                tab[cptligne][0].decompte=NBRE_DECOMPTE; // Réinitialiser la première case de la ligne par un 0

            }
            cptcolonne--;
            indic=(indic-2);
        }
        for(cptcolonne=(taille-1);cptcolonne>=0;cptcolonne--)
        {
            if(tab[cptligne][cptcolonne].decompte==0) //Si l'isotope instable arrive en fin de vie
            {
                tab[cptligne][cptcolonne].valeur=0; //Faire disparaitre cet isotope
                tab[cptligne][cptcolonne].decompte=NBRE_DECOMPTE;//Réinitialiser le décompte
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
    int indic; //Indicateur du nombre d'élements qu'il reste à classer
    for(cptcolonne=0; cptcolonne<taille; cptcolonne++)//Parcourir le tableau de haut en bas
    {
        indic=0;
        for(cptligne=0; cptligne<taille; cptligne++) //Parcourir tableau de haut en bas
        {
            if (tab[cptligne][cptcolonne].valeur!=0) //Contenu de la case différent de 0
            {
                indic++; //Compte le nombre de cases non vides
            }
        }
        tampon=indic;
        if (indic==0) //Si la colonne ne comporte que des 0
        {
            continue; // Passer à la colonne suivante
        }
        cptligne=(taille-1); //Initialisation
        while(cptligne>=0 && indic>0)
        {
            while(tab[cptligne][cptcolonne].valeur==0)
            {
                for ((cpt=cptligne-1); cpt>=0; cpt--) //Décalage de toutes les cases vers le bas
                {
                    tab[cpt+1][cptcolonne]=tab[cpt][cptcolonne];
                }
                tab[0][cptcolonne].valeur=0; //Remplir la première case de la colonne par un 0
                 tab[0][cptcolonne].decompte=NBRE_DECOMPTE;
            }
            cptligne--;
            indic--;

        }
        indic=tampon; //Réinitialisation de la valeur
        cptligne=(taille-1); //Initialisation de la boucle
        while (cptligne>=0 && indic>0)//Parcourir le tableau de bas en haut tant que l'on est pas à la fin du tableau et qu'il reste des élements à trier
        {
            if(tab[cptligne][cptcolonne].valeur==16 || tab[cptligne][cptcolonne].valeur==64) //Si la case est un isotope instable
            {
                tab[cptligne][cptcolonne].decompte=(tab[cptligne][cptcolonne].decompte)-1; //Le décompte diminue d'un
            }
            if((cptligne-1)>=0 && tab[cptligne][cptcolonne].valeur!=0 && tab[cptligne][cptcolonne].valeur==tab[cptligne-1][cptcolonne].valeur) //Si le nombre au dessus est le même
            {
                tab[cptligne][cptcolonne].valeur=(2*tab[cptligne][cptcolonne].valeur); //Fusion des deux élements (multiplication par deux)
                if(tab[cptligne][cptcolonne].valeur!=16 || tab[cptligne][cptcolonne].valeur!=64)  //Si l'élement n'est pas un isotope instable
                {
                    tab[cptligne][cptcolonne].decompte=NBRE_DECOMPTE; //Réinitialiser le décompte
                }
                tab[cptligne-1][cptcolonne].valeur=0;
                tab[cptligne-1][cptcolonne].decompte=NBRE_DECOMPTE;
                *casevide=*casevide+1; //Compteur de cases vides
                for ((cpt=cptligne-2); cpt>=0; cpt--) //Décalage de toutes les cases supérieurs vers le bas
                {
                    tab[cpt+1][cptcolonne]=tab[cpt][cptcolonne];
                }
                tab[0][cptcolonne].valeur=0; //Remplir la première case de la ligne par un 0
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
                tab[cptligne][cptcolonne].decompte=NBRE_DECOMPTE;//Réinitialiser le décompte
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
    int indic; //Indicateur du nombre d'élements qu'il reste à classer
    for(cptcolonne=0; cptcolonne<taille; cptcolonne++)//Parcourir le tableau de haut en bas
    {
        indic=0;
        for(cptligne=0; cptligne<taille; cptligne++) //Parcourir tableau de haut en bas
        {
            if (tab[cptligne][cptcolonne].valeur!=0) //Contenu de la case différent de 0
            {
                indic++; //Compte le nombre de cases non vides
            }
        }
        tampon=indic;
        if (indic==0) //Si la colonne ne comporte que des 0
        {
            continue; // Passer à la colonne suivante
        }
        cptligne=(0); //Initialisation
        while(cptligne<=(taille-1) && indic>0)
        {
            while(tab[cptligne][cptcolonne].valeur==0)
            {
                for ((cpt=cptligne+1); cpt<=(taille-1); cpt++) //Décalage de toutes les cases vers le haut
                {
                    tab[cpt-1][cptcolonne]=tab[cpt][cptcolonne];
                }
                tab[taille-1][cptcolonne].valeur=0; //Remplir la première case de la colonne par un 0
                tab[taille-1][cptcolonne].decompte=NBRE_DECOMPTE; // Réinitialiser le décompte de la première cas de la colonne
            }
            cptligne++;
            indic--;

        }
        indic=tampon; //Réinitialisation de la valeur
        cptligne=0; //Initialisation de la boucle
        while (cptligne<=(taille-1) && indic>0) //Parcourir le tableau de tant que l'on est pas à la fin du tableau et qu'il reste des élements à trier
        {
            if(tab[cptligne][cptcolonne].valeur==16 || tab[cptligne][cptcolonne].valeur==64) //Si la case est un isotope instable
            {
                tab[cptligne][cptcolonne].decompte=(tab[cptligne][cptcolonne].decompte)-1; //Le décompte diminue d'un
            }
            if((cptligne+1)<=(taille-1) && tab[cptligne][cptcolonne].valeur!=0 && tab[cptligne][cptcolonne].valeur==tab[cptligne+1][cptcolonne].valeur) //Si le nombre du dessous est le même
            {
                tab[cptligne][cptcolonne].valeur=(2*tab[cptligne][cptcolonne].valeur); //Fusion des deux élements (multiplication par deux)
                if(tab[cptligne][cptcolonne].valeur!=16 || tab[cptligne][cptcolonne].valeur!=64)  //Si l'élement n'est pas un isotope instable
                {
                    tab[cptligne][cptcolonne].decompte=NBRE_DECOMPTE; //Réinitialiser le décompte
                }
                tab[cptligne+1][cptcolonne].valeur=0;
                tab[cptligne+1][cptcolonne].decompte=NBRE_DECOMPTE;
                *casevide=*casevide+1;  //Compteur de cases vides
                for ((cpt=cptligne+2); cpt<=(taille-1); cpt++) //Décalage de toutes les cases supérieurs vers le bas
                {
                    tab[cpt-1][cptcolonne]=tab[cpt][cptcolonne];
                }
                tab[taille-1][cptcolonne].valeur=0; //Remplir la première case de la ligne par un 0
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
                tab[cptligne][cptcolonne].decompte=NBRE_DECOMPTE;//Réinitialiser le décompte
                *casevide=(*casevide)+1;
            }

        }

    }
}

void POP_NBRE_ALEATOIRE(struct square**tab,int taille,int *casevide)
{
    int ligne, colonne,element;

    do //Remplissage aléatoire
    {
        ligne=rand()%(taille);
        colonne=rand()%(taille);
        element=rand()%2;
    }
    while (tab[ligne][colonne].valeur!=0); //Vérification case différente de 0.
    if (element==0)
    {
        tab[ligne][colonne].valeur=2;
    }
    else (tab[ligne][colonne].valeur=4);
    *casevide=*casevide-1;
    //Vérification case vide
}
void GAME_OVER(struct square**tab, int taille,int*indice) // Sous programme de vérificatin de fin de jeu
{
    int cptligne,cptcolonne;
    int indic ; //indice du numéro de la première colonne de démarrage
    *indice=1; //Initialisation de l'indice
    for(cptligne=0; cptligne<taille; cptligne++) //Parcourir les lignes du tableau
    {
        indic=cptligne%2;
        for(cptcolonne=0; cptcolonne<(taille-1); cptcolonne=cptcolonne+1) //Parcourir les colonnes du tableau
        {
            if(cptcolonne+1<taille && tab[cptligne][cptcolonne].valeur==tab[cptligne][cptcolonne+1].valeur) //Si la case visée peut être fusionnée avec la case de droite (avec vérification)
            {
                *indice=0 ; //Indice de "non fin de jeu"
                return; // sortir de la boucle
            }
            else if(cptligne+1<taille && tab[cptligne][cptcolonne].valeur==tab[cptligne+1][cptcolonne].valeur)//Si la case visée peut être fusionnée avec la case du dessous
            {
                *indice=0 ;
                return;
            }
            /*  else if(cptcolonne-1>=0 && tab[cptligne][cptcolonne].valeur==tab[cptligne][cptcolonne-1].valeur) //Si la case visée peut être fusionnée avec la case de gauche
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
            if(tab[cptligne][cptcolonne].valeur==massemax)//Si le nombre est égal à la masse max décidée au par avant
            {
                *indice2=1;
            }
        }
    }
}

void COULEUR (int texte,int fond)
{
    /*  15 blanc, 0 noir
    1 bleu foncé, 2 vert foncé, 3 turquoise foncé, 4 rouge foncé, 5 violet foncé, 6 kaki foncé, 7 gris clair,
    8 gris foncé, 9 bleu fluo, 10 vert fluo, 11 turquoise fluo, 12 rouge fluo, 13 violet fluo, 14 jaune  */
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,fond*16+texte);

}
void SOUND_END()
{
    int C; //Do
    int D; //Ré
    int E; //Mi
    int F; //Fa
    int time1; //Durée son
    C=261; //Fréquence Do
    F=350; //Fréquence Fa
    E=330; //Fréquence Mi
    D=294; //Fréquence Ré
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
    fichier=fopen(nomFichier2,"w");  //pour ouvrir un fichier en écriture
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
    fichier=fopen(nomFichier,"w");  //pour ouvrir un fichier en écriture
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

