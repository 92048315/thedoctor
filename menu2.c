#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "menu2.h"

int main(int argc, char *argv[])

{
TTF_Init();

if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) < 0) {
	    printf("Unable to open audio!\n");
	    exit(1);
		}
Mix_Music *song=NULL;
Mix_Music *intro=NULL;
Mix_Chunk *click=NULL;
		//song=Mix_LoadMUS("dougga.wav");
Mix_VolumeMusic(MIX_MAX_VOLUME);
                intro=Mix_LoadMUS("intro.ogg");
Mix_PlayMusic(intro, MIX_MAX_VOLUME);
ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
posbackground.x = 0;
posbackground.y = 0;
while(y<248){
sprintf(menu,"intro/%d.jpg.jpg",y);
					intro_[y]=IMG_Load(menu); 
SDL_BlitSurface(intro_[y],NULL,ecran,&posbackground);
SDL_Delay(20);
y++;
SDL_Flip(ecran);

SDL_FreeSurface(intro_[y]);
}


y=0;
while(y<235){
sprintf(menu,"intro2/%d.jpg.jpg",y);
					intro2_[y]=IMG_Load(menu); 
SDL_BlitSurface(intro2_[y],NULL,ecran,&posbackground);
SDL_Delay(20);
y++;
SDL_Flip(ecran);
SDL_FreeSurface(intro2_[y]);

}


click=Mix_LoadWAV("bref.ogg");
Mix_VolumeMusic(MIX_MAX_VOLUME);
//Mix_PlayMusic(song, MIX_MAX_VOLUME);
police = TTF_OpenFont("police.ttf", 65);
texte = TTF_RenderText_Blended(police, " ", CN);

while(run){
ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);



SDL_WM_SetCaption("school tale", NULL);

 
   posplay1.x=218;
posplay1.y=238;

possetting1.x=218;
possetting1.y=345.7;

posexit1.x=218;
posexit1.y=452;

posplay2.x=218;
posplay2.y=238;

possetting2.x=218;
possetting2.y=345.7;

posexit2.x=218;
posexit2.y=452;


    
    //posson.x=100;
    //posson.y=300;
    on.x=300;
    on.y=300;
    of.x=500;
    of.y=300;
posback.x=500;
posback.y=440;
text.x=50;
text.y=0;
posjoystic.x=543;
posjoystic.y=230;
posclavier.x=328;
posclavier.y=230;
possouris.x=152;
possouris.y=230;

x=2;
background =  IMG_Load("Bgmenu.jpg");

    play = IMG_Load("play.png");
    setting =  IMG_Load("setting.png");

    exite = IMG_Load("exit.png");
    play2 =  IMG_Load("play2.png");
    setting2=IMG_Load("setting2.png");

    exit2=IMG_Load("exit2.png");
    //son=IMG_Load("son.png");
    on1=IMG_Load("on1.png");
    on2=IMG_Load("on2.png");
    of1=IMG_Load("of1.png");
    joystic=IMG_Load("joystic.png");
    souris=IMG_Load("clavier.png");
    clavier=IMG_Load("souris.png");
    joystic2=IMG_Load("joystic2.png");
    souris2=IMG_Load("clavier2.png");
    clavier2=IMG_Load("souris2.png");

    back = IMG_Load("21.png");
of2=IMG_Load("of2.png");

				   //{//loading menu principale
					sprintf(menu,"image/%d.jpg",i);
					Menu_anime[i]=IMG_Load(menu); 
 
SDL_BlitSurface(Menu_anime[i],NULL,ecran,&posbackground);
SDL_Delay(150);
				     
SDL_BlitSurface(play, NULL, ecran, &posplay1);
SDL_BlitSurface(setting, NULL, ecran, &possetting1);
SDL_BlitSurface(help, NULL, ecran, &poshelp1);
SDL_BlitSurface(exite, NULL, ecran, &posexit1);
SDL_BlitSurface(texte, NULL, ecran, &text);
i++;

 SDL_Flip(ecran);
if(i>21){i=1;}


if (curseur==1){SDL_BlitSurface(play2, NULL, ecran, &posplay2);
 curseurr=0;}
 if (curseur==2){SDL_BlitSurface(setting2, NULL, ecran, &possetting2);
 curseurr=0;}
   
 if (curseur==4){SDL_BlitSurface(exit2, NULL, ecran, &posexit2);
 curseurr=0;}
SDL_Flip(ecran);
if (curseurr==1){SDL_BlitSurface(play2, NULL, ecran, &posplay2);
 curseur=0;}
 if (curseurr==2){SDL_BlitSurface(setting2, NULL, ecran, &possetting2);
 curseur=0;}
   
 if (curseurr==4){SDL_BlitSurface(exit2, NULL, ecran, &posexit2);
 curseur=0;}
SDL_Flip(ecran);
while (SDL_PollEvent(&event))
       {//while event
 switch(event.type)
        {//switch event
            case SDL_QUIT:
		{// case sdl quit
            run = 0;
		}
case SDL_MOUSEMOTION:
{//SDL_MOUSEMOTION
            	if ((event.motion.x>posplay1.x )&&(event.motion.x<posplay1.x+posplay1.w)&&(event.motion.y>posplay1.y)&&(event.motion.y<posplay1.y+posplay1.h))
            	{//loading 2eme button start
            		curseur=1; Mix_PlayChannel(-1,click,0);
}
            	if ((event.motion.x>possetting1.x)&&(event.motion.x<possetting1.x+possetting1.w)&&(event.motion.y>possetting1.y)&&(event.motion.y<possetting1.y+possetting1.h))
            	{
            		curseur=2;Mix_PlayChannel(-1,click,0);
}
            	if ((event.motion.x>posexit1.x)&&(event.motion.x<posexit1.x+posexit1.w)&&(event.motion.y>posexit1.y)&&(event.motion.y<posexit1.y+posexit1.h))
            	{
            		curseur=4;Mix_PlayChannel(-1,click,0);

            	}

}
case SDL_KEYDOWN:
                {
				if (event.key.keysym.sym==SDLK_DOWN)
				{

					if (c==1)			  {curseurr=1;c++;Mix_PlayChannel(-1,click,0);}
													 else if (c==2){curseurr=2;c++;Mix_PlayChannel(-1,click,0);}
					else if (c==3){curseurr=3;c++;Mix_PlayChannel(-1,click,0);}	
else if (c==4){curseurr=4;c++;Mix_PlayChannel(-1,click,0);}	


		if(c>4){c=1;}
		}if (event.key.keysym.sym==SDLK_UP)
				{
					 if (c1==4)			  {curseurr=4;c1--;Mix_PlayChannel(-1,click,0);}
													 else if (c1==3){curseurr=3;c1--;Mix_PlayChannel(-1,click,0);}
					else if (c1==2){curseurr=2;c1--;Mix_PlayChannel(-1,click,0);}
else if (c1==1){curseurr=1;c1--;Mix_PlayChannel(-1,click,0);}


		if(c1<1){c1=4;}}

case SDL_MOUSEBUTTONUP:
{
        if ((event.button.button == SDL_BUTTON_LEFT)&&(curseur==4)){

           run=0;
 }
           	
SDL_Flip(ecran);

        if ((event.button.button == SDL_BUTTON_LEFT)&&(curseur==1)){
int i ;
/*SDL_Surface* screenTEMP = SDL_ConvertSurface(ecran, ecran->format, SDL_SWSURFACE);//Copie du contenu du screen
						for (i = 0; i < 180; i++)//Rotozoom avant chaque debut d'un niveau
						{
							SDL_Surface* effect = rotozoomSurface(screenTEMP, i, 1.0, SMOOTHING_ON);
							SDL_BlitSurface(effect, NULL, ecran, NULL);
							SDL_FreeSurface(effect);
							SDL_Flip(ecran);
						}*/
y=0;
while(y<743){
sprintf(menu,"cine/%d.jpg",y);
					cinematique[y]=IMG_Load(menu); 
SDL_BlitSurface(cinematique[y],NULL,ecran,&posbackground);
//SDL_Delay(20);
y++;
SDL_Flip(ecran);
SDL_FreeSurface(cinematique[y]);

}

}
        if ((event.button.button == SDL_BUTTON_LEFT)&&(curseur==2)){

           while(x==2){

 
SDL_BlitSurface(Menu_anime[i],NULL,ecran,&posbackground);
SDL_Delay(150);
				     
SDL_BlitSurface(son, NULL, ecran, &posson);
SDL_BlitSurface(on1, NULL, ecran, &on);
SDL_BlitSurface(of1, NULL, ecran, &of);
SDL_BlitSurface(back, NULL, ecran, &posback);
SDL_BlitSurface(joystic, NULL, ecran, &posjoystic);
SDL_BlitSurface(souris, NULL, ecran, &possouris);
SDL_BlitSurface(clavier, NULL, ecran, &posclavier);
SDL_BlitSurface(texte, NULL, ecran, &text);

i++;

 SDL_Flip(ecran);
if(i>9){i=1;}
while (SDL_PollEvent(&event))
       {//while event
 switch(event.type)
        {case SDL_MOUSEMOTION:
if ((event.motion.x>on.x )&&(event.motion.x<on.x+on.w)&&(event.motion.y>on.y)&&(event.motion.y<on.y+on.h))
{curseur2=1;}
if ((event.motion.x>of.x )&&(event.motion.x<of.x+of.w)&&(event.motion.y>of.y)&&(event.motion.y<of.y+of.h))
{curseur2=2;}
if ((event.motion.x>posjoystic.x )&&(event.motion.x<posjoystic.x+posjoystic.w)&&(event.motion.y>posjoystic.y)&&(event.motion.y<posjoystic.y+posjoystic.h))
{curseur2=4;}
if ((event.motion.x>posclavier.x )&&(event.motion.x<posclavier.x+posclavier.w)&&(event.motion.y>posclavier.y)&&(event.motion.y<posclavier.y+posclavier.h))
{curseur2=5;}
if ((event.motion.x>possouris.x )&&(event.motion.x<possouris.x+possouris.w)&&(event.motion.y>possouris.y)&&(event.motion.y<possouris.y+possouris.h))
{curseur2=6;}
if ((event.motion.x>posback.x )&&(event.motion.x<posback.x+posback.w)&&(event.motion.y>posback.y)&&(event.motion.y<posback.y+posback.h))
{curseur2=3;}

case SDL_MOUSEBUTTONUP:

        if ((event.button.button == SDL_BUTTON_LEFT)&&(curseur2==3)){x=0;}
 
SDL_Flip(ecran);
       if ((event.button.button == SDL_BUTTON_LEFT)&&(curseur2==1)){
     if(Mix_PausedMusic()==1){Mix_ResumeMusic();}
}
if ((event.button.button == SDL_BUTTON_LEFT)&&(curseur2==2)){
  if(Mix_PlayingMusic()==1){Mix_PauseMusic();}
}
}
}
if (curseur2==1){SDL_BlitSurface(on2, NULL, ecran, &on);
SDL_Flip(ecran); }
if (curseur2==2){SDL_BlitSurface(of2, NULL, ecran, &of);
SDL_Flip(ecran); }
if (curseur2==4){SDL_BlitSurface(joystic2, NULL, ecran, &posjoystic);
SDL_Flip(ecran); }
if (curseur2==5){SDL_BlitSurface(clavier2, NULL, ecran, &posclavier);
SDL_Flip(ecran); }
if (curseur2==6){SDL_BlitSurface(souris2, NULL, ecran, &possouris);
SDL_Flip(ecran); }

 }
  }        	
SDL_Flip(ecran);
}
}
}
}
}
SDL_FreeSurface(background); /* On libère la surface */

SDL_FreeSurface(play);
SDL_FreeSurface(setting);
SDL_FreeSurface(exite);

 SDL_Quit();
  SDL_Quit();
TTF_CloseFont(police);

    return EXIT_SUCCESS;
}
