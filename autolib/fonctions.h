#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#define STRINGIFY2( x) #x
#define STRINGIFY(x) STRINGIFY2(x)
#define valueInt( myvar) STRINGIFY(myvar##_), myvar
#define my_printInt( myvar) printf("%s\t= %d\n",valueInt( myvar))
#define valueStr( myvar) STRINGIFY(myvar##_), myvar
#define my_printStr( myvar) printf("%s\t= %s\n",valueInt( myvar))

#define taille 30
#define TAILLE_TABS 7

extern void init_utils_et_stations();
extern void print1Util(int i);
extern void printUtil();
extern void print1Station(int i);
extern void printStation();
extern void printGest();
int utilisateur_deja_enregistre(char *nom_test);
int gestvalide(char *nom_test);
extern int abs(int distance);

struct utilisateur
{

    int numdossier;
    char nom[taille];
    int abonnement;//0=pasabo 1=abo
    char mdp[taille];//mot de passe
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
    char nom[taille];
    char mdp[taille];//mot de passe

};



#endif // FONCTIONS_H_INCLUDED
