#ifndef LIBRARIES_H_INCLUDED
#define LIBRARIES_H_INCLUDED

#include<gtk/gtk.h>
#include<SDL.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<windows.h>

#define LARGEUR_FENETRE  800
#define HAUTEUR_FENETRE  640

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 640

SDL_Window *ecran=NULL;           //declaration et intialisation de notre fenetre
SDL_Surface *surface=NULL ;        //declaration et intialisation de notre surface

#endif // LIBRARIES_H_INCLUDED
