#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<time.h>
#include "SousProgrammes.h"


int main()
{
    struct artiste tabArtistes[50];//on déclare les informations de l'artiste
    struct producteur tabProducteurs[50]; //on déclare les informations du producteur
    struct projet tabProjets[100]; //on déclare les informations sur les projets
    struct investissement tabInvestissements[100];//on déclare les informations sur les investissements
    int nbArtistes=0; //nombre d'artistes initialisé à 0
    int nbProducteurs=0; //nombre de producteurs initialisé à 0
    int nbProjets=0; //nombre de projets initialisé à 0

    int a; //l'utilisateur a un compte ou pas
    int z; //l'utlsateur a déjà un compte mas il est artiste ou producteur
    int b; //l'utilisateur veut s'inscrire ou non
    int c; //l'utilisateur est un artiste ou un producteur
    int d; //Les projets que le visiteur veux voir
    int e; //options de l'artiste ou du producteur
    int f; //options de l'artiste
    int g; //options du producteur
    int h; //l'utilisateur veut continuer ou quitter
    int i; //vérification de l'arobaz dans le mail de l'utilisateur
    int j;//compteur investissements du producteur
    int indAsc, indDesc; //Indices de parcours ascendants et descendants pour le tri du tableau
    struct projet tampon;
    int cpt; //compteur
    int artisteco;//index artiste connecté
    int producteurco;//index producteur connecté
    int trouve;// trouve t'on un compte et mot de passe correspondant
    char emailTape[NB_LETTRES+1], mdpTape[NB_LETTRES+1];
    CHARGEMENT ( tabArtistes, &nbArtistes);
    CHARGEMENT1 ( tabProducteurs, &nbProducteurs);
    //printf("nbProjets=%d\n",nbProjets);
    CHARGEMENT2 ( tabProjets, &nbProjets);
    //printf("nbProjets=%d\n",nbProjets);
    COULEUR(0,7);
    printf("\n                           BIENVENUE SUR SEEZER  \n ",7);
    printf("\n                       Le label de musique participatif :) \n");
    a=666;//on initialise toute nos variables à une valeur quelconque
    z=666;
    b=666;
    c=666;
    d=666;
    e=666;
    f=666;
    g=666;
    h=666;
    i=666;


    while(a!=0 && a!=1)
    {
        printf("\n\n   Avez vous deja un compte ? 0: oui 1: non\n");
        scanf("%d",&a);
    }
    if(a==0) //si l'utilisateur  a déjà un compte
    {
        while(z!=0 && z!=1)//artiste ou producteur ?
        {
            printf("\n\n   Etes vous deja artiste ou producteur ? 0: artiste 1: producteur\n");
            scanf("%d",&z);
        }
        if(z==0)
        {
            printf("Quel est votre adresse mail ?\n"); //Demander son adresse mail et son mot de passe
            scanf("%s",&emailTape);
            printf("Entrez votre mot de passe\n");
            scanf("%s",&mdpTape);


            cpt=0;
            trouve=0;
            while (cpt<nbArtistes && trouve==0)
            {
                if (strcmp(emailTape,tabArtistes[cpt].adressemail)==0)
                {
                    trouve=1;
                    artisteco=cpt;
                }
                else
                {
                    cpt++;
                }

            }
            if (trouve==1)
            {
                if (strcmp(mdpTape,tabArtistes[cpt].mdp)==0)
                {
                    trouve=2;
                }
            }
            if(trouve==0)
            {
                printf("Adresse mail ou mot de passe errone\n");
            }
            if (trouve==2)
            {
                e=0;//on envoie l'utilisateur sur les choix de l'artiste
            }
        }
        if (z==1) //ou producteur
        {
            printf("Quel est votre adresse mail ?\n"); //Demander son adresse mail et son mot de passe
            scanf("%s",&emailTape);
            printf("Entrez votre mot de passe\n");
            scanf("%s",&mdpTape);


            cpt=0;
            trouve=0;
            while (cpt<nbProducteurs && trouve==0)
            {
                if (strcmp(emailTape,tabProducteurs[cpt].adressemail)==0)
                {
                    trouve=1;
                    producteurco=cpt;
                }
                else
                {
                    cpt++;
                }
            }
            if (trouve==1)
            {
                if (strcmp(mdpTape,tabProducteurs[cpt].mdp)==0)
                {
                    trouve=2;
                }
            }
            if(trouve==0)
            {
                printf("Adresse mail ou mot de passe errone\n");
            }
            if (trouve==2)
            {
                e=1;//on envoie l'utilisateur sur les choix du producteur
            }
        }

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
                do
                {
                    printf("Quelle est votre adresse mail ?\n");
                    scanf("%s",&(tabArtistes[nbArtistes].adressemail));
                    i=(strchr((tabArtistes[nbArtistes].adressemail), 64));
                    if(i==NULL)
                    {
                        printf("Erreur adresse mail invalide\n");
                    }
                }
                while(i==NULL);

                printf("Choisissez un mot de passe.\n");
                scanf("%s",&(tabArtistes[nbArtistes].mdp));
                tabArtistes[nbArtistes].nbreProjets=0;//on initialise le nombre de projet à 0
                nbArtistes=nbArtistes+1;//on rajoute 1 au nombre d'artistes
                artisteco=nbArtistes;
                SAUVEGARDE(tabArtistes,nbArtistes);//on sauvegarde le nouvel artiste
                e=0;
            }


            if(c==1) //si producteur
            {
                printf("Quel nom de producteur voulez-vous utiliser?\n");
                scanf("%s",&(tabProducteurs[nbProducteurs].nom));
                do
                {
                    printf("Quelle est votre adresse mail ?\n");
                    scanf("%s",&(tabProducteurs[nbProducteurs].adressemail));
                    i=(strchr((tabProducteurs[nbProducteurs].adressemail), 64));
                    if(i==NULL)
                    {
                        printf("erreur adresse mail invalide\n");
                    }
                }
                while(i==NULL);
                printf("Choisissez un mot de passe.\n");
                scanf("%s",(&tabProducteurs[nbProducteurs].mdp));
                tabProducteurs[nbProducteurs].nbreArgent=0;
                nbProducteurs=nbProducteurs+1;//on rajoute 1 au nombre de producteurs
                SAUVEGARDE1(tabProducteurs,nbProducteurs);//on sauvegarde le nouveau producteur
                producteurco=nbProducteurs;
                e=1;
            }
        }
        if(b==1) //si il ne veut pas s'inscrire
        {
            while(d!=1 && d!=2 && d!=3)
            {
                printf("\nBienvenue sur la plateforme de recherche de projet.\n  Quels projets voulez vous voir?\n 1:Les projets les plus chers\n 2:Les projets les moins chers\n 3:Quitter\n");
                scanf("%d",&d);
            }
            if(d==1)
            {
                //Afficher les projets du plus cher au moins cher
                //Trier les projets: prix décroissantsafficheProjet(tabProjets,cpt);
                //Tant qu'il reste des éléments à trier faire
                for(indAsc=0; indAsc<nbProjets-1; indAsc+1)
                {
                    //Se placer sur la dernière case du tableau
                    //Tant que l'on a pas atteint la partie du tableau qui n'a pas été triée(parcours de gauche à droite) faire
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
                    afficheProjet(tabProjets,cpt);
                    cpt++;
                }
            }
            else if(d==2)
            {
                //Afficher les projets du moins cher au plus cher
                //Trier les projets: prix croissants
                //Tant qu'il reste des éléments à trier faire
                for(indAsc=0; indAsc<nbProjets-1; indAsc+1)
                {
                    //Se placer sur la dernière case du tableau
                    //Tant que l'on a pas atteint la partie du tableau qui n'a pas été triée(parcours de gauche à droite) faire
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
                    afficheProjet(tabProjets,cpt);
                    cpt++;
                }
            }
            else if(d==3)
            {
                printf("\n Merci de votre visite !\n");
                return 0;//Terminer le programme

            }
        }
    }
    if(e==0) //options de l'artiste
    {
        //printf("%d h=%d f=%d e=%d\n",__LINE__,h,f,e);
        while(h!=1)
        {
            //printf("%d h=%d f=%d e=%d\n",__LINE__,h,f,e);
            while(f!=0 && f!=1)
            {
                //printf("%d h=%d f=%d e=%d\n",__LINE__,h,f,e);
                printf("\n\n Que voulez-vous faire ?\n   0:Proposer un projet\n   1:Consulter l'etat de mes projets\n");
                scanf("%d",&f);
            }
            if(f==0)//proposer un projet
            {
                f=666;
                strcpy(tabProjets[nbProjets].adressemail,tabArtistes[artisteco].adressemail);
                printf("\n Rentrez le nom de votre projet \n");
                scanf("%s",& (tabProjets[nbProjets].nomprojet));
                printf("\n Rentrez la description de votre projet \n");//descritption
                scanf("%s",& (tabProjets[nbProjets].description));
                printf("\n Rentrez une date \n");//date
                scanf("%s",& (tabProjets[nbProjets].date));
                printf("\n Rentrez un montant \n");//montant
                scanf("%f",& (tabProjets[nbProjets].financement));
                strcpy(tabProjets[nbProjets].listefinanciers,"listefinanciers");
                //printf("%s-%d %s-%s-%s\n",__FILE__,__LINE__,tabProjets[nbProjets].nomprojet,tabProjets[nbProjets].adressemail,tabArtistes[artisteco].adressemail);
                nbProjets++;
                SAUVEGARDE2(tabProjets,nbProjets);
                printf("nbProjets=%d\n",nbProjets);
            }
            else if(f==1)//voir l'état de ses projets
            {
                cpt=0;
                f=666;
                printf("nbProjets=%d\n",nbProjets);
                while(cpt<nbProjets)  //Affichage du tableau des projets
                {
                    //liste contributeurs+leurs contributions
                    //printf("cpt=%d\n",cpt);
                    //printf("%d %s vs %s\n",__LINE__,tabProjets[cpt].adressemail,tabArtistes[artisteco].adressemail);
                    if(strcmp(tabProjets[cpt].adressemail,tabArtistes[artisteco].adressemail)==0)
                    {
                        afficheProjet(tabProjets,cpt);
                    }
                    else
                    {
                        //printf("%d mail correspond pas\n",__LINE__);
                    }
                    cpt++;
                    //printf("%s-%d\n",__FILE__,__LINE__);

                }
                //printf("%s-%d\n",__FILE__,__LINE__);

            }
            //printf("%d h=%d f=%d e=%d\n",__LINE__,h,f,e);
            h=666;
            //printf("%d h=%d f=%d e=%d\n",__LINE__,h,f,e);
            while(h!=1 && h!=0)
            {
                //printf("%d h=%d f=%d e=%d\n",__LINE__,h,f,e);
                printf("\nVoulez vous poursuivre vos recherches ? 0:Oui 1:Non\n"); //continuer ou quitter
                scanf("%d",&h);
            }
            //printf("%d h=%d f=%d e=%d\n",__LINE__,h,f,e);
        }
    }
    else if(e==1) //options du producteur
    {
        while(h!=1)
        {

            do
            {
                printf("\n\n   Que voulez-vous faire ? \n   0:Investir dans un projet \n   1:Voir la liste des projets dans lesquels vous avez investis\n " );
                scanf("%d",& g);
            }
            while(g<0 || g>1);
            printf("%s-%d %d\n",__FILE__,__LINE__,g);
            if(g==0)//investir dans un projet
            {
                printf("%s-%d\n",__FILE__,__LINE__);
                g=666;
                cpt=0;
                float s;//somme versée
                printf("%s-%d %d/%d\n",__FILE__,__LINE__,cpt,nbProjets);
                while(cpt<nbProjets)  //Affichage du tableau des projets
                {
                    afficheProjet(tabProjets,cpt);
                    cpt++;
                }
                printf("%s-%d\n",__FILE__,__LINE__);
                printf("%s-%d\n",__FILE__,__LINE__);
                cpt=666;
                printf("%s-%d %d %d\n",__FILE__,__LINE__,cpt,nbProjets);
                while(cpt<0 || cpt>nbProjets)
                {
                    printf("\nTapez le numero du projet dans lequel vous voulez investir\n");//choisir un projet
                    scanf("%d",& cpt);
                }
                s=666;
                printf("%s-%d %d %d %f\n",__FILE__,__LINE__,cpt,nbProjets, s);
                printf("%s-%d %f/%f\n",__FILE__,__LINE__,s,tabProjets[cpt].financement);
                while(s<0 || s>tabProjets[cpt].financement/*financement du projet*/)
                {
                    printf("\nQuel montant souhaitez-vous investir?\n");//mettre une somme
                    scanf("%f",& s);
                    printf("%s-%d %f/%f\n",__FILE__,__LINE__,s,tabProjets[cpt].financement);
                    /*if(s>tabProjets[cpt].financement)
                    {
                        printf("\nla somme est trop importante, veuillez réduire votre investissement\n");
                    }*/
                }
                printf("%s-%d %f\n",__FILE__,__LINE__,s);
                tabProducteurs[producteurco].nbreArgent=tabProducteurs[producteurco].nbreArgent+1;//nombre d'nvestssement du producteur
                j= tabProducteurs[producteurco].nbreArgent;
                printf("%s-%d %d\n",__FILE__,__LINE__,j);
                tabProducteurs[producteurco].nbreArgent=j;
                tabProjets[cpt].sommeversee=tabProjets[cpt].sommeversee+s;
                printf("%s-%d %f\n",__FILE__,__LINE__,tabProjets[cpt].sommeversee);
                tabProducteurs[producteurco].tabInvest[j].sommeproducteur=s;
                printf("%s-%d %f\n",__FILE__,__LINE__,s);
                tabProjets[cpt].etatavancement=tabProjets[cpt].sommeversee*100/tabProjets[cpt].financement;
                printf("%s-%d %f\n",__FILE__,__LINE__,s);
                strcpy(tabProjets[nbProjets].nomprojet,tabProducteurs[producteurco].tabInvest[j].nomprojet);
                afficheProjet(tabProjets,cpt);
            }

            else if(g==1)//liste des projets dans lesquels ils ont investis
            {
                g=666;
                j=0;
                for(j=1; j<tabProducteurs[producteurco].nbreArgent; j++) //afficher la liste des projets et les différents totaux et avancement
                {
                    printf("Nom du projet: %s\n",tabProducteurs[producteurco].tabInvest[j].nomprojet);
                    printf("Somme allouee: %f\n",tabProducteurs[producteurco].tabInvest[j].sommeproducteur);
                }
            }
            h=666;
            while(h!=1 && h!=0)
            {
                printf("\nVoulez vous poursuivre vos recherches ? 0:Oui 1:Non\n"); //continuer ou quitter
                scanf("%d",&h);
            }
        }
    }

    printf("\nA bientot :)\n");
    return 0;
}
