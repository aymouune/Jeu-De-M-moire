

#ifndef PLAYERS_H_INCLUDED
#define PLAYERS_H_INCLUDED
#include"header.h"
#include"menudejeu.h"

void nombreDeJoueur(SDL_Window *ecran,SDL_Surface *surface){
    remove("listjoueursprovisoire.txt");       // on supprime ce fichier supposé existé dans notre fichier

    SDL_Surface*image=NULL ;                            //declaration et intialisation d'une surface
    SDL_Event event ;                                   //declaration d'un événement
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);            //initialisation du video et d'audio
    int continuer=1,joueurs;

    image=SDL_LoadBMP("background/players.bmp");                   //importation d'une photo dans la surface
    SDL_BlitSurface(image,NULL,surface,NULL);           //mettre la photo chargée sur la suface du jeu
    SDL_UpdateWindowSurface( ecran );                     //affichage du photo importée

while(continuer){                                       //la boucle infinie qui laisse notre événement se repete tant que l'on a pas quitter le jeu
    SDL_PollEvent(&event);
    switch(event.type){
      case SDL_QUIT:
      continuer =0;
      break;
      case SDL_MOUSEBUTTONDOWN:
        if(event.button.button==SDL_BUTTON_LEFT){

            if(event.button.x>=355&&event.button.x<=407 &&event.button.y>=170&&event.button.y<=210  ){            //l'interval de la 1ère boutton
                    joueurs=1;
                    Sleep(300);
            }
            else if(event.button.x>=355&&event.button.x<=407 &&event.button.y>=236&&event.button.y<=276){          //l'interval de la 2ème boutton
                    joueurs=2;
                    Sleep(300);
            }
            else if(event.button.x>=355&&event.button.x<=407 &&event.button.y>=300&&event.button.y<=340){           //l'interval de la 3ème boutton
                    joueurs=3;
                    Sleep(300);
            }
            menudejeu(ecran,surface,joueurs);                  //apres que l'utilisateur choisi le nombre de joueur on appelle la fonction menuDeJeu..
        }
        break;
    }
}
SDL_FreeSurface(image);
}

#endif // PLAYERS_H_INCLUDED
