#ifndef APROPOS_H_INCLUDED
#define APROPOS_H_INCLUDED
#include "instruction.h"
#include "admin.h"

void admin();

void Apropos(SDL_Window *ecran,SDL_Surface *surface,int joueurs){
    SDL_Surface*image=NULL ;
    SDL_Event event ;
    int continuer=1;

    image=SDL_LoadBMP("background/Apropos.bmp");
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

            if(event.button.x>=303&&event.button.x<=495 &&event.button.y>=260&&event.button.y<=310 ){
                    admin();           // on appelle la fonction admin si le joueur presse la bouton admin
            }
            else if(event.button.x>=303&&event.button.x<=495 &&event.button.y>=373&&event.button.y<=423){
                    instructions(ecran,surface,joueurs); // on appelle la fonction instructions si le joueur presse la bouton instructions
            }
            else if(event.button.x>=0&&event.button.x<=59 &&event.button.y>=0&&event.button.y<=55){
                    menudejeu(ecran,surface,joueurs); // si le joueur choisit de revenir en arrière
            }
        }
        break;
    }
}
SDL_FreeSurface(image);
}

#endif // APROPOS_H_INCLUDED
