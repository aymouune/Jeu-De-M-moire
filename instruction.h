#ifndef INSTRUCTION_H_INCLUDED
#define INSTRUCTION_H_INCLUDED
#include "apropos.h"

void Apropos(SDL_Window *ecran,SDL_Surface *surface,int joueurs);

void instructions(SDL_Window *ecran,SDL_Surface *surface,int joueurs){ // cette fonction permet d'afficher l'interface d'instructions
    SDL_Surface*image=NULL ;
    SDL_Event event ;
    int continuer=1;

    image=SDL_LoadBMP("background/instructions.bmp");
    SDL_BlitSurface(image,NULL,surface,NULL);
    SDL_UpdateWindowSurface( ecran );

while(continuer){
    SDL_PollEvent(&event);
    switch(event.type){
      case SDL_QUIT:
      continuer =0;
      break;
      case SDL_MOUSEBUTTONDOWN:
        if(event.button.button==SDL_BUTTON_LEFT){
            //printf("%dx  %dy",event.button.x,event.button.y);
            if(event.button.x>=0&&event.button.x<=59 &&event.button.y>=0&&event.button.y<=55){
                    Apropos(ecran,surface,joueurs);
            }
        }
        break;
    }
}
SDL_FreeSurface(image);
}

#endif // INSTRUCTION_H_INCLUDED
