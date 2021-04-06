#include"header.h"
#include"players.h"

int main(int argc,char* argv[]){
gtk_init(&argc,&argv);            //intialisation du gtk

srand(time(NULL)); //nécessaire pour appeler la fonction rand()

putenv("SDL_VIDEO_CENTERED=1");            //ON CENTRE LA FENETRE

ecran = SDL_CreateWindow("JeuDeMemory",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,LARGEUR_FENETRE,HAUTEUR_FENETRE,0);  //creation d'une fenetre par SDL
surface= SDL_GetWindowSurface( ecran );                  //on pose notre surface dans la fenetre

nombreDeJoueur(ecran,surface);                                 //on appelle la fonction nombreDeJoueur();

SDL_FreeSurface(surface);                               //pour liberer la surface du memoire
SDL_DestroyWindow(ecran);                               //pour liberer la fenetre du memoire
SDL_Quit();                                             //pour quitter la SDL
return EXIT_SUCCESS;
}


