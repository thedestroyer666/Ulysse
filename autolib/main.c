#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"


struct station tabstation[TAILLE_TABS];
struct utilisateur tabutil[TAILLE_TABS];
int nombre_utilisateurs_deja_enregistres = 0;
struct gestionnaire tabgest[TAILLE_TABS];
int nbregest = 0;
int temps;//temps du trajet

int main()
{
    int cpt=10 ;
    int temps=0 ;
    FILE *fichier;
    char nomFichier[30]="dossier_utilisateur.txt";
    fichier=fopen(nomFichier, "w");//pour ouvrir le fichier en mode écriture
    fprintf(fichier, "%d\n", cpt);

    fclose(fichier);//pour fermer le fichier


    //int tab[TAILLE_TABS][TAILLE_TABS];

    int numdossier;
    //struct voiture automobile;
    char nom_temp[taille];

    char mdp_temp[taille];//mot de passe util
    char choixUtil;//coix abcd de l'utilisateur
    char junk;//pour debuguer car abcd caractères et enter aussi
    int utilindex=888;//l'index de l'utilisateur
    int oldutilindex=999;// pour ne pas a avoir a rentrer deux fois le mdp
    int gestindex=888;//l'index du gestionnaire
    int oldgestindex=999;// pour ne pas a avoir a rentrer deux fois le mdp

    //automobile.voiture=16;


    init_utils_et_stations();
    do   //pour tout recommencer
    {
        //Demander la nature de la personne (gestionnaire, utilisateur)
        //do
        {
            printf("ETES VOUS GESTIONNAIRE OU UTILISATEUR ?\n Tapez 1: utilisateur\n tapez 2: gestionnaire\n tapez 3: quitter\n ");
            scanf("%d",&cpt);

            if (cpt<=0 || cpt>3)
            {
                printf("erreur, tapez un chiffre entre 1 et 3 ");
            }

        }
        //while (cpt<=0 || cpt>3);

        if (cpt==1)
        {
            int stationindex;
            //menu utilisateur
            //if(new dossier)
            numdossier=0;
            printf("Quel est votre nom ?\n");
            scanf("%s",&(nom_temp[0]));
            utilindex = utilisateur_deja_enregistre(nom_temp);
            if(utilindex!=777)
            {
                if(oldutilindex!=utilindex)
                {
                    printf("tapez votre mot de passe?\n");
                    scanf("%s",&(mdp_temp[0]));
                    if(strcmp(tabutil[utilindex].mdp,mdp_temp)==0)
                    {
                        printf("  Bienvenue\n");
                        //afficher les informations de l'utilisateurs
                        print1Util(utilindex);
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    printf("  C est toujours vous\n");
                    //afficher les informations de l'utilisateurs
                    print1Util(utilindex);
                }
            }
            else
            {
                printf("Nouvel utilisateur!\n");

                printf("choisissez votre mot de passe ?\n");
                scanf("%s",&(mdp_temp[0]));
                printf("votre numero de dossier est %d\n",numdossier);

                strcpy(&tabutil[nombre_utilisateurs_deja_enregistres].nom[0],nom_temp);
                strcpy(&tabutil[nombre_utilisateurs_deja_enregistres].mdp[0],mdp_temp);
                tabutil[nombre_utilisateurs_deja_enregistres].numdossier = 100+nombre_utilisateurs_deja_enregistres;
                nombre_utilisateurs_deja_enregistres++;
                printUtil();
                utilindex = nombre_utilisateurs_deja_enregistres;
            }
            oldutilindex=utilindex;


            scanf("%c",&junk); // purge le buffer de scanf
            printf("Que voulez vous faire ?\n ");
            if (tabutil[utilindex].voiture==0)
            {
                printf("\ta) Louer un vehicule\n");

            }
            else
            {
                printf("\tb) rendre un vehicule\n ");

            }
            printf("\tc) consulter mon statut\n\td) je sors\n");

            scanf("%c",&choixUtil);

            // on ne verifie pas que l'utilisateur tape un choix interdit. C'est mal.
            if (choixUtil=='a')

            {
                printf("entrez le numero de la station\n");//demander la station
                scanf("%d",&stationindex);
                tabutil[utilindex].station = stationindex;


                if (tabstation[stationindex].nbrevoitures!=0) //verifier si il y a une voiture de disponible dans la station
                {
                    print1Station(stationindex);

                    //l'attribuer a l'utilisateur
                    printf("une voiture vous a ete attribue\n");
                    tabutil[utilindex].voiture=1;
                    tabstation[stationindex].places=tabstation[stationindex].places+1;
                    tabstation[stationindex].nbrevoitures=tabstation[stationindex].nbrevoitures-1;
                    print1Station(stationindex);
                }

                else
                {
                    int cptstation;
                    int distancetampon;
                    int distanceminimum;
                    int indexminimum;
                    distanceminimum=666;
                    indexminimum=666;

                    for(cptstation=0; cptstation<5; cptstation++) //trouver la plus courte distance entre l'utilisateur et une voiture
                    {
                        if(tabstation[cptstation].nbrevoitures!=0)
                        {
                            distancetampon=abs(tabstation[cptstation].station-tabstation[stationindex].station);
                            if(distancetampon<distanceminimum)
                            {
                                distanceminimum=distancetampon;
                                indexminimum=cptstation;
                            }
                        }
                    }
                    printf("vous devez aller chercher une voiture a la station %d\n",tabstation[indexminimum].station);

                }
            }
            else if (choixUtil=='b')
            {
                printf("bonjour, entrez le numero de la station\n");
                scanf("%d",&stationindex);//demander la station
                tabutil[utilindex].station = stationindex;
                print1Station(stationindex);
                if (tabstation[stationindex].places!=0) //verifier qu'il y a de la place
                {
                    tabutil[utilindex].voiture=0;
                    tabstation[stationindex].places=tabstation[stationindex].places-1;
                    tabstation[stationindex].nbrevoitures=tabstation[stationindex].nbrevoitures+1;

                    printf("combien de temps avez vous mis ?\n en minutes :");//demander le temps du trajet
                    scanf("%d",&temps);//afficher le prix et le deduire du compte
                    if(temps<=30)
                    {
                        temps=0;
                        printf("une facture de %d euro vous sera envoyee\n",temps);
                    }
                    else
                    {
                        temps=(temps-30);
                        printf("une facture de %d euros vous sera envoyee\n",temps);
                    }


                }
                else //sinon chercher la place la plus proche

                {
                    int cptstation;
                    int distancetampon;
                    int distanceminimum;
                    int indexminimum;
                    distanceminimum=666;
                    indexminimum=666;

                    for(cptstation=0; cptstation<5; cptstation++) //trouver la plus courte distance entre l'utilisateur et une voiture
                    {
                        if(tabstation[cptstation].places!=0)
                        {
                            distancetampon=abs(tabstation[cptstation].station-tabstation[stationindex].station);
                            if(distancetampon<distanceminimum)
                            {
                                distanceminimum=distancetampon;
                                indexminimum=cptstation;
                            }
                        }


                    }
                    printf("vous devez aller rendre la voiture a la station %d\n",tabstation[indexminimum].station);

                }


            }

            else if (choixUtil=='c')
            {

                //afficher les informations de l'utilisateurs
                print1Util(utilindex);
            }
            else if (choixUtil=='d')
            {
                printf("%c Je sors\n",choixUtil);
                return 0;

            }
            else
            {
                printf("%c recommencer\n",choixUtil);
            }

        }
        else if (cpt==2)
        {
            printf("Quel est votre nom ?\n");
            scanf("%s",&(nom_temp[0]));
            gestindex = gestvalide(nom_temp);
            if(gestindex!=777)
            {
                if(oldgestindex!=gestindex)
                {
                    printf("tapez votre mot de passe?\n");
                    scanf("%s",&(mdp_temp[0]));
                    if(strcmp(tabgest[gestindex].mdp,mdp_temp)==0)
                    {
                        printf("  Bienvenue\n");
                        //afficher les informations de l'utilisateurs
                        printGest(gestindex);
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {


                    //afficher les informations des utilisateurs
                    //print1gest(utilgest);
                }
            }
            printf("  C est toujours vous\n");
            printUtil();
            printStation();

        }
        /* else if (cpt==3)
         {//cas annulé

         }*/


    }
    while ( cpt!=3);
//si gestonnaire
    // consulter et modifier comptes utilisateurs
    //consulter et modifier nbre vehicules
    //statistiques
}
