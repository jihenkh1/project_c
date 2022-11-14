#include <stdlib.h>
#include <stdio.h>
typedef struct  
{
int jour;
int mois;
int annee;
}date;
typedef struct  
{
date dateElect;
int idEl;
int nbH;
int nbC;
char muni[50];
}election ;

void saisir(election* e);
int ajouter (char filename[], election E1);
/*int modifier(char *, int ,election );
int supprimer(char *, int);
election chercher(char *, int);*/

