#ifndef SOUSPROGRAMMES_H_INCLUDED
#define SOUSPROGRAMMES_H_INCLUDED

#define NB_LETTRES 200

struct artiste
{
    char nom[NB_LETTRES+1]; //nom de l'utilisateur
    char adressemail[NB_LETTRES+1]; //adresse mail de l'utilisateur (artiste)
    char mdp[NB_LETTRES+1]; //mot de passe de l'utilisateur (artiste)
    int nbreProjets; //nombre de projets dans le tableau
    int *tabProp;//projets propos�s
};

struct investissement
{
    float sommeproducteur; //somme versee par le producteur
    int numeroProjet;
};
struct producteur
{
    char nom[NB_LETTRES+1]; //nom du producteur
    char adressemail[NB_LETTRES+1]; //adresse mail de l'utilisateur (producteur)
    char mdp[NB_LETTRES+1]; //mot de passe de l'utilisateur (producteur)
    int nbreArgent; //nombre d'investissements
    struct investissement *tabInvest;//tableau contenant pour chaque projet la somme vers�e par le producteur
};

struct projet
{
    int numero;//identifiant du projet
    char nomprojet[NB_LETTRES+1];
    char adressemail[NB_LETTRES+1]; //adresse mail de l'artiste
    char date[NB_LETTRES+1]; //date de publication du projet
    float financement; //financement du projet
    float sommeversee; //total des sommes d�j� vers�es
    char listefinanciers; //liste des personnes finan�ant le projet
    char description[NB_LETTRES+1]; //texte descriptif du projet
    int etatavancement; //pourcentage indiquant l'avancement

};

void COULEUR(int texte,int fond);
void SAUVEGARDE ( struct artiste tabArtistes[50], int nbArtistes);
void SAUVEGARDE1 ( struct producteur tabProducteur[50], int nbProducteurs);
void SAUVEGARDE2 ( struct projet tabProjets[100], int nbProjets);
#endif // SOUSPROGRAMMES_H_INCLUDED

