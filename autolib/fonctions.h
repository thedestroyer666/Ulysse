#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#define TAILLE_NOM 30
#define TAILLE_TABS 7


struct utilisateur
{

    int numdossier;
    char nom[TAILLE_NOM];
    int abonnement;//0=pas abo 1=abo
    char mdp[TAILLE_NOM];//mot de passe
    int station;//station ou se trouve l'utilisateur
    int voiture;//0=pieds 1=voiture
};

struct voiture
{
    int voiture;
    int etat;//0=pas d'Utilisateur 1=Utilisateur
    int station;// station ou se trouve la voiture, 0 si elle n'est pas dans une station
};
struct station
{
    int station;
    int nbrevoitures;
    int places;
};
struct gestionnaire
{
    char nom[TAILLE_NOM];
    char mdp[TAILLE_NOM];//mot de passe

};

typedef struct
{
    struct station      tabstation[TAILLE_TABS];
    struct utilisateur  tabutil[TAILLE_TABS];
    int                 nombre_utilisateurs_deja_enregistres;
} t_sauve;

extern t_sauve sauve;
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
