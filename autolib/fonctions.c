#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

extern struct gestionnaire tabgest[];
extern int nbregest;
extern int NombresStation;

void print1Util(int i)
{
    printf("\nsauve.tabutil[%d]\n", i);
    printf("\t.nom=%s\n",sauve.tabutil[i].nom);
    printf("\t.numdossier=%d\n",sauve.tabutil[i].numdossier);
    printf("\t.mdp=%s\n",sauve.tabutil[i].mdp);
    printf("\t.abonnement=%d\n",sauve.tabutil[i].abonnement);
    printf("\t.voiture=%d\n",sauve.tabutil[i].voiture);
    printf("\t.station=%d\n",sauve.tabutil[i].station);
}

void printUtil()
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

void print1Station(int i)
{
    printf("\nsauve.tabstation[%d]\n", i);
    printf("\t.places=%d\n",sauve.tabstation[i].places);
    printf("\t.nbrevoitures=%d\n",sauve.tabstation[i].nbrevoitures);
    printf("\t.station=%d\n",sauve.tabstation[i].station);
}

void printStation()
{
    int i;
    printf("\n%s-%d printStation\n",__FILE__,__LINE__);
    for(i=0; i<TAILLE_TABS; i++)
    {
        print1Station(i);
    }
}

void printGest()
{
    int i;
    printf("\n%s-%d printGest\n",__FILE__,__LINE__);
    printf("nombre de gestionnaire =%d",nbregest);
    for(i=0; i<nbregest; i++)
    {
        printf("\ntabgest[%d]\n", i);
        printf("\t.nomgest=%s\n",tabgest[i].nom);
        printf("\t.motdepasse=%s\n",tabgest[i].mdp);
    }
}

int utilisateur_deja_enregistre(char *nom_test)
{
    int i;
    printf("nom_test=%s",nom_test);
    for(i=0; i<sauve.nombre_utilisateurs_deja_enregistres; i++)
    {
        printf("sauve.tabutil[%d].nom\t= %s\n", i, sauve.tabutil[i].nom);
        if(strcmp(sauve.tabutil[i].nom,&nom_test[0])==0)
        {
            printf("\n:) Trouve![%d]\n", i);
            return i;
        }
    }
    printf("\n:( Pas trouve!\n");
    return 777;

}
int gestvalide(char *nom_test)
{
    int i;
    printf("nom_test=%s",nom_test);
    for(i=0; i<nbregest; i++)
    {
        printf("tabgest[%d].nom\t= %s\n", i, tabgest[i].nom);
        if(strcmp(tabgest[i].nom,nom_test)==0)
        {
            printf("\n:) Trouve![%d]\n", i);
            return i;
        }
    }
    printf("\n:( Pas trouve!\n");
    return 777;

}

void init_utils_et_stations()
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
    strcpy(&sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].nom[0],"toto");
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].numdossier = 65;
    strcpy(&sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].mdp[0],"cool");
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].station=4;
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].voiture=0;
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].abonnement=1;
    sauve.nombre_utilisateurs_deja_enregistres++;
    strcpy(&sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].nom[0],"tata");
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].numdossier = 66;
    strcpy(&sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].mdp[0],"gros");
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].station=2;
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].voiture=0;
    sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].abonnement=1;
    sauve.nombre_utilisateurs_deja_enregistres++;
    printUtil();

    nbregest=0;
    strcpy(&tabgest[nbregest].nom[0],"stella");
    strcpy(&tabgest[nbregest].mdp[0],"wesh");
    nbregest++;
    strcpy(&tabgest[nbregest].nom[0],"ulysse");
    strcpy(&tabgest[nbregest].mdp[0],"gros");
    nbregest++;
    printGest();
}

int abs(int distance)
{
    if(distance < 0) distance=-distance;
    return distance;

}

void SaveState(t_sauve *a_ecrire)
{
    // Open the file for writing binary
    FILE *fSaveFile = fopen("SaveFile.bin", "wb");

    if (fSaveFile)
    {
        // Write the structure to the file
        fwrite(a_ecrire, sizeof(a_ecrire), 1, fSaveFile);
        fclose(fSaveFile);
    }
    else
    {
        printf("Erreur ouverture Savefile.bin pour sauvegarde!\n");
    }
}

void RestoreState(t_sauve *a_initialiser)
{
    // Open the file for reading binary
    FILE *fLoadFile = fopen("SaveFile.bin", "rb");

    if (fLoadFile)
    {
        // read the structure from the file
        fread(a_initialiser, sizeof(a_initialiser), 1, fLoadFile);
        fclose(fLoadFile);
    }
    else
    {
        printf("Erreur ouverture Savefile.bin pour relecture de la sauvegarde!\nMais ca ne fait rien, on fera sans\n");
    }
}


