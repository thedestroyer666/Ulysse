/*Sous tableaux*/
#include <stdio.h>
#include <stdlib.h>
void AFFICHER_TABLEAU_DYN(int*tab,int taille)
{
    int cpt;
    for(cpt=0; cpt<taille; cpt++)    //Affichage tableau
    {
        printf("%d\n",*(tab+cpt));
    }
}

void REMPLIR_TABLEAU_DYN(int **tab, int *taille)
{
    int cpt;
    printf("Taille du tableau ?\n");  //demander une taille
    scanf("%d",&*taille);
    while (taille<=0)     //Vérification de taille de tableau >0
    {
        printf("un tableau doit avoir une taille positive\nTaille ?\n");
        scanf("%d",&*taille);
    }


    *tab=malloc((*taille)*sizeof(int)); //nombre d'octets occupés par un -->sizeof(...)
    if(*tab==NULL)
    {
        printf("Impossible de cr%cer le tableau \n",130); //Vérification de création du tableau
        exit(0);
    }
    for(cpt=0; cpt<*taille; cpt++)       //remplir le tableau
    {
        printf("Quel est l'%clement %d du tableau?\n",130,cpt+1);
        scanf("%d",&*((*tab)+cpt)); //ou "%d",&tab[cpt]
    }
}

void SAUVEGARDE(int *tab,  int taille)
{
    int cpt;
    FILE *fichier;
    char nomFichier[100];
    printf("Nom du fichier ?\n");
    scanf("%s",&nomFichier);
    strcat(nomFichier,".txt"); //rajouter l'extension ".txt")
    fichier=fopen(nomFichier,"w");  //pour ouvrir un fichier en écriture
    fprintf(fichier,"%d\n",taille);
    for(cpt=0; cpt<taille; cpt++)   //remplir le fichier
    {
        fprintf(fichier,"%d\n",tab[cpt]);
    }
    fclose(fichier); //fermer le fichier
}
void CHARGEMENT(int**tab,int*taille) {
    int cpt;
    FILE*fichier;
    char nomFichier [100];
    printf("Nom du fichier ?\n");
    scanf("%s",&nomFichier);
    strcat(nomFichier,".txt"); //rajouter l'extension du fichier
    fichier=fopen(nomFichier,"r"); //pour ouvrir un fichier en lecture
    if(fichier==NULL){printf("le fichier n'existe pas\n");
    *tab=NULL;
    }
    else{fscanf(fichier,"%d",&*taille);
    *tab=malloc((*taille)*sizeof(int));
    for(cpt=0;cpt<taille;cpt++){
        fscanf(fichier,"%d",&(*tab)[cpt]);
    }
    fclose(fichier);
    }
}
