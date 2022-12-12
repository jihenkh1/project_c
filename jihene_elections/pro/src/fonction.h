#include <gtk/gtk.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
}date;

typedef struct
{
    char id[20];
    date date_election;
    char nbh[20];
    char nbc[20];
    char muni[20];
   
}election;


void  ajouter_election(election c);
void afficher_election(GtkWidget *liste);
void supprimer_election(election c, char id[],char muni[]);
void modifier_election(election r, char id[]);
void chercher_election_supp(election r, char id[20],int *ok);
void afficher_electionModif(GtkWidget *liste);
void chercher_election(election c, char muni[20], int *ok);
