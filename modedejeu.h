

#ifndef MODEDEJEU_H_INCLUDED
#define MODEDEJEU_H_INCLUDED
#include "header.h"
#include "codedejeu.h"

void menudejeu(SDL_Window *ecran,SDL_Surface *surface,int joueurs);

void modejeu(SDL_Window *ecran,SDL_Surface *surface,int joueurs,char* names[]){

SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);     //initialisation du video et d'audio
SDL_Surface *screen=NULL;               //declaration et initialisation d'une surface
int a,b,continuer=1;
while(continuer){
    SDL_Event event ;
    screen=SDL_LoadBMP("background/mode.bmp");              // on charge l'image dans la surface
    SDL_BlitSurface(screen,NULL,surface,NULL);    //on pose l'image chargée sur la surface du jeu
    SDL_UpdateWindowSurface(ecran);               //on affiche l'image sur la fenetre
    SDL_PollEvent(&event);
    switch(event.type){
      case SDL_QUIT:
          continuer =0;
          break;
      case SDL_MOUSEBUTTONDOWN:
          if(event.button.button==SDL_BUTTON_LEFT){
           //   printf("%dx  %dy",event.button.x,event.button.y);
              if(event.button.x>=274&&event.button.x<=442 &&event.button.y>=118&&event.button.y<=178  ){ //boutton facile
                     a=3;b=4;                             //pour le niveau facile
              }
              else if(event.button.x>=274&&event.button.x<=442 &&event.button.y>=204&&event.button.y<=264){  //boutton moyen
                     a=4;b=5;                             //pour le niveau moyen
              }
              else if(event.button.x>=274&&event.button.x<=442 &&event.button.y>=290&&event.button.y<=350 ){ //boutton difficille
                    a=5;b=6;                             //pour le niveau difficile
             }
             else if(event.button.x>=0&&event.button.x<=60 &&event.button.y>=0&&event.button.y<=60){
                    //retour
                    menudejeu(ecran,surface,joueurs);
            }
            screen=SDL_LoadBMP("background/screen.bmp");                     //on importe l'image dans une surface
            SDL_BlitSurface(screen,NULL,surface,NULL);              //on pose l'image sur la surface de jeu
            SDL_UpdateWindowSurface( ecran );                      //on affiche l'image dans la fenetre
            codejeu(ecran,surface,event,a,b,joueurs,names);            //on le lance le jeu
        }
        break;
    }
}
SDL_FreeSurface(screen);
SDL_Quit();
}

#endif // MODEDEJEU_H_INCLUDED
