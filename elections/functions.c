#include "functions.h"

void saisir(election* e){
printf("donner la date de l'élection");
scanf("%d %d %d", &(e->dateElect.jour), &(e->dateElect.mois), &(e->dateElect.annee));
printf("donner l'identifiant de l'élection");
scanf("%d", &e->idEl);
printf("donner le nombre d'habitants");
scanf("%d", &e->nbH);
printf("donner le nombre de conseillers");
scanf("%d", &e->nbC);
printf("donner la municipalité");
scanf("%s", e->muni);
}
int ajouter (char filename[], election E)
{
  FILE* f=fopen(filename,"a");
if(f!=NULL)
{
fprintf(f,"%d %d-%d-%d %d %d  %s\n",E.idEl ,E.dateElect.jour,E.dateElect.mois,E.dateElect.annee,E.nbH,E.nbC ,E.muni );
fclose(f);
return 1;
}
else return 0;
}
/*
int modifier(char * filename,int idEl,election new)
{ FILE *f1=NULL, *f2=NULL;
f1 =fopen(filename, "r");

f2=fopen("new.txt", "w");
election E;
int test=-1;
if(f1!=NULL)
{
 while(fscanf(f1," %d %d %d %d %d %d %s",&E.dateElect.jour, &E.dateElect.mois, &E.dateElect.annee,&E.idEl,&E.nbH,&E.nbC,E.muni)!=EOF)
  {
  if (E.idEl==idEl)
{ test=1;
   fprintf(f2," %d %d %d %d %d %d %s\n",new.idEl,new.dateElect.jour,new.dateElect.mois,new.dateElect.annee,new.nbH,new.nbC,new.muni);

}
else
fprintf(f2,"%d %d %d %d %d %d %s\n",E.idEl,  E.dateElect.jour,E.dateElect.mois,E.dateElect.annee,E.nbH,E.nbC,E.muni);
}
}
fclose(f1);
fclose(f2);
remove(filename);
rename("new.txt",filename);
return test;
}
int supprimer(char * filename, int idEl)
{
FILE *f1=NULL , *f2=NULL;
f1= fopen(filename,"r");
f2=fopen("new.txt","w");
election E;
 int test=-1;
if(f1!=NULL)
{
while (fscanf(f1,"%d %d %d %d %d %d %s\n ",&E.dateElect.jour,&E.dateElect.mois,&E.dateElect.annee,&E.idEl,&E.nbH,&E.nbC,E.muni)!=EOF)
{
if(E.idEl==idEl)
{
test=1;

}
else
fprintf(f2,"%d  %d %d %d %d %d %s",E.idEl ,E.dateElect.jour,E.dateElect.mois,E.dateElect.annee,E.nbH,E.nbC,E.muni);

}
}
fclose(f1);
fclose(f2);
remove(filename);
rename("new.txt",filename);
return test;
}

election chercher(char * filename,int idEl)
{
  election E;
  int test=-1;
  FILE * f1=fopen(filename,"r");
  if(f1!=NULL)
 {
while(test==-1 && fscanf (f1,"%d %d %d %d %d %d  %s",&E.idEl,&E.dateElect.jour,&E.dateElect.mois,&E.dateElect.annee,&E.nbH,&E.nbC,E.muni)!=EOF)
 {
  if(E.idEl==idEl)
{
   test=1;
}
}
}
fclose(f1);
if(test==-1)
 E.idEl=-1;
return E;
}*/
