#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"


//////////Treeview Affichage//////////
void on_treeviewRechercher_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar *id;
	gchar *muni;
	gchar *nbh;
	gchar *nbc;
	gchar *date_election;
	election c;
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model, &iter, path))
	{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&id,1,&nbh,2,&muni,3,&date_election,4,&nbc,5, -1);
	strcpy(c.id,id);
	strcpy(c.nbc,nbc);
	strcpy(c.muni,muni);
	strcpy(c.nbh,nbh);
	afficher_election(treeview); 
	}
}

char tmps[30];
////////////chercher dans le Treeview/////////

void on_Rechercher_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeviewRechercher;
GtkWidget *liste1;

GtkWidget *input2;
GtkWidget *buttonEnable;
GtkWidget *window;
election c;
int ok; 
char id[30];
input2 = lookup_widget(button, "entryIDrechercher");
buttonEnable = lookup_widget(button, "Rechercherelection");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input2)));

window = lookup_widget(button, "windowGestionelection");
treeviewRechercher = lookup_widget(window, "treeviewRechercher");

//chercher_election_supp(r, id, &ok);
chercher_election(c,id, &ok);
if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); 
else
gtk_widget_set_sensitive(buttonEnable, FALSE); 


afficher_electionModif(treeviewRechercher);
}


void on_Afficher_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *snumero,*cap;
cap=lookup_widget(button,"windowGestionelection");
snumero=lookup_widget(button,"treeviewRechercher");
afficher_election(snumero);
}





void on_buttonModifelec_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *windowModifierelection;
GtkWidget *windowMenu;
GtkWidget *treeview;
windowMenu = lookup_widget(button, "windowGestionelection");
gtk_widget_destroy(windowMenu);
windowModifierelection = create_windowModifierelection();
gtk_widget_show(windowModifierelection);
treeview = lookup_widget (windowModifierelection, "treeview2");
afficher_election(treeview);
}
int choixsk[] = {0,0,0,0,0,0,0}; 
int choix1sk[] = {0,0,0,0,0,0,0};
 

void on_buttonAjoutelec_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowAjout;
GtkWidget *windowMenu;
windowMenu = lookup_widget(button,"windowGestionelection");
gtk_widget_destroy(windowMenu);

windowAjout = lookup_widget(button,"windowAjoutCapteur");
windowAjout = create_windowAjoutelection();
gtk_widget_show(windowAjout);
}

void on_buttonAcceuil_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowSupprime;
GtkWidget *windowMenu;
GtkWidget *windowAjoutelection;
GtkWidget *windowModifierelection;
GtkWidget *windowListeelection;



windowModifierelection = lookup_widget(button, "windowModifierelection");
gtk_widget_destroy(windowModifierelection);

windowAjoutelection = lookup_widget(button, "windowAjoutelection");
gtk_widget_destroy(windowAjoutelection);




windowMenu = create_windowGestionelection();
gtk_widget_show(windowMenu);
}





void on_okbutton1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "windowAjoutSucc");
gtk_widget_destroy(window);
}


void on_okbutton2_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "windowModifSucc");
gtk_widget_destroy(window);
}


void on_okbutton3_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "windowSupSucc");
gtk_widget_destroy(window);
}


void on_okbutton444_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "windowRemplir");
gtk_widget_destroy(window);
}


void on_button24_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
window = lookup_widget(button, "windowID");
gtk_widget_destroy(window);
}



void on_checkbutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixsk[0] = 1;
else
choixsk[0] = 0;
}


void on_checkbutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixsk[1] = 1;
else
choixsk[1] = 0;
}


void
on_checkbutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixsk[2] = 1;
else
choixsk[2] = 0;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1sk[0] = 1;
else
choix1sk[0] = 0;
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1sk[1] = 1;
else
choix1sk[1] = 0;
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1sk[2] = 1;
else
choix1sk[2] = 0;
}


void
on_buttonAjouter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
                                       
{
{
election c;
election r;
FILE *fp1;
int fail=0;
fp1 = fopen("election.bin", "rb");



GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *windowRemplir;
GtkWidget *windowConfirmation;
GtkWidget *windowErreur;

GtkWidget *nbc;
GtkWidget *muni;
GtkWidget *dialog;
input1 = lookup_widget(button, "entryId");

Jour = lookup_widget(button, "spinbuttonSkJours");
Mois = lookup_widget(button, "spinbuttonSkMois");
Annee = lookup_widget(button, "spinbuttonSkAnnees");
muni= lookup_widget(button, "comboboxnbh");
nbc= lookup_widget(button, "comboboxnbc");
strcpy(c.muni,gtk_combo_box_get_active_text(GTK_COMBO_BOX(muni)));
strcpy(c.nbc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(nbc)));
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));








if (choix1sk[0]==1)
strcpy(c.nbh,"5000 ");
else if (choix1sk[1]==1)
strcpy(c.nbh,"5001 a 10.000");
else if (choix1sk[2]==1)
strcpy(c.nbh,"10.001 a 25.000");
else if  (choix1sk[3]==1)
strcpy(c.nbh,"25.001 a 50.000 ");
else if (choix1sk[4]==1)
strcpy(c.nbh,"50.001 a 100.000");
else if (choix1sk[5]==1)
strcpy(c.nbh,"100.001 a 500.000");
else if (choix1sk[6]==1)
strcpy(c.nbh,"plus que 500.001  ");



c.date_election.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
c.date_election.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
c.date_election.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));


if (  
(strcmp(c.id,"")==0)   || (choix1sk[0]==1) && (choix1sk[1]==1) && (choix1sk[2]==1) && (choix1sk[3]==1) && (choix1sk[4]==1) && (choix1sk[5]==1) && (choix1sk[6]==1) ||  (choix1sk[0]==0) && (choix1sk[1]==0) && (choix1sk[2]==0 )&& (choix1sk[3]==0) && (choix1sk[4]==0 )  && (choix1sk[5]==0) && (choix1sk[6]==0 ) 
) 
{
windowErreur = create_windowRemplir();
gtk_widget_show(windowErreur);
fail=1;
}


fp1 = fopen("election.bin", "rb");
if(fp1==NULL)
{
	return;
}
else
{
while (fread(&r, sizeof(r), 1, fp1))
{
	if(strcmp(c.id, r.id)==0)
	{
		dialog = create_windowID();
		gtk_widget_show(dialog);
		fail = 1;
		break;
	}
}
fclose(fp1);
}



if (fail==0)
{
ajouter_election(c);
windowConfirmation = create_windowAjoutSucc();
gtk_widget_show(windowConfirmation);
}
}

}


void
on__annulerajout                       (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *windowMenu;
GtkWidget *windowAjoutelection;


windowAjoutelection = lookup_widget(button, "windowAjoutelection");
gtk_widget_destroy(windowAjoutelection);

windowMenu = create_windowGestionelection();
gtk_widget_show(windowMenu);
}


void
on_buttonMenu_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *windowMenu;
GtkWidget *windowAjoutelection;
GtkWidget *windowModifierelection;




windowModifierelection = lookup_widget(button, "windowModifierelection");
gtk_widget_destroy(windowModifierelection);

windowAjoutelection = lookup_widget(button, "windowAjoutelection");
gtk_widget_destroy(windowAjoutelection);


windowMenu = create_windowGestionelection();
gtk_widget_show(windowMenu);
}

/*
void
on_buttonSupprimerelec_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}
*/




void
on_buttonSuppelection_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *windowConfirmation;
	GtkTreeSelection *selection;
        GtkTreeIter iter;
	GtkTreeModel *model;
        GtkWidget *label;
        GtkWidget* p;
   	gchar *id;
	gchar *nbh;
	gchar *nbc;
	gchar *muni;
	
	gchar *date_election;
	election c ;
        //label=lookup_widget(objet,"label78");
        p=lookup_widget(button,"treeviewRechercher");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        (gtk_tree_selection_get_selected(selection, &model, &iter)) ;
        gtk_tree_model_get (model,&iter,0,&id,1,&muni,2,&nbh,3,&date_election,4,&nbc,5, -1);
        gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
	supprimer_election(c,id,muni);
	windowConfirmation = create_windowSupSucc();
	gtk_widget_show(windowConfirmation);
}


gboolean
on_treeview_start_interactive_search   (GtkTreeView     *treeview,
                                        gpointer         user_data)
{

  return FALSE;
}


void
on_buttonRechercherMODIF_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *liste1;
GtkWidget *input;
GtkWidget *input1;
GtkWidget *buttonEnable;
GtkWidget *window;
int ok;
char muni[20]; 
election r;
char id[20];
input = lookup_widget(button, "entryIDMODIF");
//input1 = lookup_widget(button, "comboboxen");
buttonEnable = lookup_widget(button, "buttonModiff"); 
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
//strcpy(muni,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
window = lookup_widget(button, "windowModifierelection");
treeview1 = lookup_widget(window, "treeview1");
//chercher_election(c,id, &ok);
chercher_election_supp(r, id, &ok);
if (ok)
gtk_widget_set_sensitive(buttonEnable, TRUE); 
else
gtk_widget_set_sensitive(buttonEnable, FALSE); 


afficher_electionModif(treeview1);
}


void
on_buttonModifier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
election c;
GtkWidget *input1;
GtkWidget *windowModification;
FILE *fp;
fp = fopen("temp1.bin", "rb");
input1 = lookup_widget(button, "entryIDMODIF");
strcpy(tmps,gtk_entry_get_text(GTK_ENTRY(input1)));
windowModification = create_Modifierelection();
gtk_widget_show(windowModification);

GtkWidget *output1, *output2, *output3, *output4, *output5, *output6, *output7, *output8, *output9 ;
if(fp!=NULL)
{
while (fread(&c, sizeof(c), 1, fp))
{
	output1 = lookup_widget(windowModification, "entryMOdifierId");
	gtk_entry_set_text(GTK_ENTRY(output1), c.id);

	
	output4 = lookup_widget(windowModification, "spinbuttonJours");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output4), c.date_election.jour);


	output5 = lookup_widget(windowModification, "spinbuttonMois");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5), c.date_election.mois);


	output6 = lookup_widget(windowModification, "spinbuttonAnnees");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6), c.date_election.annee);


	

	

}
}
fclose(fp);
}


void
on_buttonConfirmerModifier_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
election c;
FILE *fp1;
fp1 = fopen("election.bin", "rb");


GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *Jour;
GtkWidget *Mois;
GtkWidget *Annee;
GtkWidget *windowErreur;
GtkWidget *windowSuccees;
GtkWidget *Modifierelection;
GtkWidget *muni;
GtkWidget *nbc;

input1 = lookup_widget(button, "entryMOdifierId");

Jour = lookup_widget(button, "spinbuttonJours");
Mois = lookup_widget(button, "spinbuttonMois");
Annee = lookup_widget(button, "spinbuttonAnnees");
muni = lookup_widget(button, "comboboxmuni");
nbc = lookup_widget(button, "combobox2nbc");
strcpy(c.muni,gtk_combo_box_get_active_text(GTK_COMBO_BOX(muni)));

strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.nbc,gtk_combo_box_get_active_text(GTK_COMBO_BOX(nbc)));










if (choixsk[0]==1)
strcpy(c.nbh,"5000");
else if (choixsk[1]==1)
strcpy(c.nbh,"5001 a 10.000");
else if (choixsk[2]==1)
strcpy(c.nbh,"10.001 a 25.000");
else if (choixsk[3]==1)
strcpy(c.nbh,"25.001 a 50.000");
else if (choixsk[4]==1)
strcpy(c.nbh,"50.001 a 100.000");
else if (choixsk[5]==1)
strcpy(c.nbh,"100.001 a 500.000");
else if (choixsk[6]==1)
strcpy(c.nbh,"plus que 500.000");






c.date_election.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
c.date_election.mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
c.date_election.annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));



if( (strcmp(c.id,"")==0)  ||  (strcmp(c.nbc,"")==0) ||  ((choixsk[0]==0) && (choixsk[1]==0)&&  (choixsk[2]==0) && (choixsk[3]==0) &&  (choixsk[4]==0) && (choixsk[5]==0) && (choixsk[6]==0))|| ( (choixsk[0]==1) && (choixsk[1]==1) && (choixsk[2]==1 )&& (choixsk[3]==1) && (choixsk[4]==1 )  && (choixsk[5]==1) && (choixsk[6]==1 )  ))
{
windowErreur = create_windowRemplir();
gtk_widget_show(windowErreur);
}
else
{
modifier_election(c,tmps);
windowSuccees = create_windowModifSucc();
gtk_widget_show(windowSuccees);
Modifierelection = lookup_widget(button, "Modifierelection");
gtk_widget_destroy(Modifierelection);
}
}




void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1sk[4] = 1;
else
choix1sk[4] = 0;
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1sk[5] = 1;
else
choix1sk[5] = 0;
}


void
on_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1sk[6] = 1;
else
choix1sk[6] = 0;
}


void
on_radiobutton44_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1sk[3] = 1;
else
choix1sk[3] = 0;
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixsk[3] = 1;
else
choixsk[3] = 0;
}


void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixsk[6] = 1;
else
choixsk[6] = 0;
}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixsk[5] = 1;
else
choixsk[5] = 0;
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choixsk[4] = 1;
else
choixsk[4] = 0;
}

