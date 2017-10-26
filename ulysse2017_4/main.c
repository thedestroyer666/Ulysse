/*Camille Fallion
Ulysse Mariacher
11/10/2017*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nombre;// le nombre que l'on doit vérifier
    int dividende,quotient,reste,resteprecedent;//le dividende, le quotient, les restes de la division par 10
    int resultat;//1 vrai, 0 faux
    int verif;

    //Initialisation des données



//Demander et lire l'entier, avec vérification
    do
    {
        printf("entrer l'entier\n");
        scanf("%d",&nombre);
        if(nombre<0)
        {
            verif=1;
            printf("erreur recommencer\n");
        }
        else
        {
            verif=0;
        }

    }
    while (verif=1);
//affecter le nombre au dividende
dividende=nombre;
//diviser le dividende par 10
// affecter le quotient au dividende
quotient=dividende/10;
// Traitement
// tant que le quotient n'est pas egal a 0 faire
if (quotient!=0){
// diviser le dividende par 10
    reste=dividende%10;
// si le 1er reste de la division est plus grand que le reste precedent alors affecter faux au resultat
//sinon
//affecter le reste au reste précédent
// affecter le quotient au dividende
//Affichage des résultats

//si le reste est vrai
//alors afficher "le nombre est bien ordonné"
//Sinon affcicher "le nombre n'est pas bien ordonné"
    return 0;
}}
