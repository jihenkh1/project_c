#include "entite.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//calcul du taux des votes blancs
float TVB(char *filename)
{
	Utilisateur u;
	int nb_blancs=0,nb_total=0;
	float taux;
	FILE *f=fopen(filename,"r");
	if(f!=NULL)
	while(fscanf(f,"%s %s %d %d %s %s %d %d %d %s %s %d %d \n",u.nom,u.prenom,&u.cin,&u.id,u.sexe,u.nationalite,&u.date_de_naissance.jj,&u.date_de_naissance.mm,&u.date_de_naissance.aa,u.adresse,u.role,&u.vote,&u.mot_de_passe)!=EOF)
	if(u.vote==0)
	nb_blancs++;
	if(u.vote!=-1)
	nb_total+=1;
	taux=nb_blancs/nb_total;
	fclose(f);
	return taux;
}

//calcul de l'age moyen des electeurs participants
/*float agemoy(char *filename)
{
Utilisateur u;
int nb_elec;
int age;
int s=0;
float moyAge; 

FILE *f=fopen(filename,"r");
	if(f!=NULL)
	
	while(fscanf(f,"%s %s %d %d %s %s %d %d %d %s %s %d %d \n",u.nom,u.prenom,&u.cin,&u.id,u.sexe,u.nationalite,&u.date_de_naissance.jj,&u.date_de_naissance.mm,&u.date_de_naissance.aa,u.adresse,u.role,&u.vote,&u.mot_de_passe)!=EOF)

	
	if(strcmp(u.role,"1")!=0)
	
	nb_elec++;
	age=2022-u.date_de_naissance.aa;
	s=s+age;
	
moyAge=s/nb_elec;
return moyAge;
}*/
