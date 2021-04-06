

#ifndef MENUDEJEU_H_INCLUDED
#define MENUDEJEU_H_INCLUDED
#include "header.h"
#include "modedejeu.h"
#include "players.h"
#include"apropos.h"

GtkBuilder *builder1;
GtkWidget *window1;
GtkWidget *button1;
GtkWidget *E1win1,*E2win1,*E3win1;
GtkLabel *plabel;
char* names[3];
static int c;


void nombreDeJoueur(SDL_Window *ecran,SDL_Surface *surface);
player* found(char *nomdefichier,char * login,char * password);
void menudejeu(SDL_Window *ecran,SDL_Surface *surface,int joueurs);

void creerJoueur(GtkWidget *widget,gpointer data){
    char T11[20],T22[20],T33[20];

    strcpy(T11,gtk_entry_get_text(GTK_ENTRY(E1win1)));  //on recupere la 1ére entrée
    strcpy(T22,gtk_entry_get_text(GTK_ENTRY(E2win1)));  //on recupere la 2eme entrée
    strcpy(T33,gtk_entry_get_text(GTK_ENTRY(E3win1)));  //on recupere la 3eme entrée
    int score=0;

    printf("%s %s %s \n",T11,T22,T33);

    FILE *fp=fopen("texto.txt","a+");
    if(found("texto.txt",T22,T33)!=NULL ||T11==NULL||T22==NULL||T33==NULL){    //si le joueur existe deja ou l'utilisateur n'a saisie rien dans une case!!
      plabel=GTK_LABEL(gtk_builder_get_object(builder1,"label2"));
      gtk_label_set_text(plabel,"existe deja!!");
      g_signal_connect(G_OBJECT(window1), "destroy",G_CALLBACK(gtk_main_quit), NULL);  //on laisse la fenetre ouverte pour s'inscrire
    }
    else{                                              //si tout est bien passé on enregistre les données dans le fichier
    fprintf(fp, "%s %s %s %d\n",T11,T22,T33,score);
    fclose(fp);
    plabel=GTK_LABEL(gtk_builder_get_object(builder1,"label2"));
    gtk_label_set_text(plabel,"Player Saved!");
    g_signal_connect(G_OBJECT(window1), "destroy",G_CALLBACK(gtk_main_quit), NULL);   //on retoure à la fenetre du menu pour se connecter

    }
}

int getFileLinesNumber(FILE *fp){   //cette fonctions retourne le nombre des lignes d'un fichier
    if(fp==NULL) return -1;
    int ch=0;
    int lines=0;
    while(!feof(fp)){
      ch = fgetc(fp);
      if(ch == '\n'){
        lines++;
      }
    }
    return lines;
}


void sup_joueur(char*login,char*pass){
  FILE *fPtr,*fPtr2;
  fPtr = fopen ("texto.txt", "r");
  fPtr2 = fopen("provisoire.txt","a+");
  char str1[20],str2[20],str3[20],str4[20];
  int i,n=getFileLinesNumber(fPtr);
  rewind(fPtr);
  for(i=0;i<n;i++){
    fscanf(fPtr,"%s %s %s %s",str1,str2,str3,str4);     //on recupere toutes les données des joueurs existants sauf du joueur que l'on souhaite supprimer
    if(strcmp(login,str2 ) != 0 && strcmp(pass,str3) != 0)
      fprintf(fPtr2,"%s %s %s %s\n",str1,str2,str3,str4);   //on pose ces données dand un autre fichier
  }
fclose(fPtr);
fclose(fPtr2);
remove("texto.txt");                     //on efface les dernier fichier
rename("provisoire.txt","texto.txt");    //on renomme le nouveau fichier par le nom du fichier precedent pour qu'il reste un seul fichier qui contient les données
}
void modifierscore(player *ptr,int score){
  if(ptr->score < score ){    //si le score du joueur est superieur à son score precedent
    sup_joueur(ptr->username, ptr->password);   // on supprime le joueur du fichier
    FILE *fpx=fopen("texto.txt","a+");
    rewind(fpx);
    fprintf(fpx,"%s %s %s %d\n",ptr->name,ptr->username,ptr->password,score);   //on ecrit dans le fichier les infos du joueur avec le nouveau score
    fclose(fpx);
  }
}

player* found(char *nomdefichier, char * login, char * password){
  FILE *fp=fopen(nomdefichier,"r");
  Player ptr=(Player)malloc(sizeof(player)) ;
  int i,n=getFileLinesNumber(fp);             //on affecte à n le nombre de ligne du fichier
  char *strscore=(char*)malloc(sizeof(int)) ;
  rewind(fp);
  for(i=0;i<=n;i++){                    //on parcourt le fichier ligne par ligne
    fscanf(fp,"%s %s %s %s\n ",ptr->name,ptr->username,ptr->password,strscore);
    ptr->score=atoi(strscore);
    if(strcmp(login,ptr->username ) == 0 && strcmp(password,ptr->password ) == 0){  //si les données saisis existe dans le fichier
            fclose(fp);
			return ptr;         //on retourne un pointeur de type joueur qui contient les infos du joueurs
		}
  }
    fclose(fp);
    return NULL;               //sinn on retourne un pointeur nulle
}

void EnCours(GtkWidget *widget,gpointer data){
        char T1[20],T2[20];
        strcpy(T1,gtk_entry_get_text(GTK_ENTRY(E1win1)));       //on recupere la donnée entrée 1 dans un tableau de type char
        strcpy(T2,gtk_entry_get_text(GTK_ENTRY(E2win1)));       //on recupere la donnée entrée 2 dans un tableau de type char

        player* ptr=found("texto.txt",T1,T2);                   //on cherche dans notre fichier si le joueur existe
        if(ptr!=NULL){                            // si le joueur existe
                FILE *fp=fopen("listjoueursprovisoire.txt","a+");
                fprintf(fp,"%s %s %s %d\n",ptr->name,ptr->username,ptr->password,ptr->score);
                fclose(fp);
                names[c-1]=ptr->name;            //on recupere son nom
                gtk_main_quit();
        }
        else{                                //si le joueur n'existe pas
            plabel=GTK_LABEL(gtk_builder_get_object(builder1,"label1"));
            gtk_label_set_text(plabel,"joueur n'existe pas!!");
            g_signal_connect(G_OBJECT(window1), "destroy",G_CALLBACK(gtk_main_quit), NULL);   //on affiche la fenetre pour se connecter avec d'autres infos

        }
}

void menudejeu(SDL_Window *ecran,SDL_Surface *surface,int joueurs){
    SDL_Surface*image=NULL ;                                         //declaration et initialisation d'une surface
    SDL_Event event ;                                                //declaration de notre evenement
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);                         //insialisation du video et d'audio
    int continuer=1;

    image=SDL_LoadBMP("background/menu.bmp");                                   //importation d'une image
    SDL_BlitSurface(image,NULL,surface,NULL);                        //on pose l'image sur la surface du jeu
    SDL_UpdateWindowSurface( ecran );                                //on affiche notre image

while(continuer){                               //la boucle infinie qui laisse notre événement se repete tant que l'on a pas quitter le jeu
    SDL_PollEvent(&event);
    switch(event.type){
      case SDL_QUIT:
      continuer =0;
      break;
      case SDL_MOUSEBUTTONDOWN:
        if(event.button.button==SDL_BUTTON_LEFT){

               if(event.button.x>=312&&event.button.x<=441 &&event.button.y>=110&&event.button.y<=150  ){    //l'intervalle du boutton se connecter
                    c=joueurs;                                                    //on affecte à la variable c le nombre de joueur
                    do{
                    builder1=gtk_builder_new_from_file("loginpro.glade");      //on charge le fichier preparé en utilisant Glade et qui comporte les entrées et les sorties
                    plabel=GTK_LABEL(gtk_builder_get_object(builder1,"label1"));     //on associe la case d'affichage à une variable pour l'utiliser apres
                    switch(c){                                                       //on affiche à chaque joueur son nombre dans le jeu
                        case 3:gtk_label_set_text(plabel,"JOUEUR 3 ");break;
                        case 2:gtk_label_set_text(plabel,"JOUEUR 2 ");break;
                        case 1:gtk_label_set_text(plabel,"JOUEUR 1 ");break;
                    }
                    window1=GTK_WIDGET(gtk_builder_get_object(builder1,"window1"));      //on associe la fenetre du gtk à une variable
                    button1=GTK_WIDGET(gtk_builder_get_object(builder1,"button1"));       //on associe le boutton du gtk à une variable
                    E1win1=GTK_WIDGET(gtk_builder_get_object(builder1,"E1"));             //on associe l'entrée du gtk à une variable
                    E2win1=GTK_WIDGET(gtk_builder_get_object(builder1,"E2"));
                    gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);       // on centre la fenetre
                    gtk_window_set_title(GTK_WINDOW(window1), "Se connecter");                //on donne un nom  à notre fenetre gtk

                    g_signal_connect(button1,"clicked",G_CALLBACK(EnCours),NULL);          //pour connecter le boutton à la fonction chercher
                    gtk_widget_show_all(window1);                                            //affichage du fenetre
                    gtk_main();                                                              //la boucle infinie qui laisse la fenetre affichée
                    gtk_widget_destroy(window1);                                          //pour liberer la fenetre du memoire apres la fin de son travail
                    c--;
                    }while(c>0);                                        //on repete cela c fois tel que c est le nombre de joueur
                    int h;
                    for(h=joueurs;h>0;){
                        if(names[h-1]==NULL){                                      //si un des utilisateurs saisie des infos fausses
                            menudejeu(ecran,surface,joueurs);break;
                        }
                        h--;
                    }
                    if(h==0){modejeu(ecran,surface,joueurs,names);}               //si tout est bien on lance le jeu
            }
            else if(event.button.x>=312&&event.button.x<=441 &&event.button.y>=174&&event.button.y<=214){      //boutton pour s'inscrire
                    builder1=gtk_builder_new_from_file("inscriptionPRO.glade");

                    window1=GTK_WIDGET(gtk_builder_get_object(builder1,"window2"));
                    button1=GTK_WIDGET(gtk_builder_get_object(builder1,"button2"));
                    E1win1=GTK_WIDGET(gtk_builder_get_object(builder1,"E1"));
                    E2win1=GTK_WIDGET(gtk_builder_get_object(builder1,"E2"));
                    E3win1=GTK_WIDGET(gtk_builder_get_object(builder1,"E3"));
                    gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
                    gtk_window_set_title(GTK_WINDOW(window1), "S'inscrire");

                    g_signal_connect(button1,"clicked",G_CALLBACK(creerJoueur),NULL);
                    gtk_widget_show_all(window1);
                    gtk_main();
                    gtk_widget_destroy(window1);
                    menudejeu(ecran,surface,joueurs);         // on revient vers la page du menu pour se connecter et jouer..
            }
            else if(event.button.x>=312&&event.button.x<=441 &&event.button.y>=235&&event.button.y<=275){
                    //à propos
                    Apropos(ecran,surface,joueurs);
            }
            else if(event.button.x>=0&&event.button.x<=60 &&event.button.y>=0&&event.button.y<=60){
                    //retour
                    nombreDeJoueur(ecran,surface);
            }
            else if(event.button.x>=312&&event.button.x<=441 &&event.button.y>=300&&event.button.y<=340 ){
                    exit(0);    //quitter le jeu
            }

        }

        break;
    }

}

}

#endif // MENUDEJEU_H_INCLUDED
