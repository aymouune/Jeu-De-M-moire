#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include "menudejeu.h"

void sup_joueur(char*login,char*pass);
void admin();

GtkBuilder *builder2;
GtkWidget *window2;
GtkWidget *button2;
GtkWidget *E1win2,*E2win2;
GtkLabel *plabel2;

void exclureJoueur(GtkWidget *widget,gpointer data){
    char T1[20],T2[20];
    strcpy(T1,gtk_entry_get_text(GTK_ENTRY(E1win2)));
    strcpy(T2,gtk_entry_get_text(GTK_ENTRY(E2win2)));
    sup_joueur(T1,T2);

    gtk_main_quit();
}

void checkadmin(GtkWidget *widget,gpointer data){
    char T1[20],T2[20];
    strcpy(T1,gtk_entry_get_text(GTK_ENTRY(E1win2)));
    strcpy(T2,gtk_entry_get_text(GTK_ENTRY(E2win2)));
    gtk_widget_destroy(window2);

    if((strcmp("aymoune",T1) == 0 && strcmp("aymoune",T2 ) == 0)||(strcmp("tikiller",T1) == 0 && strcmp("tikiller",T2 ) == 0)){  // vérifie l'accès de l'admin
    builder2=gtk_builder_new_from_file("supprimer.glade");
    plabel2=GTK_LABEL(gtk_builder_get_object(builder2,"label1"));
    gtk_label_set_text(plabel2,"JOUEUR A EXCLURE..");   // affiche le label entre guillemets

    window2=GTK_WIDGET(gtk_builder_get_object(builder2,"window1"));
    button2=GTK_WIDGET(gtk_builder_get_object(builder2,"button1"));
    E1win2=GTK_WIDGET(gtk_builder_get_object(builder2,"E1"));
    E2win2=GTK_WIDGET(gtk_builder_get_object(builder2,"E2"));
    gtk_window_set_position(GTK_WINDOW(window2), GTK_WIN_POS_CENTER); // ON CENTRE LA FENÊTRE
    gtk_window_set_title(GTK_WINDOW(window2), "Admin");    // On modifie le titre de la fenêtre

    g_signal_connect(button2,"clicked",G_CALLBACK(exclureJoueur),NULL); // une fois cliquée , il y aure appel de la fct exclureJoueur
    gtk_widget_show_all(window2);
    gtk_main();
    }

    gtk_widget_destroy(window2);
    gtk_main_quit();
}

void admin(){
    builder2=gtk_builder_new_from_file("loginpro.glade");
    plabel2=GTK_LABEL(gtk_builder_get_object(builder2,"label1"));
    gtk_label_set_text(plabel2,"WELCOME ADMIN :)");  // on affiche le texte dans la fenêtre

    window2=GTK_WIDGET(gtk_builder_get_object(builder2,"window1"));
    button2=GTK_WIDGET(gtk_builder_get_object(builder2,"button1"));
    E1win2=GTK_WIDGET(gtk_builder_get_object(builder2,"E1"));
    E2win2=GTK_WIDGET(gtk_builder_get_object(builder2,"E2"));
    gtk_window_set_position(GTK_WINDOW(window2), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window2), "Admin");     // On modifie le titre de la fenêtre

    g_signal_connect(button2,"clicked",G_CALLBACK(checkadmin),NULL); // appel la fct checkadmin
    gtk_widget_show_all(window2);
    gtk_main();
}


#endif // ADMIN_H_INCLUDED
