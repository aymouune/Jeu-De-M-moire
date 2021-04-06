

#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
#include "header.h"

char* inttoimagechrono(int y){    // permet de convertir un entier en une image , cette fonction concerne le chrono
    if(y==10){return "chrono/0.bmp";}
    else if(y==9){return "chrono/1.bmp";}
    else if(y==8){return "chrono/2.bmp";}
    else if(y==7){return "chrono/3.bmp";}
    else if(y==6){return "chrono/4.bmp";}
    else if(y==5){return "chrono/5.bmp";}
    else if(y==4){return "chrono/6.bmp";}
    else if(y==3){return "chrono/7.bmp";}
    else if(y==2){return "chrono/8.bmp";}
    else if(y==1){return "chrono/9.bmp";}
    else if(y==0){return "chrono/10.bmp";}
}

char* inttoimagescore(int y){       // permet de convertir un entier en une image , cette fonction concerne le score
    if(y==1){return "score/1.bmp";}
    else if(y==0){return "score/0.bmp";}
    else if(y==2){return "score/2.bmp";}
    else if(y==3){return "score/3.bmp";}
    else if(y==4){return "score/4.bmp";}
    else if(y==5){return "score/5.bmp";}
    else if(y==6){return "score/6.bmp";}
    else if(y==7){return "score/7.bmp";}
    else if(y==8){return "score/8.bmp";}
    else if(y==9){return "score/9.bmp";}
    else if(y==10){return "score/10.bmp";}
    else if(y==11){return "score/11.bmp";}
    else if(y==12){return "score/12.bmp";}
    else if(y==13){return "score/13.bmp";}
    else if(y==14){return "score/14.bmp";}
    else if(y==15){return "score/15.bmp";}
    else if(y==16){return "score/16.bmp";}
}

char* inttoimageeasy(int y){                // permet de convertir un entier en une image
    if(y==1){return "easy/A.bmp";}          // cette fonction concerne les  cartes en mode facile
    else if(y==2){return "easy/B.bmp";}
    else if(y==3){return "easy/C.bmp";}
    else if(y==4){return "easy/D.bmp";}
    else if(y==5){return "easy/E.bmp";}
    else if(y==6){return "easy/F.bmp";}
    else if(y==7){return "easy/G.bmp";}
    else if(y==8){return "easy/H.bmp";}
    else if(y==9){return "easy/I.bmp";}
    else if(y==10){return "easy/J.bmp";}
    else if(y==11){return "easy/K.bmp";}
    else if(y==12){return "easy/L.bmp";}
    else if(y==13){return "easy/M.bmp";}
    else if(y==14){return "easy/N.bmp";}
    else if(y==15){return "easy/O.bmp";}
    else if(y==16){return "easy/P.bmp";}
}
char* inttoimagemedium(int y){              // permet de convertir un entier en une image
                                            // cette fonction concerne les  cartes en mode moyen
    if(y==1){return "medium/A.bmp";}
    else if(y==2){return "medium/B.bmp";}
    else if(y==3){return "medium/C.bmp";}
    else if(y==4){return "medium/D.bmp";}
    else if(y==5){return "medium/E.bmp";}
    else if(y==6){return "medium/F.bmp";}
    else if(y==7){return "medium/G.bmp";}
    else if(y==8){return "medium/H.bmp";}
    else if(y==9){return "medium/I.bmp";}
    else if(y==10){return "medium/J.bmp";}
    else if(y==11){return "medium/K.bmp";}
    else if(y==12){return "medium/L.bmp";}
    else if(y==13){return "medium/M.bmp";}
    else if(y==14){return "medium/N.bmp";}
    else if(y==15){return "medium/O.bmp";}
    else if(y==16){return "medium/P.bmp";}
}
char* inttoimagehard(int y){        // permet de convertir un entier en une image
                                    // cette fonction concerne les  cartes en mode difficile
    if(y==1){return "hard/A.bmp";}
    else if(y==2){return "hard/B.bmp";}
    else if(y==3){return "hard/C.bmp";}
    else if(y==4){return "hard/D.bmp";}
    else if(y==5){return "hard/E.bmp";}
    else if(y==6){return "hard/F.bmp";}
    else if(y==7){return "hard/G.bmp";}
    else if(y==8){return "hard/H.bmp";}
    else if(y==9){return "hard/I.bmp";}
    else if(y==10){return "hard/J.bmp";}
    else if(y==11){return "hard/K.bmp";}
    else if(y==12){return "hard/L.bmp";}
    else if(y==13){return "hard/M.bmp";}
    else if(y==14){return "hard/N.bmp";}
    else if(y==15){return "hard/O.bmp";}
    else if(y==16){return "hard/P.bmp";}
}

void affichescore1(SDL_Surface *surface,char* score1){      //affiche le score du 1er joueur dans le plateau de jeu
    SDL_Surface *image1,*image2,*image3;
    SDL_Rect rectangle1,rectangle2,rectangle3;
    rectangle1.x=660;
    rectangle1.y=220;
    image1=SDL_LoadBMP("score/joueur1.bmp");
    SDL_BlitSurface(image1,NULL,surface,&rectangle1);
    rectangle2.x=755;
    rectangle2.y=215;
    image2=SDL_LoadBMP(score1);
    SDL_BlitSurface(image2,NULL,surface,&rectangle2);
    rectangle3.x=630;
    rectangle3.y=225;
    image3=SDL_LoadBMP("score/blache.bmp");
    SDL_BlitSurface(image3,NULL,surface,&rectangle3);
}
void affichescore2(SDL_Surface *surface,char* score2){   //affiche le score du 2eme joueur dans le plateau de jeu
    SDL_Surface *image1,*image2,*image3;
    SDL_Rect rectangle1,rectangle2,rectangle3;
    rectangle1.x=660;
    rectangle1.y=270;
    image1=SDL_LoadBMP("score/joueur2.bmp");
    SDL_BlitSurface(image1,NULL,surface,&rectangle1);
    rectangle2.x=755;
    rectangle2.y=265;
    image2=SDL_LoadBMP(score2);
    SDL_BlitSurface(image2,NULL,surface,&rectangle2);
    rectangle3.x=630;
    rectangle3.y=275;
    image3=SDL_LoadBMP("score/blache.bmp");
    SDL_BlitSurface(image3,NULL,surface,&rectangle3);
}
void affichescore3(SDL_Surface *surface,char* score3){           //affiche le score du 3eme joueur dans le plateau de jeu
    SDL_Surface *image1,*image2,*image3;
    SDL_Rect rectangle1,rectangle2,rectangle3;
    rectangle1.x=660;
    rectangle1.y=320;
    image1=SDL_LoadBMP("score/joueur3.bmp");
    SDL_BlitSurface(image1,NULL,surface,&rectangle1);
    rectangle2.x=755;
    rectangle2.y=315;
    image2=SDL_LoadBMP(score3);
    SDL_BlitSurface(image2,NULL,surface,&rectangle2);
    rectangle3.x=630;
    rectangle3.y=325;
    image3=SDL_LoadBMP("score/blache.bmp");
    SDL_BlitSurface(image3,NULL,surface,&rectangle3);
}

void fleche(SDL_Surface *surface,int essaie){              //affiche une fleche indiquant le tour de quel joueur
    SDL_Surface *image ;
    SDL_Rect rectangle;
    switch(essaie){
    case 0:
        rectangle.x=630;
        rectangle.y=225;break;
    case 1:
        rectangle.x=630;
        rectangle.y=275;break;
    case 2:
        rectangle.x=630;
        rectangle.y=325;break;
    }
    image=SDL_LoadBMP("score/vert.bmp");
    SDL_BlitSurface(image,NULL,surface,&rectangle);
}

void timer(SDL_Surface *surface,int variable){          // affiche un chronomètre qui gère les tours
    SDL_Surface *image ;
    SDL_Rect rectangle;

    rectangle.x=5;
    rectangle.y=538;

    image=SDL_LoadBMP("chrono/inverse.bmp");
    SDL_BlitSurface(image,NULL,surface,&rectangle);

    image=SDL_LoadBMP(inttoimagechrono(variable));
    SDL_BlitSurface(image,NULL,surface,&rectangle);
    SDL_FreeSurface(image);
}

void AfficherCarreau(char*photo,SDL_Surface*image,int i,int j,int a,int b){     // affiche un carreau dans lequel
    SDL_Surface *carreau;                                                       // est déposer les cartes de jeu
    SDL_Rect rectangle;

    int h=520/a,w=600/b;

    rectangle.x=35+j*w;
    rectangle.y=25+i*h;
    rectangle.w=w-20;
    rectangle.h=w-20;

    carreau=SDL_LoadBMP(photo);
    SDL_BlitSurface(carreau,NULL,image,&rectangle);
}

void Memoriser(SDL_Window*ecran,SDL_Surface *image,int **retournemat , int **mat ,int a,int b){ // cette fonction affiche les cartes
    int i,j;                                                                                    // tournées faces
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            char* nom;
            switch(a){
            case 3:
                nom=inttoimageeasy(mat[i][j]) ;break;
            case 4:
                nom=inttoimagemedium(mat[i][j]) ;break;
            case 5:
                nom=inttoimagehard(mat[i][j]) ;break;
            }
            AfficherCarreau(nom,image,i, j,a,b);
            SDL_UpdateWindowSurface( ecran );
        }
    }
}

void affichegrille(SDL_Window*ecran,SDL_Surface *image,int **retournemat , int **mat ,int a,int b){
                                                 //Cette fonction affiche la grille de jeu (cartes)
                                                 //Elle prends en paramètres une fenêtre et une surface ainsi que
                                                 // le tableau qui contient les images
                                                 //ainsi que le tableau permettant de savoir si une carte est retournée

int valeur,i,j;

                                                 // L'affichage des cartes a l'ecran se fait sur a lignes et b colonnes
                                                 //Nous utiliserons donc 2 boucles "pour", des sauts de ligne et des tabulations
                                                 //pour réaliser cet affichage.


for(i=0;i<a;i++){
     for(j=0; j<b; j++){
                                        //Si la carte n'est pas retournée on affiche la carte tournée face cachée
        if (retournemat[i][j]==0){
            char* nom;
            switch(a){
            case 3:
                nom="easy/inverse.bmp" ;break;
            case 4:
                nom="medium/inverse.bmp" ;break;
            case 5:
                nom="hard/inverse.bmp" ;break;
            }
            AfficherCarreau(nom,image,i, j,a,b);
            SDL_UpdateWindowSurface( ecran );

        }
                                            //Sinon si la carte est retournée on affiche son image
        else{
            char* nom;
            switch(a){
            case 3:
                nom=inttoimageeasy(mat[i][j]) ;break;
            case 4:
                nom=inttoimagemedium(mat[i][j]) ;break;
            case 5:
                nom=inttoimagehard(mat[i][j]) ;break;
            }

            AfficherCarreau(nom,image,i, j,a,b);
            SDL_UpdateWindowSurface( ecran );
                                            //si elle n'est que temporairemant retournée, on la laisse tournée

        }
     }
 }

}


#endif // AFFICHAGE_H_INCLUDED
