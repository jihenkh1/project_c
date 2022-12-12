#include "fonction.h"
#include "callbacks.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

enum{
ID,
NBC,
DATE_ELECTION,
MUNI,
NBH,
COLUMNS
};

////////////////////////////////AjouterElection///////////////////////
void ajouter_election(election c)
{
    FILE *fp;
    fp = fopen("election.bin", "ab+");
    if (fp!=NULL)
    {
        

        fwrite(&c, sizeof(c), 1, fp);
        
    }
    else
    {
        printf("\n non trouver");
    }
fclose(fp);
}
/////////////////////////////////////Afficherelection////////////////////////////////////////
void afficher_election(GtkWidget *liste)
{
election c;
char DATE[30];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
store = NULL;
FILE *fp;


store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" nmbre Habitants",renderer,"text",NBH,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date d'election",renderer,"text",DATE_ELECTION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Municipalite ",renderer,"text",MUNI,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nombre Cons",renderer,"text",NBC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	fp = fopen("election.bin", "rb");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("election.bin", "ab+");	
		while(fread(&c, sizeof(c), 1, fp))
		{
		sprintf(DATE, "%d/%d/%d", c.date_election.jour,c.date_election.mois,c.date_election.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ID, c.id, NBH, c.nbh,DATE_ELECTION, DATE, MUNI, c.muni,  NBC, c.nbc,-1);
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}
/////////////////////////////////////Supprimerelection////////////////////////////////////
void supprimer_election(election c, char id[], char muni[])
{

FILE *fp1, *fp2;
    fp1 = fopen("election.bin", "rb");
    fp2 = fopen("temp.bin", "ab+");
    if (fp1==NULL)
    {
        printf("\nEchec lors de l'ouverture du fichier 'election.bin'");
    }
    else
    {
        while (fread(&c, sizeof(c), 1, fp1))
        {
            if ((strcmp(id, c.id)!=0) && (strcmp(muni, c.muni)!=0))
                fwrite(&c, sizeof(c), 1, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("election.bin");
    rename("temp.bin", "election.bin");
}

/////////////////////////////////////Afficher election a modifier ////////////////////////////////
void afficher_electionModif(GtkWidget *liste)
{
election c;
char DATE[30];
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store = NULL;

FILE *fp;



store = gtk_tree_view_get_model(liste);

if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" nmbre Habitants",renderer,"text",NBH,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Date d'election",renderer,"text",DATE_ELECTION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" Municipalite ",renderer,"text",MUNI,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nombre cons",renderer,"text",NBC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	fp = fopen("election.bin", "rb");

	if(fp==NULL)
	{
	return;
	}

	else
	{
		fp = fopen("temp1.bin", "ab+");	
		while(fread(&c, sizeof(c), 1, fp))
		{
		sprintf(DATE, "%d/%d/%d", c.date_election.jour,c.date_election.mois,c.date_election.annee);
		
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ID, c.id, NBH, c.nbh,DATE_ELECTION, DATE, MUNI, c.muni,  NBC, c.nbc,-1);
		}
		fclose(fp);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
	}

}

///////////////////////////////////// election a modifier ///////////////////////////////////////////
void modifier_election(election r, char id[])
{
FILE *fp1, *fp2;
election c;
fp1 = fopen("election.bin", "rb");
fp2 = fopen("tmpp.bin","ab+");
if (fp1==NULL)
{
	return ;
}
else
{
	while (fread(&c,sizeof(c),1,fp1))
	{
		if (strcmp(c.id,id)!=0)
			fwrite(&c,sizeof(c),1,fp2);
		else
		{
			fwrite(&r,sizeof(r),1,fp2);			
		}
	}
}
fclose(fp1);
fclose(fp2);
remove("election.bin");
rename("tmpp.bin", "election.bin");


}


/////////////////////////////////////chercher election a supprimer ///////////////////////////////////////////
void chercher_election_supp(election r, char id[20], int *ok)
{
FILE *fp ,*fp1;
fp = fopen("election.bin", "rb");
fp1 = fopen("temp1.bin", "wb");
*ok=0;

if(fp==NULL)
{
return;
}
else
{
while(fread(&r, sizeof(r), 1, fp))
{
	if  ((strcmp(id, r.id)==0) )
	{
		fwrite(&r, sizeof(r), 1, fp1);
		*ok=1; 
	}

}
}
fclose(fp);
fclose(fp1);
}

/////////////////////////////////////chercher election  //////////////////////////////////////
void chercher_election(election c, char muni[20], int *ok)
{
FILE *fp ,*fp1;
fp = fopen("election.bin", "rb");
fp1 = fopen("temp1.bin", "wb");
*ok=0;

if(fp==NULL)
{
return;
}
else
{
while(fread(&c, sizeof(c), 1, fp))
{
	if  ((strcmp(muni, c.muni)==0) )
	{
		fwrite(&c, sizeof(c), 1, fp1);
		*ok=1; 
	}

}
}
fclose(fp);
fclose(fp1);
}






