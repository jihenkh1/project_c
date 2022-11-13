#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include<stdio.h>
typedef struct  
{
int jour ;
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
int ajouter (char *, election);
int modifier(char *, int ,election );
int supprimer(char *, int);
election chercher(char *, int);
#endif
