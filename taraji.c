#include <stdio.h>
#include "SDL/SDL.h"
#include"SDL/SDL_image.h"
#include <SDL/SDL_mixer.h>


int main (int argc, char *argv[])
{
SDL_Surface *screen= NULL ;
SDL_Surface *image=  NULL ;
SDL_Surface *image2= NULL;
SDL_Surface *image3= NULL;


SDL_Event event;
Mix_Music *mix;


int done =1;
SDL_Rect positionecran,positionecran2,positionecran3;
int back_x=0;
int back_y=0;
int coin_x=110;
int coin_y=30;
int coeur_x=150;
int coeur_y=30 ;

char pause ;
if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS, 1024)==-1)
	{
		printf("%s",Mix_GetError());
	}
mix=Mix_LoadMUS("menu.mp3");

if (SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initialize SDL: %s \n ",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(500,250, 32,SDL_HWSURFACE | SDL_DOUBLEBUF);
if (screen==NULL){
printf("unable to set video mode : %s \n",SDL_GetError());
return 1;
}
image=SDL_LoadBMP/*Chargez un fichier Windows
 BMP dans une SDL_Surface.*/("lvl 0 0 0.bmp");
if(image==NULL){
printf("unable to load bitmap : %s \n",SDL_GetError());
return 1;
}
image2=SDL_LoadBMP/*Chargez un fichier Windows
 BMP dans une SDL_Surface.*/("coin.bmp");



if(image2==NULL){
printf("unable to load bitamp : %s \n ",SDL_GetError());
SDL_SetColorKey(image2, SDL_SRCCOLORKEY, SDL_MapRGB(image2->format,255,255,255));
return 1;
}
image3=SDL_LoadBMP/*Chargez un fichier Windows
 BMP dans une SDL_Surface.*/("coeur.bmp");

if(image3==NULL){
printf("unable to load bitamp : %s \n ",SDL_GetError());
SDL_SetColorKey(image3, SDL_SRCCOLORKEY, SDL_MapRGB(image3->format,255,255,255));
return 1;
}
	while (done)
{
	positionecran.x =0;
	positionecran.y =0;
	positionecran2.x =coin_x;
	positionecran2.y =coin_y ;
	positionecran3.x=coeur_x ;
        positionecran3.y=coeur_y ;


 	SDL_BlitSurface(image, NULL , screen,   &positionecran);
	SDL_BlitSurface(image2, NULL , screen , &positionecran2);
        SDL_BlitSurface(image3, NULL , screen , &positionecran3);

SDL_Flip(screen);
}

SDL_FreeSurface(image);
SDL_FreeSurface(image2);
SDL_FreeSurface(image3);
Mix_FreeMusic(mix);

SDL_Quit();

return 0;
}



