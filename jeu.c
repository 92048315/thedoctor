#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>



int main() {

SDL_Surface *screen=NULL;
SDL_Surface *fond=NULL, *fond2=NULL, *fond3=NULL;
SDL_Rect positionecran, positionsouris;
SDL_Event event;



int done=1;
int etat=0;


screen=SDL_SetVideoMode(1280,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if (SDL_Init(SDL_INIT_VIDEO)!=0){printf("unable to set 1280*800 video : %s ", SDL_GetError());
return(-1);
}


SDL_FillRect(screen,0,SDL_MapRGB(screen ->format,0,0,0));
positionecran.x=0;
positionecran.y=0;
SDL_BlitSurface(fond,NULL,screen,&positionecran);

fond=IMG_Load("background.png");
if (fond==NULL){
printf("Unable to load image : %s \n",SDL_GetError());
return -1;
}

fond2=IMG_Load("lose.png");
if (fond2==NULL){
printf("Unable to load image : %s \n",SDL_GetError());
return -1;
}

fond3=IMG_Load("win.png");
if (fond3==NULL){
printf("Unable to load image : %s \n",SDL_GetError());
return -1;
}




while (done){
SDL_WaitEvent(&event);
switch(event.type){
case SDL_QUIT: done=0;
break;

case SDL_MOUSEMOTION : positionsouris.x=event.motion.x;
			positionsouris.y=event.motion.y;
break;

case SDL_MOUSEBUTTONDOWN : positionsouris.x=event.motion.x;
			     positionsouris.y=event.motion.y;
	if ((positionsouris.x>=425 && positionsouris.x<=475 && positionsouris.y>=440 && positionsouris.y<= 550)||(positionsouris.x>=522 && positionsouris.x<=573 && positionsouris.y>=440 && positionsouris.y<= 550)||(positionsouris.x>=637 && positionsouris.x<=687 && positionsouris.y>=440 && positionsouris.y<= 550)){
		
		SDL_FreeSurface(fond);		
		SDL_BlitSurface(fond2,NULL,screen,&positionecran);
		SDL_Flip(screen);
		etat=1;
	}
	else{
		SDL_FreeSurface(fond);		
		SDL_BlitSurface(fond3,NULL,screen,&positionecran);
		SDL_Flip(screen);
		etat=2;
	}
		
break;

}


if (etat ==0){
SDL_BlitSurface(fond,NULL,screen,&positionecran);
SDL_Flip(screen);
}
else if (etat ==1){
SDL_BlitSurface(fond2,NULL,screen,&positionecran);
SDL_Flip(screen);
}
else{
SDL_BlitSurface(fond3,NULL,screen,&positionecran);
SDL_Flip(screen);
}


}


SDL_FreeSurface(fond);


return 0;
}
