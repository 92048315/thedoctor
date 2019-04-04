prog:main.o main.o button.o bg.o
	gcc main.o button.o bg.o -lm -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -o prog
main.o:main.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c main.c
button.o:lib/button.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c lib/button.c
bg.o:lib/bg.c
	gcc -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -c lib/bg.c
