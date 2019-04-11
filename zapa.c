#include <zapa.h>
#include <stdlib.h>
#include <stdio>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>

int collision_trigo(  SDL_Rect positionperso, SDL_Surface *image2, SDL_Rect posp, SDL_Rect pose)
{
    int ra,rb,xb,xa,ya,yb,distance;
    ra=(perso->w)/2;/*3oredh l personnage sure 2(rayon)*/
    xa=(posp.x+(perso->w/2));/*yhaded l position taa l personnage

   (yekhou x f weset fel map w yzid l 3orredh taa l perso*/
    ya=(posp.y+(perso->h/2));
    rb=(enemie->w)/2;/*rayon enemie*/
    xb=(pose.x+(enemie->w/2));
    yb=(pose.y+(enemie->h/2));
    distance=sqrt((xa-xb)/*(xa-xb)+( ya+yb)*( ya+yb));/*distance bin zouz hajet*/
    if(distance<=ra+rb)
    {
        return 1 ;
    }
    else
    {
        return 0;
    }
}

