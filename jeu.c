0
positionecran.y=0;
positionecran.w=1280;
positionecran.h=720;
image=IMG_Load("samidroite/backG.jpg");

if(!image) {
  printf("IMG_Load: %s\n", IMG_GetError());
// handle error
}
    int continuer=1;
    SDL_Event evenement;

    //initialisation personnage

    SDL_Surface *personnage;


    personnage = IMG_Load("samidroite/000.png");
positionperso.x=0;
positionperso.y=400;


    SDL_EnableKeyRepeat(10,10);

while(continuer){
SDL_BlitSurface(image,&positionecran,ecran,&camera);
SDL_BlitSurface(personnage,NULL,ecran,&positionperso);
SDL_Flip(ecran);



SDL_WaitEvent(&event);
switch(event.type)
{
case SDL_QUIT: continuer=0;
break;

case SDL_KEYDOWN:
if (event.key.keysym.sym==SDLK_RIGHT)
{
  positionecran.x+=2;
}
if(event.key.keysym.sym==SDLK_LEFT)
{
if (positionecran.x>0)positionecran.x-=2;
}
break;

default:
break;







}








}

return 0;
}
