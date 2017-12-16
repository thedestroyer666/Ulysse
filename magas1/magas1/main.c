/*MARIACHER Ulysse
OSSART Julie  14/12/17*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NB_LETTRES 40

struct magasin
{
    char nomRayon[NB_LETTRES+1]; //Nom du rayon
    char nomProduit[NB_LETTRES+1]; //Nom du produit
    double prix; //prix du produit
};
struct panier
{
    char nomRayon[NB_LETTRES+1]; //Nom du  rayon
    char nomProduit[NB_LETTRES+1]; //Nom du produit
    int quantite; //Quantité demandée
    double prixunitaire; //Prix d'un produit
    double prixtotalrayon; //Prix total au sein du même rayon
    double prixtotal;//prix total des produits similaires
};

int main()
{
    int nbre=6;
    int cpt; //compteur
    int cpt2;
    int condition; //condition pour l'achat de produits
    double total; //le prix à payer
    struct magasin tabMagasin[]= {{"Alcool","Vodka",10.20},{"Alcool","Whisky",20.10},
        {"Gateaux","Kinder Country",3.60},{"Gateaux","Gerble",6.66},{"Poissons","Cabillaud",45.62},{"Poissons","Truite saumonnee",36.70}
    };

    struct panier tabPanier[100];

    printf("\t\tBienvenue chez A&G&P.\n \n");
    printf("\tVoici la liste de nos produits.\n \n");
    total=0;
    for(cpt=0; cpt<nbre; cpt++)
    {
        printf("%d\t", cpt+1);
        printf("%-10s %20s %10.2f\n",tabMagasin[cpt].nomRayon, tabMagasin[cpt].nomProduit, tabMagasin[cpt].prix);
    }
    condition=0;
    cpt=0;
    cpt2=0;
    while (condition==0)
    {
        printf("\nChoisissez vos produits, entrez le numero de la ligne.\n");

        scanf("%d",&cpt);

        cpt=cpt-1;

        strcpy(tabPanier[cpt2].nomRayon,tabMagasin[cpt].nomRayon);

        strcpy(tabPanier[cpt2].nomProduit,tabMagasin[cpt].nomProduit);

        tabPanier[cpt2].prixunitaire=tabMagasin[cpt].prix;

        printf("Choisissez la quantite.\n");

        scanf("%d",&tabPanier[cpt2].quantite);

        tabPanier[cpt2].prixtotal=tabPanier[cpt2].prixunitaire*tabPanier[cpt2].quantite;

        printf("\nVoulez vous choisir d'autres produits ? Si oui tapez 0, sinon tapez un autre chiffre.\n");

        scanf("%d",&condition);



        cpt2++;
    }
    int indAsc, indDesc; //indices de parcours ascendant et descendant
    char tampon[NB_LETTRES+1];
    //struct panier elt;
    //tant qu'il reste des éléments à trier faire
    for(indAsc=0; indAsc<cpt2-1; indAsc++)
    {
        //se placer sur la dernière case du tableau
        //Tant que l'on n'a pas atteint la partie déjà triée
        //(parcours de droite à gauche) faire
        for(indDesc=cpt2-1; indDesc>=indAsc+1; indDesc--)
        {
            //Permuter toute paire d'éléments consécutifs non ordonnés
            if (strcmp(tabPanier[indDesc].nomRayon,tabPanier[indDesc-1].nomRayon))
            {
                strcpy((char *)tampon,(char *)tabPanier[indDesc].nomRayon);
                strcpy((char *)tabPanier[indDesc].nomRayon,(char *)tabPanier[indDesc-1].nomRayon);
                strcpy((char *)tabPanier[indDesc-1].nomRayon,(char *)tampon);
            }
        }
    }

    int indAsc2, indDesc2; //indices de parcours ascendant et descendant
    double tampon2;
    //struct panier elt;
    //tant qu'il reste des éléments à trier faire
    for(indAsc2=0; indAsc2<cpt2-1; indAsc2++)
    {
        //se placer sur la dernière case du tableau
        //Tant que l'on n'a pas atteint la partie déjà triée
        //(parcours de droite à gauche) faire
        for(indDesc2=cpt2-1; indDesc2>=indAsc+1; indDesc2--)
        {
            //Permuter toute paire d'éléments consécutifs non ordonnés
            if (tabPanier[indDesc2].prixunitaire<tabPanier[indDesc2-1].prixunitaire)
            {
                tampon2=tabPanier[indDesc2].prixunitaire;
                tabPanier[indDesc2].prixunitaire=tabPanier[indDesc2-1].prixunitaire;
                tabPanier[indDesc-1].prixunitaire=tampon2;
            }
        }
    }


    for(cpt=0; cpt<cpt2; cpt++)
    {
        printf("%d\t", cpt+1);
        printf("%-10s %20s %10.2f\n",tabPanier[cpt].nomRayon, tabPanier[cpt].nomProduit, tabPanier[cpt].prixunitaire);
        total=tabPanier[cpt].prixtotal+total;
    }

    printf("\nle total a payer est de %.2f euros\n ",total);

    return 0;
}
