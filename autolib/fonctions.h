#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#define TAILLE_NOM 30
#define TAILLE_TABS 7


struct utilisateur
{

    int numdossier;         //numéro du dossier
    char nom[TAILLE_NOM];   //nom de l'utilisateur
    int abonnement;         //0=pas abo 1=abo
    char mdp[TAILLE_NOM];   //mot de passe
    int station;            //station ou se trouve l'utilisateur
    int voiture;            //0=pieds 1=voiture
    int facture;            //nombre total du cout
    int nbretrajet;         //nombre total de trajet
};

struct voiture// on a créé la structure au début mais on ne l'as pas utilisé
{
    int voiture;
    int etat; //0=pas d'Utilisateur 1=Utilisateur
    int station; // station ou se trouve la voiture, 0 si elle n'est pas dans une station
};
struct station
{
    int station; // numéro de la station
    int nbrevoitures; //nbres de voitures disponibles dans la station
    int places; //nbres de places disponibles dans la station
};
struct gestionnaire
{
    char nom[TAILLE_NOM]; //nom du gestionnaire
    char mdp[TAILLE_NOM]; //mot de passe du gestionnaire

};

typedef struct//on réunit les structures dans une seule structure
{
    struct station      tabstation[TAILLE_TABS];
    struct utilisateur  tabutil[TAILLE_TABS];
    int                 nombre_utilisateurs_deja_enregistres;
} t_sauve;

extern t_sauve sauve; // extern sert à ne pas redéclarer les void dans le main
extern int debug;
extern void init_utils_et_stations();
extern void print1Util(int i);
extern void printUtil();
extern void print1Station(int i);
extern void printStation();
extern void printGest();
extern int utilisateur_deja_enregistre(char *nom_test);
extern int gestvalide(char *nom_test);
extern int abs(int distance);
extern void SaveState(t_sauve a_ecrire);
extern void RestoreState(t_sauve *a_initialiser);
#endif // FONCTIONS_H_INCLUDED
