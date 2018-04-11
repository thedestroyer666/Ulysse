#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<time.h>
#include "SousProgrammes.h"


int main()
{
    struct artiste tabArtistes[50];//on d�clare les informations de l'artiste
    struct producteur tabProducteurs[50]; //on d�clare les informations du producteur
    struct projet tabProjets[100]; //on d�clare les informations sur les projets
    struct investissement tabInvestissements[100];//on d�clare les informations sur les investissements
    int nbArtistes=0; //nombre d'artistes initialis� � 0
    int nbProducteurs=0; //nombre de producteurs initialis� � 0
    int nbProjets=0; //nombre de projets initialis� � 0
    struct artiste artisteConnecte;
    struct producteur producteurConnecte;

    int a; //l'utilisateur a un compte ou pas
    int b; //l'utilisateur veut s'inscrire ou non
    int c; //l'utilisateur est un artiste ou un producteur
    int d; //Les projets que le visiteur veux voir
    int e; //options de l'artiste ou du producteur
    int f; //options de l'artiste
    int g; //options du producteur
    int h; //l'utilisateur veut continuer ou quitter
    int indAsc, indDesc; //Indices de parcours ascendants et descendants pour le tri du tableau
    struct projet tampon;
    int cpt; //compteur

    COULEUR(0,7);
    printf("\n                           BIENVENUE SUR SEEZER  \n ",7);
    printf("\n                       Le label de musique participatif :) \n");
    a=666;
    b=666;
    c=666;
    d=666;
    e=666;
    f=666;
    g=666;
    h=666;

    while(a!=0 && a!=1)
    {
        printf("\n\n   Avez vous deja un compte ? 0: oui 1: non\n");
        scanf("%d",&a);
    }
    if(a==0) //si l'utilisateur  a d�j� un compte
    {
        /*printf("Quel est votre adresse mail ?\n"); //Demander son adresse mail et son mot de passe
        scanf("%s",&);
        printf("Entrez votre mot de passe\n.");
        scanf("%s",&);
        //afficher les informations du compte
        //artiste
        //ou producteur*/

    }
    else if(a==1) //Si l'utilisateur n'a pas encore de compte
    {
        while(b!=0 && b!=1)
        {
            printf("\n  Voulez-vous vous inscrire ? 0: Oui 1: Non\n");
            scanf("%d",&b);

        }
        if(b==0) //Si l'utilisateur veut s'inscrire
        {
            while(c!=0 && c!=1)
            {
                printf("\nEtes vous artiste ou producteur ? 0: Artiste 1: Producteur\n");//artiste ou producteur ?
                scanf("%d",&c);


            }
            if(c==0)//si artiste
            {
                printf("Quel nom d'artiste voulez-vous utiliser?\n");
                scanf("%s",&(tabArtistes[nbArtistes].nom));
                printf("Quelle est votre adresse mail ?\n");
                scanf("%s",&(tabArtistes[nbArtistes].adressemail));
                printf("Choisissez un mot de passe.\n");
                scanf("%s",&(tabArtistes[nbArtistes].mdp));
                tabArtistes[nbArtistes].nbreProjets=0;//on initialise le nombre de projet � 0
                nbArtistes=nbArtistes+1;//on rajoute 1 au nombre d'artistes
                SAUVEGARDE(tabArtistes,nbArtistes);//on sauvegarde le nouvel artiste
                e=0;
            }


            if(c==1) //si producteur
            {
                printf("Quel nom de producteur voulez-vous utiliser?\n");
                scanf("%s",&(tabProducteurs[nbProducteurs].nom));
                printf("Quelle est votre adresse mail ?\n");
                scanf("%s",&(tabProducteurs[nbProducteurs].adressemail));
                printf("Choisissez un mot de passe.\n");
                scanf("%s",(&tabProducteurs[nbProducteurs].mdp));
                nbProducteurs=nbProducteurs+1;//on rajoute 1 au nombre de producteurs
                SAUVEGARDE1(tabProducteurs,nbProducteurs);//on sauvegarde le nouveau producteur
                e=1;
            }
        }
        if(b==1) //si il ne veut pas s'inscrire
        {
            while(d!=1 && d!=2 && d!=3 && d!=4)
            {
                printf("\nBienvenue sur la plateforme de recherche de projet.\n  Quels projets voulez vous voir?\n 1:Les 5 derniers projets \n 2:Les projets les plus chers\n 3:Les projets les moins chers\n 4:Quitter\n");
                scanf("%d",&d);
            }
            if(d==1)//Afficher les 5 derniers projets
            {
                //Trier les projets par date


                cpt=0;
                while(cpt<nbProjets)  //Affichage du tableau des projets
                {
                    printf("%s\n",tabProjets[cpt].nomprojet);
                    printf("%s\n",tabProjets[cpt].adressemail);
                    printf("%s\n",tabProjets[cpt].date);
                    printf("%f\n",tabProjets[cpt].financement);
                    printf("%f\n",tabProjets[cpt].sommeversee);
                    printf("%s\n",tabProjets[cpt].listefinanciers);
                    printf("%s\n",tabProjets[cpt].description);
                    printf("%d\n",tabProjets[cpt].etatavancement);
                    cpt++;


                }
            }
            else if(d==2)
            {
                //Afficher les projets du plus cher au moins cher
                //Trier les projets: prix d�croissants
                //Tant qu'il reste des �l�ments � trier faire
                for(indAsc=0; indAsc<nbProjets-1; indAsc+1)
                {
                    //Se placer sur la derni�re case du tableau
                    //Tant que l'on a pas atteint la partie du tableau qui n'a pas �t� tri�e(parcours de gauche � droite) faire
                    for(indDesc=nbProjets-1; indDesc>=indAsc+1; indDesc--)
                    {
                        if(tabProjets[indDesc].financement>tabProjets[indDesc-1].financement)
                        {
                            tampon=tabProjets[indDesc];
                            tabProjets[indDesc]=tabProjets[indDesc-1];
                            tabProjets[indDesc-1]=tampon;
                        }
                    }
                }
                //Affichage
                cpt=0;
                while(cpt<nbProjets)  //Affichage du tableau des projets
                {
                    printf("%s\n",tabProjets[cpt].nomprojet);
                    printf("%s\n",tabProjets[cpt].adressemail);
                    printf("%s\n",tabProjets[cpt].date);
                    printf("%f\n",tabProjets[cpt].financement);
                    printf("%f\n",tabProjets[cpt].sommeversee);
                    printf("%s\n",tabProjets[cpt].listefinanciers);
                    printf("%s\n",tabProjets[cpt].description);
                    printf("%d\n",tabProjets[cpt].etatavancement);
                    cpt++;
                }
            }
                else if(d==3)
                {
                    //Afficher les projets du moins cher au plus cher
                    //Trier les projets: prix croissants
                    //Tant qu'il reste des �l�ments � trier faire
                    for(indAsc=0; indAsc<nbProjets-1; indAsc+1)
                    {
                        //Se placer sur la derni�re case du tableau
                        //Tant que l'on a pas atteint la partie du tableau qui n'a pas �t� tri�e(parcours de gauche � droite) faire
                        for(indDesc=nbProjets-1; indDesc>=indAsc+1; indDesc--)
                        {
                            if(tabProjets[indDesc].financement<tabProjets[indDesc-1].financement)
                            {
                                tampon=tabProjets[indDesc];
                                tabProjets[indDesc]=tabProjets[indDesc-1];
                                tabProjets[indDesc-1]=tampon;
                            }
                        }
                    }
                    //Affichage
                    cpt=0;
                    while(cpt<nbProjets)  //Affichage du tableau des projets
                    {
                        printf("%s\n",tabProjets[cpt].nomprojet);
                        printf("%s\n",tabProjets[cpt].adressemail);
                        printf("%s\n",tabProjets[cpt].date);
                        printf("%f\n",tabProjets[cpt].financement);
                        printf("%f\n",tabProjets[cpt].sommeversee);
                        printf("%s\n",tabProjets[cpt].listefinanciers);
                        printf("%s\n",tabProjets[cpt].description);
                        printf("%d\n",tabProjets[cpt].etatavancement);
                        cpt++;
                    }
                }
                    else if(d==4)
                    {
                        //Terminer le programme

                    }
                }
            }
            if(e==0) //options de l'artiste
            {
                while(h!=1)
                {
                    while(f!=0 && f!=1 && f!=2 && f!=3)
                    {
                        printf("\n\n Que voulez-vous faire ?\n  0:Proposer un projet\n   1:Consulter l'etat de mes projets\n");
                        scanf("%d",&f);
                    }
                    if(f==0)//proposer un projet
                    {
                        //descritption
                        //date
                        //montant

                    }
                    else if(f==1)//voir l'�tat de ses projets
                    {
                        //liste contributeurs+leurs contributions
                        //total

                    }
                    while(h!=1 && h!=0)
                    {
                        printf("\nVoulez vous poursuivre vos recherches ? 0:Oui 1:Non\n"); //continuer ou quitter
                        scanf("%d",&h);
                    }


                }
            }
            else if(e==1) //options du producteur
            {
                while(h!=1)
                {
                    while(g!=0 && g!=1 && g!=2 && g!=3)
                    {
                        printf("\n\n   Que voulez-vous faire ? \n0:Investir dans un projet \n1:Voir la liste des projets dans lesquels vous avez investis" );
                        printf("   \n2:Voir la somme totale que vous avez investie\n");
                        scanf("%d",&g);
                    }
                    if(g==0)//investir dans un projet
                    {
                        //choisir un projet
                        //mettre une somme
                    }

                    else if(g==1)//liste des projets dans lesquels ils ont investis
                    {
                        //afficher la liste des projets et les diff�rents totaux

                    }
                    else if(g==2)//afficher la somme totale investie
                    {

                    }
                    while(h!=1 && h!=0)
                    {
                        printf("\nVoulez vous poursuivre vos recherches ? 0:Oui 1:Non\n"); //continuer ou quitter
                        scanf("%d",&h);
                    }
                }
            }

            return 0;
        }
