#include<stdio.h>
#include<stdlib.h>
#include "functions.h"

int main()
{
election E1 ={{1,10,22},1,8,100,"x"},E2={{2,11,23},2,5,200,"y"},E3;
int x=ajouter("election.txt",E1);

if(x==1)
printf("\najout d election avec succes");
else printf("\nechec ajout");

x=modifier("election.txt",1,E2);
if(x==1)
printf("\nmodification de l election avec succes");
else printf("\nechec modification");
x=supprimer("election.txt",1);
if(x==1)
printf("\nsuppression de point avec succes");
else printf("\nechec suppression");
E3=chercher("election.txt",3);
if(E3.idEl==-1)
printf("\nintrouvable");
return 0;
}
