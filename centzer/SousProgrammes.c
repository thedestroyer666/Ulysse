#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "SousProgrammes.h"


void COULEUR(int texte,int fond)
{
    //0 noir 15 blanc
    //1-bleu fonc� 2-vert fonc� 3-turquoise fonc� 4-rouge fonc�
    //5-violet fonc� 6-vert kaki 7-gris clair 8-gris fonc�
    //9-bleu fluo 10-vert fluo 11-turquoise fluo
    //12-rouge fluo 13-violet fluo 14-jaune
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,fond*16+texte);
}

void SAUVEGARDE ( struct artiste tabArtistes[50], int nbArtistes) //Sauvegarde des artistes
{
    FILE*fichier;//on cr�� un fichier
    int cpt;
    fichier=fopen("fichierArtiste.txt","w");//on ouvre un fichier texte dans lequel on �crit les informations de l'artiste
    cpt=0;
    fprintf(fichier,"%d\n",nbArtistes);
    while(cpt<nbArtistes)
    {
        fprintf(fichier,"%s\n",tabArtistes[cpt].nom);//on charge  le nom de l'artiste
        fprintf(fichier,"%s\n",tabArtistes[cpt].adressemail);//on charge  l'adresse mail de l'artiste
        fprintf(fichier,"%s\n",tabArtistes[cpt].mdp);//on charge  le mot de passe de l'artiste
        fprintf(fichier,"%d\n",tabArtistes[cpt].nbreProjets);//on charge  le nombre de projets de l'artiste
        cpt++;


    }
    fclose(fichier);//on ferme le fichier
}

void CHARGEMENT ( struct artiste tabArtistes[50], int *nbArtistes) //chargement des artistes
{
    FILE*fichier;//on cr�� un fichier
    int cpt;
    fichier=fopen("fichierArtiste.txt","r");//on ouvre un fichier texte dans lequel on �crit les informations de l'artiste
    cpt=0;
    fscanf(fichier,"%d",&*nbArtistes);//on lit nbartistes
    while(cpt<*nbArtistes)
    {
        fscanf(fichier,"%s",& (tabArtistes[cpt].nom));//on sauvegarde  le nom de l'artiste
        fscanf(fichier,"%s",& (tabArtistes[cpt].adressemail));//on sauvegarde  l'adresse mail de l'artiste
        fscanf(fichier,"%s",& (tabArtistes[cpt].mdp));//on sauvegarde  le mot de passe de l'artiste
        fscanf(fichier,"%d",& (tabArtistes[cpt].nbreProjets));//on sauvegarde  le nombre de projets de l'artiste
        cpt++;
    }
    fclose(fichier);//on ferme le fichier
}


void SAUVEGARDE1 ( struct producteur tabProducteurs[50], int nbProducteurs) //Sauvegarde des producteurs
{
    FILE*fichier;
    int cpt,j;
    fichier=fopen("fichierProducteur.txt","w");
    cpt=0;
    while(cpt<nbProducteurs)
    {
        fprintf(fichier,"%s\n",tabProducteurs[cpt].nom);//on sauvegarde le nom du producteur
        fprintf(fichier,"%s\n",tabProducteurs[cpt].adressemail);//on sauvegarde l'adresse mail du producteur
        fprintf(fichier,"%s\n",tabProducteurs[cpt].mdp);//on sauvegarde le mot de passe du producteur
        fprintf(fichier,"%d\n",tabProducteurs[cpt].nbreArgent);//on sauvegarde le nombre d'investissements
        for (j=0; j<tabProducteurs[cpt].nbreArgent; j++)
        {
            fprintf(fichier,"%f\n",tabProducteurs[cpt].tabInvest[j].sommeproducteur);
            fprintf(fichier,"%d\n",tabProducteurs[cpt].tabInvest[j].numeroProjet);
        }
        cpt++;


    }
    fclose(fichier);
}

void CHARGEMENT1 ( struct producteur tabProducteurs[50], int *nbProducteurs) //chargement des producteurs
{
    FILE*fichier;//on cr�� un fichier
    int cpt,j;
    fichier=fopen("fichierArtiste.txt","r");//on ouvre un fichier texte dans lequel on �crit les informations du producteur
    cpt=0;
    fscanf(fichier,"%d",&*nbProducteurs);// on ajoute le nomre de producteurs
    while(cpt<*nbProducteurs)
    {
        fscanf(fichier,"%s",& (tabProducteurs[cpt].nom));//on charge  le nom du producteur
        fscanf(fichier,"%s",& (tabProducteurs[cpt].adressemail));//on charge  l'adresse mail du producteur
        fscanf(fichier,"%s",& (tabProducteurs[cpt].mdp));//on charge  le mot de passe du producteurs
        fscanf(fichier,"%d",& (tabProducteurs[cpt].nbreArgent));//
        cpt++;
        for (j=0; j<tabProducteurs[cpt].nbreArgent; j++)
        {
            fscanf(fichier,"%f",&tabProducteurs[cpt].tabInvest[j].sommeproducteur);
            fscanf(fichier,"%d",&tabProducteurs[cpt].tabInvest[j].numeroProjet);
        }
        fclose(fichier);//on ferme le fichier
    }
}


void SAUVEGARDE2 ( struct projet tabProjets[100], int nbProjets) //Sauvegarde des projets
{
    FILE*fichier;
    int cpt;
    fichier=fopen("fichierProjet.txt","w");
    cpt=0;
    fprintf(fichier,"%d\n",nbProjets);
    while(cpt<nbProjets)
    {
        fprintf(fichier,"%d\n",tabProjets[cpt].numero);//on sauvegarde le num�ro du projet
        fprintf(fichier,"%d\n",tabProjets[cpt].nomprojet);//on sauvegarde le nom du projet
        fprintf(fichier,"%s\n",tabProjets[cpt].adressemail);//on sauvegarde l'adresse mail de l'artiste qui cr�� le projet
        fprintf(fichier,"%s\n",tabProjets[cpt].date);//on sauvegarde la date de publication du projet
        fprintf(fichier,"%d\n",tabProjets[cpt].etatavancement);//on sauvegarde l'�tat d'avancement(pourcentage)
        fprintf(fichier,"%s\n",tabProjets[cpt].description);//on sauvegarde la description du projet
        fprintf(fichier,"%s\n",tabProjets[cpt].listefinanciers);//on sauvegarde la liste des personnes qui financent le projet
        fprintf(fichier,"%f\n",tabProjets[cpt].financement);//on sauvegarde la somme demand�e par l'artiste pour son projet
        fprintf(fichier,"%f\n",tabProjets[cpt].sommeversee);//on sauvegarde la somme vers�e par le producteur pour ce projet
        cpt++;


    }
    fclose(fichier);
}


void CHARGEMENT2 ( struct projet tabProjets[100], int *nbProjets) //chargement
{
    FILE*fichier;
    int cpt;
    fichier=fopen("fichierProjet.txt","r");
    fscanf(fichier,"%d",&*nbProjets);//on lit nbProjets
    cpt=0;
    while(cpt<*nbProjets)
    {
        fscanf(fichier,"%d",& (tabProjets[cpt].numero));//on charge le num�ro du projet
        fscanf(fichier,"%d",& (tabProjets[cpt].nomprojet));//on charge le nom du projet
        fscanf(fichier,"%s",& (tabProjets[cpt].adressemail));//on charge l'adresse mail de l'artiste qui cr�� le projet
        fscanf(fichier,"%s",& (tabProjets[cpt].date));//on charge la date de publication du projet
        fscanf(fichier,"%d",& (tabProjets[cpt].etatavancement));//on charge l'�tat d'avancement(pourcentage)
        fscanf(fichier,"%s",& (tabProjets[cpt].description));//on charge la description du projet
        fscanf(fichier,"%s",& (tabProjets[cpt].listefinanciers));//on charge la liste des personnes qui financent le projet
        fscanf(fichier,"%f",& (tabProjets[cpt].financement));//on charge la somme demand�e par l'artiste pour son projet
        fscanf(fichier,"%f",& (tabProjets[cpt].sommeversee));//on charge la somme vers�e par le producteur pour ce projet
        cpt++;


    }
    fclose(fichier);
}

