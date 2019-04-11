#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "lib/bg.c"
#include "lib/button.c"
#include "samidroite/jeu.c"


int main(int argc, char const *argv[]) {
  int running=1;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface* screen;
  screen = SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  //Menu BG INIT
  bg menu=initbg(0,0,800,600,"Images/bg/Bgmenu.jpg");
	int play=0;
	int jouer=0;

  //Button init
  button menuButton[4];
  menuButton[0]=initbutton(30,200,278,106,"Images/Button/Play/play.png","Images/Button/Play/play*.png");
  menuButton[1]=initbutton(30,300,278,106,"Images/Button/LoadGame/load.png","Images/Button/LoadGame/load*.png");
  menuButton[2]=initbutton(30,400,278,106,"Images/Button/Settings/settings.png","Images/Button/Settings/settings*.png");
  menuButton[3]=initbutton(30,500,278,106,"Images/Button/Quit/quit.png","Images/Button/Quit/quit*.png");
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
      for(int i=0;i<4;i++)
      {
        if((event.motion.x>menuButton[i].pos.x)&&(event.motion.x<(menuButton[i].pos.x+menuButton[i].pos.w))&&(event.motion.y>menuButton[i].pos.y)&&(event.motion.y<(menuButton[i].pos.y+menuButton[i].pos.h)))
        {
          displaybuttonOnHover(menuButton[i],screen);
		if (i==0) play=1;
        }
        else
        {
		if (i==0) play=0;
          displaybutton(menuButton[i],screen);
        }

      }
    }
    else
    {
	if (event.type==SDL_MOUSEBUTTONDOWN && play == 1)
	{
		jouer=1;
		jouer=jeu(screen);
		jouer=0;
		play=0;
	}

      for(int i=0;i<4;i++)
      {
        displaybutton(menuButton[i],screen);
      }
    }


      SDL_Flip(screen);
  }

}
