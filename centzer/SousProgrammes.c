#include <windows.h>
#include "SousProgrammes.h"

void COULEUR(int texte,int fond)
{
    //0 noir 15 blanc
    //1-bleu foncé 2-vert foncé 3-turquoise foncé 4-rouge foncé
    //5-violet foncé 6-vert kaki 7-gris clair 8-gris foncé
    //9-bleu fluo 10-vert fluo 11-turquoise fluo
    //12-rouge fluo 13-violet fluo 14-jaune
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,fond*16+texte);
}
