#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "maths.h"
#include <khedmti.h>
int main()
{

int aff(int argc, char *argc[])
{
bool continuer=true;
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *ecran = NULL;
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
ecran = SDL_SetVideoMode(ettoul,eloordh,24,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_Surface *background = IMG_Load(el background.png);
SDL_Rect pos;
SDL_WM_SetCaption(lektiba,NULL);
while (continuer)
{
pos.x=100;
pos.y=250;
SDL_Blitsurface(background,NULL,ecran,&pos);
SDL_Flip(ecran);



}
return 0;





}

//scrolling (j'etais obligé besh nekhdmou)

int scorlling(int argc, char* argv[])
{
bool continuer = true;
SDL_Event event;
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *ecran = NULL;
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
ecran = SDL_Surface *background=IMG_Load(el fond.png);
SDL_Rect pos,p;
pos.y=0;
pos.x=0;
SDL_WM_SetCaption(test,NULL);
while(continuer)
{
SDL_Blitsurface(background,NULL,ecran,&p);
SDL_PollEvent(&event);
switch(event.type)
{
case SDL_QUIT;
continuer=false;
break;
case SDL_KEYDOWN;
if (event.key.keysym.sym==SDLK_RIGHT)
{
pos.x-=2;
}
if(event.key.keysym.sym==SDLK_LEFT)
{
pos.x+=2;
}
break;

}
p=pos;
SDL_Flip(ecran);




}
return 0;



//deplacement aleatoire de l'ennemi
void deplaceralea(int arg[],SDL_Rect *pos, int direction)
{
int i=0;
while(i<24)
{
direction = LEFT ;
i++;

}
if (i==23)
{
while(i>-1)
{
i--;
direction=RIGHT;



}



}





}

//collision ki ymes el joueur mte3na fel ennemi yadhrbou
int collision_trigo(SDL_Surface *perso  ,SDL_Surface *enemie,SDL_Rect posp,SDL_Rect pose )
{

int ra,rb,xb,xa,ya,yb,distance;
ra=(perso->w)/2;
xa=(posp.x+(perso->w/2));
ya=(posp.y+(perso->h/2));
rb=(enemie->w)/2;
xb=(pose.x+(enemie->w/2));
yb=(pose.y+(enemie->h/2));
distance=sqrt((xa-xb)*(xa-xb)+( ya+yb)*( ya+yb));
if(distance<=ra+rb)
{
return 1 ;
}
else
{
return 0;
}


int collisionAB(SDL_Surface *iA,SDL_Surface *iB,SDL_Rect pA,SDL_Rect pB)
{

    if  ((pA.y + iA->h) < pB.y )
      return 0;
    else if ( pA.y > (pB.y + iB->h))
      return 0;
    else if ( (pA.x + iA->w) < pB.x )
      return 0;
    else if ( pA.x > (pB.x +  iB->w))
      return 0;
return 1;

}

return 0;
}