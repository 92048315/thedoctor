#include <stdio.h>
#include "/usr/include/SDL/SDL.h"
#include "/usr/include/SDL/SDL_image.h"
#include "/usr/include/SDL/SDL_mixer.h"
int main(void)
{
			SDL_Rect positionperso;/*position*/
	 		SDL_Event event;
 int done = 0;
 while(!done){

                        switch(event.type)
                        {
case SDL_QUIT: done=0;
break;
case SDL_KEYDOWN :
switch(event.key.keysym.sym)
{ case SDLK_ESCAPE: done=0;
break;
case SDLK_UP : positionperso.y -=20;
break;
case SDLK_DOWN : positionperso.y +=20;
break;
case SDLK_RIGHT : positionperso.x +=20;
break;
case SDLK_LEFT : positionperso.x -=20;
break;


default :
break;
}
break;

case SDL_MOUSEMOTION : positionperso.x=event.motion.x;
			positionperso.y=event.motion.y;
break;


default:
break;

}
}


        return 0;
}


