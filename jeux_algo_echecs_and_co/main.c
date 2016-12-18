/*MARIACHER Ulysse
MAIRESSE Lancelot
FA1
TP jeux et groupes
15/12/2016*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NB_LETTRES 30 //nombre maximum de lettre dans nom
#define NB_JEUX 5 // nombre max de jeux proposés
struct Jeu   //infos sur le jeu
{
    char nom[NB_LETTRES+1]; //nom du jeu
    int nbreMin, nbreMax; // nbre min et nbre max de joueurs
    int cptParticipants; //compteur de participants inscrits
    int cptGroupes; //compteur de groupes formés
};
struct Participants   // infos sur les participants
{
    char nomP[NB_LETTRES+1]; // nom du participant
    char nomJ[NB_LETTRES+1]; // nom du jeu
    int groupe; // numéro  du groupe
};

int main()
{
    int numero; //numero du jeu
    struct Jeu tabJeux[NB_JEUX]=
    {
        {"Barbu",3,6,0,1},{"Belotte",4,4,0,1}, {"Tarot",4,5,0,1}, {"Echecs",2,2,0,1}, {"Magicthegatering",2,4,0,1}
    }; //le tableau contenant les jeux proposés
    int nbreParticipants; // compteur nombre participant

    //demander et lire le nbre de participants, avec verification
    do
    {
        nbreParticipants=1;
        printf("nombre de participants? \n");
        scanf("%d",&nbreParticipants);
        if (nbreParticipants<1) //verification nombre de participants
        {
            printf("erreur, retapez le nombre de participants \n");
        }
    }
    while (nbreParticipants<1);
    struct Participants tabParticipants[nbreParticipants]; //le tableau contenant les participants
//afficher le tableau des jeux (en numérotant les cases)
    int cptJeu; //compteur jeu
    for (cptJeu=0; cptJeu<NB_JEUX; cptJeu++ ) //affichage tableau de jeu
    {
        printf(" Jeu[%d] %s \n",cptJeu, tabJeux[cptJeu].nom);
    }

//remplir le tableau des participants (nom du joueur et numéro du jeu) et affecter un numéro de groupe
    int cptPart; //compteur boucle remplissage tableau
    int cptParticipants=0; //cptParticipants
    for (cptPart=0; cptPart<nbreParticipants; cptPart++ ) //lancement boucle
    {
        printf("nom d'un participant "); // demander nom des participants
        scanf("%s",&(tabParticipants[cptPart].nomP)); //lire
        //demander numero jeu, avec verification
        do
        {
            printf("numero du jeu? \n"); //demander numéro du jeu
            scanf("%d",&numero); //lire

            if (numero<0 || numero>=NB_JEUX) //verification
            {
                printf("Erreur, Choisir un numero dans la liste \n");
            }
            tabJeux[numero].cptParticipants++; //On ajoute 1 au nombre de participants

        }
        while (numero<0 || numero>=NB_JEUX); //pour chaque jeu
        strcpy(tabParticipants[cptPart].nomJ, tabJeux[numero].nom); //transposer nom du jeu dans l'autre structure
        if (tabJeux[numero].cptParticipants>tabJeux[numero].nbreMax) //compter le nombre de groupe
        {
            (tabJeux[numero].cptGroupes)++; //rajouter un au nombre de groupe
            tabJeux[numero].cptParticipants=1;// reinitialiser nombre de partipants pour prochain groupe
        }
        printf(" %s vous allez dans groupe %d \n",(tabParticipants[cptPart].nomP),(tabJeux[numero].cptGroupes)); //informer sur le groupe de jeu
        tabParticipants[cptPart].groupe = tabJeux[numero].cptGroupes; //affecte le numero du groupe dans la structure Participant (et sa variable adaptée)
    }
    for (cptPart=0; cptPart<nbreParticipants; cptPart++ ) //pour chaque participant
    {
        printf(" Participant[%d] %s joue a %s \n \n",cptPart, tabParticipants[cptPart].nomP, tabParticipants[cptPart].nomJ); //récapituler le jeu attribué
    }

//trier le tableau des participants
// tri bulle
    int indAsc, indDesc; //indices de parcours ascendant et descendant
    struct Participants tampon; //tampon


//Tant qu'il reste des éléments à trier faire
    for(indAsc=0; indAsc<nbreParticipants-1; indAsc++)
    {
        //Se placer sur la première case du tableau
        //Tant que l'on a pas atteint la partie déjà triée faire
        for(indDesc=nbreParticipants-1; indDesc>=indAsc+1; indDesc--) //lancement du tri bulle
        {
            //permuter toute partie d'éléments consécutifs non ordonnées
            if(strcmp(tabParticipants[indDesc].nomJ, tabParticipants[indDesc-1].nomJ)<0) //lancement tri alphabetique par rapport au nom du jeu
            {
                tampon =tabParticipants[indDesc]; //permutations structure à l'aide de la structure tampon
                tabParticipants[indDesc]= tabParticipants[indDesc-1];
                tabParticipants[indDesc-1]= tampon;
            }
            else if (strcmp(tabParticipants[indDesc].nomJ, tabParticipants[indDesc-1].nomJ)==0
                     && tabParticipants[indDesc].groupe<tabParticipants[indDesc-1].groupe) //lancement tri par rapport au groupe
            {
                tampon =tabParticipants[indDesc];  //permutations structure à l'aide de la structure tampon
                tabParticipants[indDesc]= tabParticipants[indDesc-1];
                tabParticipants[indDesc-1]= tampon;
            }
            else   if (strcmp(tabParticipants[indDesc].nomJ, tabParticipants[indDesc-1].nomJ)==0 // lancement tri alphabetique par rapport au nom du joueur
                       && tabParticipants[indDesc].groupe==tabParticipants[indDesc-1].groupe
                       && strcmp(tabParticipants[indDesc].nomP, tabParticipants[indDesc-1].nomP)<0)
            {
                tampon =tabParticipants[indDesc];  //permutations structure à l'aide de la structure tampon
                tabParticipants[indDesc]= tabParticipants[indDesc-1];
                tabParticipants[indDesc-1]= tampon;
            }


        }

    }
//informer les participants qui font partie d un groupe dans lequel il n y a pas assez de joueurs
    printf("\n"); //revenir a la ligne
    int cptPart2; //compteur boucle affichage

    for (cptPart2=0; cptPart2<=nbreParticipants-1; cptPart2++) //lancement boucle affichage
    {
        if (cptPart2==0 || strcmp(tabParticipants[cptPart2].nomJ,tabParticipants[cptPart2-1].nomJ)!=0) //afficher une seule fois le nom du jeu, afficher les groupes et les noms des jouerus
        {
            if ((cptPart2==0 || (tabParticipants[cptPart2].groupe!=tabParticipants[cptPart2-1].groupe)) || (tabParticipants[cptPart2].nomJ!=tabParticipants[cptPart2-1].nomJ) )
            {
                printf("%s Groupe %d \nJoueurs\n  %s\n", tabParticipants[cptPart2].nomJ,tabParticipants[cptPart2].groupe, tabParticipants[cptPart2].nomP);
            }
            else printf("Joueurs\n  %s\n", tabParticipants[cptPart2].nomP ) ;

        }
        else if (cptPart2==0 || tabParticipants[cptPart2].groupe!=tabParticipants[cptPart2-1].groupe)
        {
            printf("%s Groupe %d  \nJoueurs\n  %s \n", tabParticipants[cptPart2].nomJ,tabParticipants[cptPart2].groupe, tabParticipants[cptPart2].nomP);
        }
        else printf("  %s\n", tabParticipants[cptPart2].nomP);
    }
    numero=0;
    for (numero=0; numero<=NB_JEUX-1; numero++)
    {

        if ((tabJeux[numero].cptParticipants < tabJeux[numero].nbreMin) && (tabJeux[numero].cptParticipants != 0))
        {
            printf("Le groupe %d du jeu %s ne contient pas assez de participants, revenez une prochaine fois!\n", tabJeux[numero].cptGroupes, tabJeux[numero].nom);
        }
    }
}
