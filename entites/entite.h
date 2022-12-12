#include <stdlib.h>
#include <stdio.h>
typedef struct  
{
int jj;
int mm;
int aa;
}date;
typedef struct
{
char nom[20];
char prenom[20];
int cin;
int id;
char sexe[10];
char nationalite[25];
date date_de_naissance;
char adresse[30];
char role [30];
int vote;
int mot_de_passe;
}Utilisateur;

float TVB(char * filename);
//float agemoy(char * filename);
