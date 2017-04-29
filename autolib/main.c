#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"


/*struct station sauve.tabstation[TAILLE_TABS];
struct utilisateur sauve.tabutil[TAILLE_TABS];*/

t_sauve sauve;

//int nombre_utilisateurs_deja_enregistres = 0;
struct gestionnaire tabgest[TAILLE_TABS];
int nbregest = 0;
int temps;//temps du trajet

int main()
{
    int cpt=10 ;
    int temps=0 ;
    int numdossier;
    char nom_temp[TAILLE_NOM];  //quand on lit un nom
    char mdp_temp[TAILLE_NOM];  //quand on lit un mot de passe
    char choixUtil;             //coix abcd de l'utilisateur
    char junk;                  // pour purger le buffer d'entree
    int utilindex=888;          //l'index de l'utilisateur
    int oldutilindex=999;       // pour ne pas a avoir a rentrer deux fois le mdp
    int gestindex=888;          //l'index du gestionnaire
    int oldgestindex=999;       // pour ne pas a avoir a rentrer deux fois le mdp
    int choixgest;              //choix du gestionnaire
    int stationindex;           //station que choisit l'utilisateur ou le gestionnaire
    sauve.nombre_utilisateurs_deja_enregistres = 0;

    init_utils_et_stations(); // de toutes facon on initialise la structure
    RestoreState(&sauve); // si jamis on trouve un fichier Savefile.bin, on initialise la structure avec ce que l'on trouve dedans
    printUtil();
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

            //menu utilisateur
            //if(new dossier)
            numdossier=0;
            printf("Quel est votre nom ?\n");
            scanf("%s",&(nom_temp[0]));
            utilindex = utilisateur_deja_enregistre(nom_temp);

            if(utilindex!=777)

            {
                if (sauve.tabutil[utilindex].abonnement==1)
                {

                    if(oldutilindex!=utilindex)
                    {
                        printf("tapez votre mot de passe?\n");
                        scanf("%s",&(mdp_temp[0]));
                        print1Util(utilindex);
                        if(strcmp(sauve.tabutil[utilindex].mdp,mdp_temp)==0)
                        {
                            printf("  Bienvenue\n");
                            //afficher les informations de l'utilisateurs
                            print1Util(utilindex);
                        }
                        else
                        {
                            printf("  Mauvais mot de passe\n");
                            return 1;
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

                    printf("vous n'avez plus d'abonnement");
                    return 1;
                }
            }
            else
            {
                printf("Nouvel utilisateur!\n");

                printf("choisissez votre mot de passe ?\n");
                scanf("%s",&(mdp_temp[0]));
                printf("votre numero de dossier est %d\n",numdossier);

                strcpy(&sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].nom[0],nom_temp);
                strcpy(&sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].mdp[0],mdp_temp);
                sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].numdossier = 100+sauve.nombre_utilisateurs_deja_enregistres;
                sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].abonnement=1;
                sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].facture=0;
                sauve.tabutil[sauve.nombre_utilisateurs_deja_enregistres].nbretrajet=0;
                utilindex = sauve.nombre_utilisateurs_deja_enregistres;
                sauve.nombre_utilisateurs_deja_enregistres++;
                printUtil();
            }
            oldutilindex=utilindex;


            scanf("%c",&junk); // purge le buffer de scanf
            printf("Que voulez vous faire ?\n ");
            if (sauve.tabutil[utilindex].voiture==0)
            {
                printf("\ta) Louer un vehicule\n");

            }
            else
            {
                printf("\tb) rendre un vehicule\n ");

            }
            printf("\tc) consulter et modifier mon statut\n\td) je sors\n");

            scanf("%c",&choixUtil);

            // on ne verifie pas que l'utilisateur tape un choix interdit. C'est mal.
            if (choixUtil=='a')

            {
                printf("entrez le numero de la station\n");//demander la station
                scanf("%d",&stationindex);
                sauve.tabutil[utilindex].station = stationindex;


                if (sauve.tabstation[stationindex].nbrevoitures!=0) //verifier si il y a une voiture de disponible dans la station
                {
                    print1Station(stationindex);

                    //l'attribuer a l'utilisateur
                    printf("une voiture vous a ete attribue\n");
                    sauve.tabutil[utilindex].voiture=1;
                    sauve.tabstation[stationindex].places=sauve.tabstation[stationindex].places+1;
                    sauve.tabstation[stationindex].nbrevoitures=sauve.tabstation[stationindex].nbrevoitures-1;
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
                        if(sauve.tabstation[cptstation].nbrevoitures!=0)
                        {
                            distancetampon=abs(sauve.tabstation[cptstation].station-sauve.tabstation[stationindex].station);
                            if(distancetampon<distanceminimum)
                            {
                                distanceminimum=distancetampon;
                                indexminimum=cptstation;
                            }
                        }
                    }
                    printf("vous devez aller chercher une voiture a la station %d\n",sauve.tabstation[indexminimum].station);

                }
            }
            else if (choixUtil=='b')
            {
                printf("bonjour, entrez le numero de la station\n");
                scanf("%d",&stationindex);//demander la station
                sauve.tabutil[utilindex].station = stationindex;
                print1Station(stationindex);
                if (sauve.tabstation[stationindex].places!=0) //verifier qu'il y a de la place
                {
                    sauve.tabutil[utilindex].voiture=0;
                    sauve.tabstation[stationindex].places=sauve.tabstation[stationindex].places-1;
                    sauve.tabstation[stationindex].nbrevoitures=sauve.tabstation[stationindex].nbrevoitures+1;

                    printf("combien de temps avez vous mis ?\n en minutes :");//demander le temps du trajet
                    scanf("%d",&temps);//afficher le prix et le deduire du compte
                    if(temps<=30)
                    {
                        temps=0;
                    }
                    else
                    {
                        temps=(temps-30);
                        sauve.tabutil[utilindex].facture=sauve.tabutil[utilindex].facture+temps;
                    }
                    sauve.tabutil[utilindex].nbretrajet=sauve.tabutil[utilindex].nbretrajet+1;
                    printf("une facture de %d euros vous sera envoyee\n",temps);
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
                        if(sauve.tabstation[cptstation].places!=0)
                        {
                            distancetampon=abs(sauve.tabstation[cptstation].station-sauve.tabstation[stationindex].station);
                            if(distancetampon<distanceminimum)
                            {
                                distanceminimum=distancetampon;
                                indexminimum=cptstation;
                            }
                        }


                    }
                    printf("vous devez aller rendre la voiture a la station %d\n",sauve.tabstation[indexminimum].station);
                }
            }

            else if (choixUtil=='c')
            {

                //afficher les informations de l'utilisateurs
                int choix;
                print1Util(utilindex);
                printf("voulez vous annuler votre abonnement ?\n \t1)Oui 2)Non\n");
                scanf("%d",&choix);
                if (choix==1)
                {
                    sauve.tabutil[utilindex].abonnement=0;
                    print1Util(utilindex);
                }

            }
            else if (choixUtil=='d')
            {
                printf("%c Je sors\n",choixUtil);
                break;

            }
            else
            {
                printf("%c recommencer\n",choixUtil);
            }


        }
        else if (cpt==2)//si gestonnaire
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
                        printf("  Mauvais mot de passe\n");
                        break;
                    }
                }
                else
                {


                    //afficher les informations des utilisateurs
                    //print1gest(utilgest);
                }
            }
            printf("  C est toujours vous\n");
            printUtil();//statistiques
            printStation();

            printf("\t1) ajouter ou supprimer des vehicules\n \t2) supprimer un utilisateur\n");

            scanf("%d",&choixgest);
            if (choixgest==1)  //consulter et modifier nbre vehicules
            {
                int compteur;//nbres de voitures a enlever ou ajouter
                printf("choisissez la station a modifier\n");
                scanf("%d",&stationindex);
                if ((stationindex==0)||(stationindex>TAILLE_TABS))
                {
                    printf("erreur, la base de donnees ne contient pas autant de station\n Station %d, MaxStation%d\n",stationindex,TAILLE_TABS);
                    break;

                }

                printf("combien de voitures voulez vous enlevez ou ajouter?\n");
                scanf("%d",&compteur);
                sauve.tabstation[stationindex].nbrevoitures=sauve.tabstation[stationindex].nbrevoitures+compteur;
                if (sauve.tabstation[stationindex].nbrevoitures<0)
                {
                    sauve.tabstation[stationindex].nbrevoitures=0;
                }



            }
            else if (choixgest==2)  // consulter et modifier comptes utilisateurs
            {

                printf("choisissez l'utilisateur a modifier\n");
                scanf("%d",&utilindex);
                if (utilindex>TAILLE_TABS)
                {
                    printf("erreur, la base de donnees ne contient pas autant d'utilisateur\n utilisateur %d, maxutilisateur %d\n",utilindex,TAILLE_TABS);
                    break;
                }
                print1Util(utilindex);
                printf("voulez vous supprimer l'utilisateur ?\n \t1)Oui\n \t2)Non\n");
                scanf("%d",&choixgest);

                if (choixgest==1)
                {
                    sauve.tabutil[utilindex].abonnement=0;
                    print1Util(utilindex);

                }
                else if (choixgest==2)
                {
                    //printf("%s-%d\n",__FILE__,__LINE__);
                    //return 0;

                }
                else
                {
                    //printf("%s-%d\n",__FILE__,__LINE__);
                    printUtil();//statistiques
                    printStation();
                }


            }
            else
            {
                //printf("%s-%d\n",__FILE__,__LINE__);
                printUtil();//statistiques
                printStation();
            }

        }
        //printf("%s-%d\n",__FILE__,__LINE__);

    }
    while ( cpt!=3);
    SaveState(sauve); // a la sortie on sauve dans un fichier Savefile.bin


    //printf("%s-%d\n",__FILE__,__LINE__);
}
