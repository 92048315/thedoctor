#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "maths.h"
int scorlling(int argc, char* argv[]);
int collisionAB(SDL_Surface *iA,SDL_Surface *iB,SDL_Rect pA,SDL_Rect pB);
void deplaceralea(int arg[],SDL_Rect *pos, int direction);
int aff(int argc, char *argc[]);