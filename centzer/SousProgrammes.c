#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "SousProgrammes.h"


void COULEUR(int texte,int fond)
{
    //0 noir 15 blanc
    //1-bleu foncé 2-vert foncé 3-turquoise foncé 4-rouge foncé
    //5-violet foncé 6-vert kaki 7-gris clair 8-gris foncé
    //9-bleu fluo 10-vert fluo 11-turquoise fluo
    //12-rouge fluo 13-violet fluo 14-jaune
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,fond*16+texte);
}

void SAUVEGARDE ( struct artiste tabArtistes[50], int nbArtistes) //Sauvegarde des artistes
{
    FILE*fichier;//on créé un fichier
    int cpt;
    fichier=fopen("fichierArtiste.txt","w");//on ouvre un fichier texte dans lequel on écrit les informations de l'artiste
    cpt=0;
    while(cpt<nbArtistes)
    {
        fprintf(fichier,"%s\n",tabArtistes[cpt].nom);//on sauvegarde  le nom de l'artiste
        fprintf(fichier,"%s\n",tabArtistes[cpt].adressemail);//on sauvegarde  l'adresse mail de l'artiste
        fprintf(fichier,"%s\n",tabArtistes[cpt].mdp);//on sauvegarde  le mot de passe de l'artiste
        fprintf(fichier,"%d\n",tabArtistes[cpt].nbreProjets);//on sauvegarde  le nombre de projets de l'artiste
        //fprintf(fichier,"%d\n",tabArtistes[cpt].*tabProp);//on sauvegarde  le nom de l'artiste
        cpt++;


    }
    fclose(fichier);//on ferme le fichier
}


void SAUVEGARDE1 ( struct producteur tabProducteurs[50], int nbProducteurs) //Sauvegarde des producteurs
{
    FILE*fichier;
    int cpt;
    fichier=fopen("fichierProducteur.txt","w");
    cpt=0;
    while(cpt<nbProducteurs)
    {
        fprintf(fichier,"%s\n",tabProducteurs[cpt].nom);//on sauvegarde le nom du producteur
        fprintf(fichier,"%s\n",tabProducteurs[cpt].adressemail);//on sauvegarde l'adresse mail du producteur
        fprintf(fichier,"%s\n",tabProducteurs[cpt].mdp);//on sauvegarde le mot de passe du producteur
        fprintf(fichier,"%d\n",tabProducteurs[cpt].nbreArgent);//on sauvegarde le nombre d'investissements
        cpt++;


    }
    fclose(fichier);
}


void SAUVEGARDE2 ( struct projet tabProjets[100], int nbProjets) //Sauvegarde des projets
{
    FILE*fichier;
    int cpt;
    fichier=fopen("fichierProjet.txt","w");
    cpt=0;
    while(cpt<nbProjets)
    {
        fprintf(fichier,"%d\n",tabProjets[cpt].numero);//on sauvegarde le numéro du projet
        fprintf(fichier,"%d\n",tabProjets[cpt].nomprojet);//on sauvegarde le nom du projet
        fprintf(fichier,"%s\n",tabProjets[cpt].adressemail);//on sauvegarde l'adresse mail de l'artiste qui créé le projet
        fprintf(fichier,"%s\n",tabProjets[cpt].date);//on sauvegarde la date de publication du projet
        fprintf(fichier,"%d\n",tabProjets[cpt].etatavancement);//on sauvegarde l'état d'avancement(pourcentage)
        fprintf(fichier,"%s\n",tabProjets[cpt].description);//on sauvegarde la description du projet
        fprintf(fichier,"%s\n",tabProjets[cpt].listefinanciers);//on sauvegarde la liste des personnes qui financent le projet
        fprintf(fichier,"%f\n",tabProjets[cpt].financement);//on sauvegarde la somme demandée par l'artiste pour son projet
        fprintf(fichier,"%f\n",tabProjets[cpt].sommeversee);//on sauvegarde la somme versée par le producteur pour ce projet
        //fprintf(fichier,"%s\n",tabArtistes[cpt].);
        cpt++;


    }
    fclose(fichier);
}


/*void SAUVEGARDE3 ( struct artiste tabArtistes[50], int nbArtistes){//sauvegarde des investissements
FILE*fichier;
int cpt;
fichier=fopen("fichierArtiste.txt","w");
cpt=0;
while(cpt<nbArtistes){
    fprintf(fichier,"%s\n",tabArtistes[cpt].nom);
    fprintf(fichier,"%s\n",tabArtistes[cpt].adressemail);
    fprintf(fichier,"%s\n",tabArtistes[cpt].mdp);
    fprintf(fichier,"%d\n",tabArtistes[cpt].nbreProjets);
    //fprintf(fichier,"%s\n",tabArtistes[cpt].);
    cpt++;


}
fclose(fichier);
}*/
