#include <windows.h>
#include "SousProgrammes.h"

void COULEUR(int texte,int fond)
{
    //0 noir 15 blanc
    //1-bleu fonc� 2-vert fonc� 3-turquoise fonc� 4-rouge fonc�
    //5-violet fonc� 6-vert kaki 7-gris clair 8-gris fonc�
    //9-bleu fluo 10-vert fluo 11-turquoise fluo
    //12-rouge fluo 13-violet fluo 14-jaune
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,fond*16+texte);
}
