
#ifndef CODEDEJEU_H_INCLUDED
#define CODEDEJEU_H_INCLUDED
#include "header.h"
#include "affichage.h"
#include "menudejeu.h"
#include "findejeu.h"

typedef struct __player{   //structure de joueur
    char name[20] ;
    char username[20] ;
    char password[20] ;
    int score;
}player;
typedef struct __player* Player;

typedef struct _utilisateur{     //struvture utilisateur
    int score=0;
    char *nom;
}utilisateur;

void modifierscore(player *ptr,int score);
//FONCTION INITTABS
void initmat(int **mat, int **retournemat,int a,int b){
                                              //Declaration des variables
 int i,j;                                     //itérateurs
                                              //Initialisation de mat[][] et de retournemat[][] a "0"
                                              //Les tableaux position[][] et estretourne[][] auront les valeurs de toutes leurs cases à 0
    for(i=0;i<a;i++){
        for(j=0; j<b; j++){
           mat[i][j] = 0;
           retournemat[i][j] = 0;
        }
    }
}

//FONCTION INITVALEUR
void initval(int val[],int n){

  int i,j;
                                  //Cette fonction rempli un tableau indéxé de 0 à 31 (32 cases) avec des
                                  //valeurs de 1 à 16, chaque numéro de 1 à 16 sera en double
  for (i=0; i<n/2; i++){
                                  //les index 0 à 15 prennent les valeurs de 1 à 16
    val[i]=i+1;}
  for (j=n/2; j<n; j++){
                                  //les index 16 à 31 prennent les valeurs de 1 à 16
    val[j]=1+j-n/2;}
}

void remplirmat(int val[], int **mat,int a,int b){  // remplir la matrice par des valeurs de 1 à 16 d'une maniere aléatoire

 int i,j,index,x=a*b;
 for(i=0; i<a; i++){
     for(j=0; j<b; j++){
        index =rand() % x;
        mat[i][j]=val[index];
        int k;
        int var=val[index];
        for(k=index;k<x-1;k++){
          val[k]=val[k+1];
        }
        val[x-1]=var;
        x--;
     }
  }
}

void codejeu(SDL_Window*ecran,SDL_Surface *surface,SDL_Event event,int a,int b,int joueurs,char*names[]){

  int len=0;
  int val[a*b];
  initval(val,a*b);
  int *ptr1,*ptr2, **mat,**retournemat;
  len = sizeof(int *) * a + sizeof(int) * b * a;
  mat = (int **)malloc(len);
  retournemat = (int **)malloc(len);
  ptr1 = (int *)(mat + a);                                             //initialisation et allocation de memoire des variables
  ptr2 = (int *)(retournemat + a);
  int k;
  for(k = 0; k < a; k++){
    mat[k] = (ptr1 + b * k);
    retournemat[k] = (ptr2 + b * k);}
  initmat(mat, retournemat,a,b);
  remplirmat(val, mat ,a,b);

Memoriser(ecran,surface,retournemat, mat,a,b);           //afficher la grille qu'on doit la memoriser

switch(a){
case 3:Sleep(4000);break;
case 4:Sleep(6000);break;                       // on sleep la grille un nombre de seconde ca depent du mode de jeu
case 5:Sleep(8000);break;
}

affichegrille(ecran,surface,retournemat, mat,a,b);      //on retourne la grille pour commencer je jeu

int h=520/a,w=600/b;

int gagne=0,compteur=0;
int essaie=0;
utilisateur j1;j1.nom=names[0]; //on assicie à chaque utilisateur son nom et un score de 0
utilisateur j2;j2.nom=names[1];
utilisateur j3;j3.nom=names[2];

unsigned int lastTime = 0, currentTime;
int variable=0;

while(gagne==0){

        currentTime = SDL_GetTicks();
        if (currentTime > lastTime + 1000) {     // un minuteur
        timer(surface,variable);
        variable++;
        lastTime = currentTime;
        }
        if(variable==11){                  //si le countdown de 10seconds découle , le tour passe immédiatement à l'autre joueur
            essaie++;
            essaie%=joueurs;
            variable=0;
        }

        switch(joueurs){                  // l'affichage du score dépend du nounbre de joueurs
        case 1:
            affichescore1(surface,inttoimagescore(j1.score));break;
        case 2:
            affichescore1(surface,inttoimagescore(j1.score));
            affichescore2(surface,inttoimagescore(j2.score));break;
        case 3:
            affichescore1(surface,inttoimagescore(j1.score));
            affichescore2(surface,inttoimagescore(j2.score));
            affichescore3(surface,inttoimagescore(j3.score));break;
        }
        fleche(surface,essaie);              //on affiche la fleche qui montre le joueur qui va jouer
        int retour=0,i,j;
        int lig,col,valeur;
        SDL_PollEvent(&event);
        switch(event.type){
        case SDL_QUIT:
        exit(0);
        break;
        case SDL_MOUSEBUTTONDOWN:
           // printf("%dx     %dy\n",event.button.x,event.button.y);
            if(event.button.button==SDL_BUTTON_LEFT &&event.button.clicks==1){
                if(event.button.x>=30&&event.button.x<=600 &&event.button.y>=25&&event.button.y<=520){
            lig=event.button.y/h;                              //la i eme ligne
            col=event.button.x/w;                              //le j eme colonne
            if(retournemat[lig][col]!=2){                      //si la carte n'est pas encore retounée
            retournemat[lig][col]=1;                           //on donne à cette catre la valeur 1 en attendant l'autre carte pour faire le test
            valeur=mat[lig][col];
            affichegrille(ecran,surface,retournemat, mat,a,b);    // on affiche la carte choisie
            compteur++;}                                          //on incrémente le compteur par 1
             }
            }
        break;
        }
        Sleep(200);  // pour qu'il n'ya pas chevauchement entre les évenements
if(compteur==2){                                        //si le joueur a retourné deux cartes
    int carreau=0,valeur1,valeur2,lig1,col1,lig2,col2;
    for(i=0;i<a;i++){
          for(j=0;j<b;j++){
            if(retournemat[i][j]==1){
                carreau++;
                if(carreau==1){
                 valeur1=mat[i][j];                      //ici on cherche de comparer les valeurs de la 1 ere carte avec la 2 eme
                 lig1=i;col1=j;
                }
                if(carreau==2){
                 valeur2=mat[i][j];
                 lig2=i;col2=j;
                }
            }}}
    if(valeur1==valeur2){                              //si ils sont égales
        retournemat[lig1][col1]=2;                     // on retourne les deux cartes définitivement
        retournemat[lig2][col2]=2;
        if (joueurs ==1){
            j1.score +=1;}                            // on incremente le score du joueur par 1
        else if(joueurs==2){
            switch(essaie){
                case 0 : j1.score +=1;break;
                case 1 : j2.score +=1;break;
            }
        }
        else{
            switch(essaie){
                case 0:j1.score +=1;break;
                case 1:j2.score +=1;break;
                case 2:j3.score +=1;break;
            }
        }
    }
    else{                                  //si les deux cartes ne sont pas les memes alors on passe le tour à l'autre joueur
        fleche(surface,essaie);
        retournemat[lig1][col1]=0;         // et on retourne les deux cartes pour continuer le jeu
        retournemat[lig2][col2]=0;
        essaie++;
        essaie%=joueurs;
        variable=0;
    }

    compteur=0;

}
affichegrille(ecran,surface,retournemat, mat,a,b);     // on affiche la grille du jeu
int k,l;
for(k=0;k<a;k++){
    for(l=0;l<b;l++){
        if(retournemat[k][l]==2){           //ici on compte si toutes les cartes sont affichées alors le jau est fini
            retour++;}}}
if(retour==a*b){gagne=1;}
else{gagne=0;}

}
//enregistrement du score !!!
FILE *fp=fopen("listjoueursprovisoire.txt","r");
Player ptr=(Player)malloc(sizeof(player)) ;
char *strscore=(char*)malloc(sizeof(int)) ;                // on modifie le score des joueurs dans le fichier
rewind(fp);
switch(joueurs){           // selon le nombre de joueurs, on importe les données du fichiers
case 1:
    fscanf(fp,"%s %s %s %s\n ",ptr->name,ptr->username,ptr->password,strscore);
    ptr->score=atoi(strscore);
    modifierscore(ptr,j1.score);break;
case 2:
    fscanf(fp,"%s %s %s %s\n ",ptr->name,ptr->username,ptr->password,strscore);
    ptr->score=atoi(strscore);
    modifierscore(ptr,j1.score);
    fscanf(fp,"%s %s %s %s\n ",ptr->name,ptr->username,ptr->password,strscore);
    ptr->score=atoi(strscore);
    modifierscore(ptr,j2.score);break;
case 3:
    fscanf(fp,"%s %s %s %s\n ",ptr->name,ptr->username,ptr->password,strscore);
    ptr->score=atoi(strscore);
    modifierscore(ptr,j1.score);
    fscanf(fp,"%s %s %s %s\n ",ptr->name,ptr->username,ptr->password,strscore);
    ptr->score=atoi(strscore);
    modifierscore(ptr,j2.score);
    fscanf(fp,"%s %s %s %s\n ",ptr->name,ptr->username,ptr->password,strscore);
    ptr->score=atoi(strscore);
    modifierscore(ptr,j3.score);break;
}
fclose(fp);
//remove("listjoueursprovisoire.txt"); // on supprime ce fichier après la fin du jeu

if(j1.score > j2.score && j1.score > j3.score){
    findejeu(j1.nom,j1.score);
}
else if(j2.score > j1.score && j2.score > j3.score){
    findejeu(j2.nom,j2.score);                               //on affiche la page qui donne le gagnant avec son score
}
else if(j3.score > j1.score && j3.score > j2.score){
    findejeu(j3.nom,j3.score);
}
else if(j3.score == j1.score || j3.score == j2.score || j1.score == j2.score){   //en cas d'égalité
    findejeu(NULL,0);
}

}

#endif // CODEDEJEU_H_INCLUDED
