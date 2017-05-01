#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

extern struct gestionnaire tabgest[];
extern int nbregest;
extern int NombresStation;

void print1Util(int i) // fonction pour afficher les informations d'un utilisateur
{
    printf("\nsauve.tabutil[%d]\n", i);
    printf("\t.nom=%s\n",sauve.tabutil[i].nom);
    printf("\t.numdossier=%d\n",sauve.tabutil[i].numdossier);
    printf("\t.mdp=%s\n",sauve.tabutil[i].mdp);
    printf("\t.abonnement=%d\n",sauve.tabutil[i].abonnement);
    printf("\t.voiture=%d\n",sauve.tabutil[i].voiture);
    printf("\t.station=%d\n",sauve.tabutil[i].station);
    printf("\t.facture=%d\n",sauve.tabutil[i].facture);
    printf("\t.nbretrajet=%d\n",sauve.tabutil[i].nbretrajet);
}

void printUtil() // fonction pour afficher les informations de tout les utilisateurs
{
    int i;
    printf("\n%s-%d printUtil\n",__FILE__,__LINE__);
    printf("nombre_utilisateurs_deja_enregistres =%d",sauve.nombre_utilisateurs_deja_enregistres);
    for(i=0; i<sauve.nombre_utilisateurs_deja_enregistres; i++)
    {
        if(sauve.tabutil[i].abonnement==1)
        {
            print1Util(i);
        }
    }
}

void print1Station(int i) //fonction pour afficher les informations  d'une station
{
    printf("\nstation[%d]\n", i);
    printf("\t.places=%d\n",sauve.tabstation[i].places);
    printf("\t.nbrevoitures=%d\n",sauve.tabstation[i].nbrevoitures);
    printf("\t.station=%d\n",sauve.tabstation[i].station);
}

void printStation() //fonction pour afficher les informations de toutes les stations
{
    int i;
    printf("\n%s-%d Station\n",__FILE__,__LINE__);
    for(i=0; i<TAILLE_TABS; i++)
    {
        print1Station(i);
    }
}

void printGest() //fonction pour afficher les informations d'un gestionnaire
{
    int i;
    printf("\n%s-%d Gest\n",__FILE__,__LINE__);
    printf("nombre de gestionnaire =%d",nbregest);
    for(i=0; i<nbregest; i++)
    {
        printf("\ntabgest[%d]\n", i);
        printf("\t.nomgest=%s\n",tabgest[i].nom);
        printf("\t.motdepasse=%s\n",tabgest[i].mdp);
    }
}

int utilisateur_deja_enregistre(char *nom_test) // vérification du mot de passe de l'utilisateur
{
    int i;
    if(debug==1) printf("nom_test=%s",nom_test);
    for(i=0; i<sauve.nombre_utilisateurs_deja_enregistres; i++)
    {
        if(debug==1) printf("tabutil[%d].nom\t= %s\n", i, sauve.tabutil[i].nom);
        if(strcmp(sauve.tabutil[i].nom,&nom_test[0])==0)
        {
            if(debug==1) printf("\n:) Trouve![%d]\n", i);
            return i;
        }
    }
    if(debug==1) printf("\n:( Pas trouve!\n");
    return 777;

}
int gestvalide(char *nom_test) // vérification du mot de passe du gestionnaire
{
    int i;
    if(debug==1) printf("nom_test=%s",nom_test);
    for(i=0; i<nbregest; i++)
    {
        if(debug==1) printf("tabgest[%d].nom\t= %s\n", i, tabgest[i].nom);
        if(strcmp(tabgest[i].nom,nom_test)==0)
        {
            if(debug==1) printf("\n:) Trouve![%d]\n", i);
            return i;
        }
    }
    if(debug==1) printf("\n:( Pas trouve!\n");
    return 777;

}

void init_utils_et_stations() // initialise les stations, les utilisateurs et les gestionnaires
{
    sauve.tabstation[1].station=1;
    sauve.tabstation[1].places=17;
    sauve.tabstation[1].nbrevoitures=1;

    sauve.tabstation[2].station=2;
    sauve.tabstation[2].places=16;
    sauve.tabstation[2].nbrevoitures=2;

    sauve.tabstation[3].station=3;
    sauve.tabstation[3].places=0;
    sauve.tabstation[3].nbrevoitures=0;

    sauve.tabstation[4].station=4;
    sauve.tabstation[4].places=16;
    sauve.tabstation[4].nbrevoitures=2;

    sauve.tabstation[5].station=5;
    sauve.tabstation[5].places=16;
    sauve.tabstation[5].nbrevoitures=2;

    sauve.nombre_utilisateurs_deja_enregistres = 0;
    strcpy(&sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].nom[0],"toto"); //&yyyy[0] est un char * : strcpy(char *dest, const char *src)
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].numdossier = 65;
    strcpy(&sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].mdp[0],"cool");
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].station=4;
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].voiture=0;
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].abonnement=1;
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].facture=0;
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].nbretrajet=0;
    sauve.nombre_utilisateurs_deja_enregistres++;

    strcpy(&sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].nom[0],"tata");
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].numdossier = 66;
    strcpy(&sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].mdp[0],"gros");
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].station=2;
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].voiture=0;
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].abonnement=1;
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].facture=0;
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].nbretrajet=0;
    sauve.nombre_utilisateurs_deja_enregistres++;

    nbregest=0;
    strcpy(&tabgest[nbregest].nom[0],"stella");
    strcpy(&tabgest[nbregest].mdp[0],"wesh");
    nbregest++;
    strcpy(&tabgest[nbregest].nom[0],"ulysse");
    strcpy(&tabgest[nbregest].mdp[0],"gros");
    nbregest++;
}

int abs(int distance) //fonction valeur absolue pour calculer les différentes distances
{
    if(distance < 0) distance=-distance;
    return distance;

}


// ask google : c language save and read data from file
// https://www.gamedev.net/topic/633653-save-and-read-data-from-file/
void SaveState(t_sauve a_ecrire) // fonction qui sauvent les structures dans un fichier
{
    // Open the file for writing binary
    FILE *fSaveFile = fopen("SaveFile.bin", "wb");

    if (fSaveFile)
    {
        // Write the structure to the file
        fwrite(&a_ecrire, sizeof(t_sauve), 1, fSaveFile);
        fclose(fSaveFile);
        if(debug==1) printf("*** Sauvegarde dans Savefile.bin \n");
    }
    else
    {
        printf("Erreur ouverture Savefile.bin pour sauvegarde!\n");
    }
}

void RestoreState(t_sauve *a_initialiser) // fonction qui lit les structures sauvées
{
    // Open the file for reading binary
    FILE *fLoadFile = fopen("SaveFile.bin", "rb");

    if (fLoadFile)
    {
        // read the structure from the file
        fread(a_initialiser, sizeof(t_sauve), 1, fLoadFile);
        fclose(fLoadFile);
        if(debug==1) printf("*** Relecture de la sauvegarde dans Savefile.bin \n");
    }
    else
    {
        printf("Erreur ouverture Savefile.bin pour relecture de la sauvegarde!\nMais ca ne fait rien, on fera sans\n");
    }
}
