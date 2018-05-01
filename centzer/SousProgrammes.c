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
    printf("%s-%d Sauve Artistes\n",__FILE__,__LINE__);
    fichier=fopen("fichierArtiste.txt","w");//on ouvre un fichier texte dans lequel on écrit les informations de l'artiste
    cpt=0;
    fprintf(fichier,"%d\n",nbArtistes);
    while(cpt<nbArtistes)
    {
        fprintf(fichier,"%s\n",tabArtistes[cpt].nom);//on charge  le nom de l'artiste
        fprintf(fichier,"%s\n",tabArtistes[cpt].adressemail);//on charge  l'adresse mail de l'artiste
        fprintf(fichier,"%s\n",tabArtistes[cpt].mdp);//on charge  le mot de passe de l'artiste
        fprintf(fichier,"%d\n",tabArtistes[cpt].nbreProjets);//on charge  le nombre de projets de l'artiste
        printf("%s-%d      %d %s\n",__FILE__,__LINE__, cpt, tabArtistes[cpt].adressemail);
        cpt++;
    }
    fclose(fichier);//on ferme le fichier
}

void CHARGEMENT ( struct artiste tabArtistes[50], int *nbArtistes) //chargement des artistes
{
    FILE*fichier;//on créé un fichier
    int cpt;
    printf("%s-%d Charge Artistes\n",__FILE__,__LINE__);
    fichier=fopen("fichierArtiste.txt","r");//on ouvre un fichier texte dans lequel on écrit les informations de l'artiste
    cpt=0;
    fscanf(fichier,"%d",&*nbArtistes);//on lit nbartistes
    while(cpt<*nbArtistes)
    {
        fscanf(fichier,"%s",& (tabArtistes[cpt].nom));//on sauvegarde  le nom de l'artiste
        fscanf(fichier,"%s",& (tabArtistes[cpt].adressemail));//on sauvegarde  l'adresse mail de l'artiste
        fscanf(fichier,"%s",& (tabArtistes[cpt].mdp));//on sauvegarde  le mot de passe de l'artiste
        fscanf(fichier,"%d",& (tabArtistes[cpt].nbreProjets));//on sauvegarde  le nombre de projets de l'artiste
        printf("%s-%d      %d %s\n",__FILE__,__LINE__, cpt, tabArtistes[cpt].adressemail);
        cpt++;
    }
    fclose(fichier);//on ferme le fichier
}


void SAUVEGARDE1 ( struct producteur tabProducteurs[50], int nbProducteurs) //Sauvegarde des producteurs
{
    FILE*fichier;
    int cpt,j;
    printf("%s-%d Sauve Producteurs\n",__FILE__,__LINE__);
    fichier=fopen("fichierProducteur.txt","w");
    cpt=0;
    fprintf(fichier,"%d\n",nbProducteurs);
    while(cpt<nbProducteurs)
    {
        fprintf(fichier,"%s\n",tabProducteurs[cpt].nom);//on sauvegarde le nom du producteur
        fprintf(fichier,"%s\n",tabProducteurs[cpt].adressemail);//on sauvegarde l'adresse mail du producteur
        fprintf(fichier,"%s\n",tabProducteurs[cpt].mdp);//on sauvegarde le mot de passe du producteur
        fprintf(fichier,"%d\n",tabProducteurs[cpt].nbreArgent);//on sauvegarde le nombre d'investissements
        for (j=0; j<tabProducteurs[cpt].nbreArgent; j++)
        {
            fprintf(fichier,"%s\n",tabProducteurs[cpt].tabInvest[j].nomprojet);
            fprintf(fichier,"%f\n",tabProducteurs[cpt].tabInvest[j].sommeproducteur);
        }
        printf("%s-%d      %d %s\n",__FILE__,__LINE__, cpt, tabProducteurs[cpt].adressemail);
        cpt++;
    }
    fclose(fichier);
}

void CHARGEMENT1 ( struct producteur tabProducteurs[50], int *nbProducteurs) //chargement des producteurs
{
    FILE*fichier;//on créé un fichier
    int cpt,j;
    printf("%s-%d Charge Producteurs\n",__FILE__,__LINE__);
    fichier=fopen("fichierProducteur.txt","r");//on ouvre un fichier texte dans lequel on écrit les informations du producteur
    cpt=0;
    fscanf(fichier,"%d",&*nbProducteurs);// on ajoute le nomre de producteurs
    while(cpt<*nbProducteurs)
    {
        fscanf(fichier,"%s",& (tabProducteurs[cpt].nom));//on charge  le nom du producteur
        fscanf(fichier,"%s",& (tabProducteurs[cpt].adressemail));//on charge  l'adresse mail du producteur
        fscanf(fichier,"%s",& (tabProducteurs[cpt].mdp));//on charge  le mot de passe du producteurs
        fscanf(fichier,"%d",& (tabProducteurs[cpt].nbreArgent));//
        for (j=0; j<tabProducteurs[cpt].nbreArgent; j++)
        {
            fscanf(fichier,"%s",& (tabProducteurs[cpt].tabInvest[j].nomprojet));
            fscanf(fichier,"%f",& (tabProducteurs[cpt].tabInvest[j].sommeproducteur));
        }
        printf("%s-%d      %d %s\n",__FILE__,__LINE__, cpt, tabProducteurs[cpt].adressemail);
        cpt++;
    }
    fclose(fichier);//on ferme le fichier

}


void SAUVEGARDE2 ( struct projet tabProjets[100], int nbProjets) //Sauvegarde des projets
{
    FILE*fichier;
    int cpt;
    printf("%s-%d Sauve Projets\n",__FILE__,__LINE__);
    fichier=fopen("fichierProjet.txt","w");
    fprintf(fichier,"%d\n",nbProjets);
    cpt=0;
    while(cpt<nbProjets)
    {
        fprintf(fichier,"%s\n",tabProjets[cpt].nomprojet);//on sauvegarde le nom du projet
        fprintf(fichier,"%s\n",tabProjets[cpt].adressemail);//on sauvegarde l'adresse mail de l'artiste qui créé le projet
        fprintf(fichier,"%s\n",tabProjets[cpt].date);//on sauvegarde la date de publication du projet
        fprintf(fichier,"%f\n",tabProjets[cpt].financement);//on sauvegarde la somme demandée par l'artiste pour son projet
        fprintf(fichier,"%f\n",tabProjets[cpt].sommeversee);//on sauvegarde la somme versée par le producteur pour ce projet
        fprintf(fichier,"%d\n",tabProjets[cpt].etatavancement);//on sauvegarde l'état d'avancement(pourcentage)
        fprintf(fichier,"%s\n",tabProjets[cpt].description);//on sauvegarde la description du projet
        fprintf(fichier,"%s\n",tabProjets[cpt].listefinanciers);//on sauvegarde la liste des personnes qui financent le projet
        printf("%s-%d      %d %s-%s %f.\n",__FILE__,__LINE__, cpt, tabProjets[cpt].nomprojet, tabProjets[cpt].adressemail, tabProjets[cpt].financement);
        cpt++;
    }
    fclose(fichier);
}


void CHARGEMENT2 ( struct projet tabProjets[100], int *nbProjets) //chargement
{
    FILE*fichier;
    int cpt;
    printf("%s-%d Charge Projets\n",__FILE__,__LINE__);
    fichier=fopen("fichierProjet.txt","r");
    fscanf(fichier,"%d",&*nbProjets);//on lit nbProjets
    cpt=0;
    while(cpt<*nbProjets)
    {
        fscanf(fichier,"%s",& (tabProjets[cpt].nomprojet));//on charge le nom du projet
        fscanf(fichier,"%s",& (tabProjets[cpt].adressemail));//on charge l'adresse mail de l'artiste qui créé le projet
        fscanf(fichier,"%s",& (tabProjets[cpt].date));//on charge la date de publication du projet
        fscanf(fichier,"%f",& (tabProjets[cpt].financement));//on charge la somme demandée par l'artiste pour son projet
        fscanf(fichier,"%f",& (tabProjets[cpt].sommeversee));//on charge la somme versée par le producteur pour ce projet
        fscanf(fichier,"%d",& (tabProjets[cpt].etatavancement));//on charge l'état d'avancement(pourcentage)
        fscanf(fichier,"%s",& (tabProjets[cpt].description));//on charge la description du projet
        fscanf(fichier,"%s",& (tabProjets[cpt].listefinanciers));//on charge la liste des personnes qui financent le projet
        printf("%s-%d      %d %s-%s %f.\n",__FILE__,__LINE__, cpt, tabProjets[cpt].nomprojet, tabProjets[cpt].adressemail, tabProjets[cpt].financement);
        cpt++;
    }
    fclose(fichier);
}

void afficheProjet(struct projet tabProjets[100], int indexProjet)
{
    printf("%d\n ",indexProjet);
    printf("%s\n ",tabProjets[indexProjet].adressemail);
    printf("%s\n ",tabProjets[indexProjet].date);
    printf("financement  %f\n ",tabProjets[indexProjet].financement);
    printf("somme versee %f\n ",tabProjets[indexProjet].sommeversee);
    //printf("lf %s\n ",tabProjets[indexProjet].listefinanciers);
    printf("%s\n ",tabProjets[indexProjet].description);
    printf("avancement: %d\n",tabProjets[indexProjet].etatavancement);

}
