#ifndef FINDEJEU_H_INCLUDED
#define FINDEJEU_H_INCLUDED
#include "players.h"
#include "header.h"

void nombreDeJoueur(SDL_Window *ecran,SDL_Surface *surface);

GtkBuilder *builder3;
GtkWidget *window3;
GtkWidget *button4,*button3;
GtkLabel *plabel31,*plabel32,*plabel33;

void quit(GtkWidget *widget,gpointer data){
    exit(0);
}

void recommencer(GtkWidget *widget,gpointer data){
    gtk_widget_destroy(window3);
    nombreDeJoueur(ecran,surface);
    gtk_main_quit();
}

void findejeu(char *nom,int score){

    if(nom==NULL && score==0){                             //si'il y a égalité dans le jeu
    builder3=gtk_builder_new_from_file("egalite.glade");

    window3=GTK_WIDGET(gtk_builder_get_object(builder3,"window"));
    button3=GTK_WIDGET(gtk_builder_get_object(builder3,"button1"));
    button4=GTK_WIDGET(gtk_builder_get_object(builder3,"button2"));
    gtk_window_set_position(GTK_WINDOW(window3), GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window3), "JeuDeMemory");

    g_signal_connect(button3,"clicked",G_CALLBACK(recommencer),NULL);
    g_signal_connect(button4,"clicked",G_CALLBACK(quit),NULL);

    gtk_widget_show_all(window3);
    gtk_main();
    }

    else {                              //si on a un gagnant

    char buffer[20];
    itoa(score,buffer,10);                  //pour convertir int to string

    char meilleurscore[3];
    FILE *fp=fopen("meilleurscore.txt","r");  // ouvre le fichier texte meilleurscore
    fscanf(fp,"%s",meilleurscore);            // lit la valeur stockée
    fclose(fp);
    if(atoi(meilleurscore)<score){                  // si on a marquée un score encore mieux que le score meilleur
        FILE *fp=fopen("meilleurscore.txt","w+");   // il devient notre nouveau meilleur score
        fprintf(fp,"%d",score);
        fclose(fp);
    }

    builder3=gtk_builder_new_from_file("gagne.glade");      // importe le fichier glade qui contient notre fenêtre

    window3=GTK_WIDGET(gtk_builder_get_object(builder3,"window"));
    button3=GTK_WIDGET(gtk_builder_get_object(builder3,"button1"));
    button4=GTK_WIDGET(gtk_builder_get_object(builder3,"button2"));
    gtk_window_set_position(GTK_WINDOW(window3), GTK_WIN_POS_CENTER);      // ON CENTRE CETTE FENÊTRE
    gtk_window_set_title(GTK_WINDOW(window3), "JeuDeMemory");

    plabel31=GTK_LABEL(gtk_builder_get_object(builder3,"label1"));
    gtk_label_set_text(plabel31,nom);
    plabel32=GTK_LABEL(gtk_builder_get_object(builder3,"label2"));
    gtk_label_set_text(plabel32,buffer);
    plabel33=GTK_LABEL(gtk_builder_get_object(builder3,"label3"));
    gtk_label_set_text(plabel33,meilleurscore);

    g_signal_connect(button3,"clicked",G_CALLBACK(recommencer),NULL);
    g_signal_connect(button4,"clicked",G_CALLBACK(quit),NULL);

    gtk_widget_show_all(window3);
    gtk_main();
    }
}

#endif // FINDEJEU_H_INCLUDED
