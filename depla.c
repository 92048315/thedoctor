void deplacerdroite(int arg[],SDL_Rect *pos, int direction)
{
	int i=0;
	while (i<255)
	{
		direction=SLDK_RIGHT;
		pos->x++;
	}
	SDL_FillRect(ecran,NULL,Map_RGB(ecran->format,255,255,255));

}
void deplacergauche(int arg[],SDL_Rect *pos, int direction)
{

int i;
	while ((i>=254)&&(i!=0))
	{
		direction=SLDK_LEFT;
		pos->x--;
	}

SDL_FillRect(ecran,NULL,Map_RGB(ecran->format,255,255,255));
}

void deplacer(int arg[],SDL_Rect *pos, int direction)
{
deplacerdroite(arg[],&pos,direction);
deplacergauche(arg[],&pos,direction);
}