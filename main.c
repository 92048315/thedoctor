#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


#include "lib/button.h"
#include "lib/bg.h"


int main(int argc, char const *argv[]) {
  int running=1;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface *screen;
  screen = SDL_SetVideoMode(800,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  //Menu BG INIT
  bg menu=initbg(0,0,800,600,"Images/bg/Bgmenu.png");

  //Button init
  button menuButton[4];
  menuButton[0]=initbutton(200,200,278,106,"Images/Button/Play/play.png","Images/Button/Play/play*.png");
  menuButton[1]=initbutton(200,400,278,106,"Images/Button/Quit/quit.png","Images/Button/Quit/quit*.png");


  //Display SplachScreen
  splachscreen(screen);
  SDL_Event event;
  while (running==1) {
      displaybg(menu,screen);

    SDL_PollEvent(&event);
    if(event.type==SDL_QUIT)
      running=0;
    if(event.type==SDL_MOUSEMOTION)
    {
      for(int i=0;i<2;i++)
      {
        if((event.motion.x>menuButton[i].pos.x)&&(event.motion.x<(menuButton[i].pos.x+menuButton[i].pos.w))&&(event.motion.y>menuButton[i].pos.y)&&(event.motion.y<(menuButton[i].pos.y+menuButton[i].pos.h)))
        {
          displaybuttonOnHover(menuButton[i],screen);
        }
        else
        {
          displaybutton(menuButton[i],screen);
        }

      }
    }
    else
    {
      for(int i=0;i<2;i++)
      {
        displaybutton(menuButton[i],screen);
      }
    }


      SDL_Flip(screen);
  }

}
