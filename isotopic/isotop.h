#ifndef ISOTOPIC__H_INCLUDED
#define ISOTOPIC__H_INCLUDED
#define NBRE_LETTRE 20 //Nombre de lettre du pr�nom
#define NBRE_DECOMPTE 10 //Nombres de coups avant disparition de l'�lement
struct square
    {
        int valeur;
        int decompte;
    };
    char nomj[NBRE_LETTRE];//Nom du joueur
    int regle;//affichage r�gles
    int taille; //Taille du tableau
    int ligne;//ligne
    int colonne;//colonne tableau
    int element;//Element de la case
    int cptligne; //Compteur ligne de remplissage du tableau
    int cptcolonne; //Compteur colonne de remplissage du tableau
    int cptaffc; //compteur d'affichage colonne tableau
    int cptaffl; //compteur d'affichage ligne tableau
    int massemax; //Score que le joueur souhaite atteindre
    int casevide;//Compteur de cases vides
    int indiceloose; //Indice de possibilit� de jouer
    int indicewin; //Inidice de gain de la partie
    int i; //Compteur
    int direction; //Sens de d�placement des �lements
    int fin; //Lorsque le jeu est fini
    int keepplay; // rejouer ou s'arr�ter
    //keepplay=0;
    int change; //changer masse max
    //int indic;
    int tamp;
    int coups; //compteur de coups jou�s
    struct square **tab; //Tableau de jeu

void AFFICHER_TAB (struct square **tab,int taille) ; //Sous programme d'affichage du tableau
void REMPLISSAGE_TABLEAU_DEBUT(struct square **tab,int taille);
void POP_NBRE_ALEATOIRE(struct square**tab,int taille,int *casevide); //Sous programme d'apparitition al�atoire d'un nouvel �l�ment
void GAME_OVER(struct square**tab,int taille,int*indice); //Condition de fin de partie
void YOU_WIN(struct square**tab, int taille, int massemax, int *indice2);//Condition de gain de la partie
void COULEUR (int texte,int fond); //Sous programme d'affichage de couleurs
void SOUND_END(); //Musique de game over
void REGLES(char nomj[NBRE_LETTRE]); //Affichage des r�gles du jeu
void MVMT_DROITE (struct square **tab, int taille, int *casevide); //D�placement droite
void MVMT_BAS (struct square **tab, int taille, int *casevide); //D�placement bas
void MVMT_HAUT(struct square **tab, int taille, int *casevide); // D�placement haut
void MVMT_GAUCHE (struct square **tab, int taille, int *casevide); //D�placement gauche
void DUREE_DE_VIE(struct square **tab, int taille, int *casevide); // gestion de la dur�e de vie des �l�ments
void SAUVEGARDE_PARTIE(struct square **tab, int taille, char nomj[NBRE_LETTRE], int massemax, int casevide);
void CHARGEMENT_PARTIE(struct square ***tab,int*taille,int*massemax, int*casevide,char *nomj[NBRE_LETTRE]);
void CHARGEMENT_SCORE(int *taille, int *massemax, char *nomj[NBRE_LETTRE]);
void SAUVEGARDE_SCORE(int taille, int massemax, char nomj[NBRE_LETTRE]);
#endif // ISOTOPIC__H_INCLUDED
