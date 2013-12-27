all: 
	g++ -o main main.cpp framework/game.cpp `sdl2-config --libs --cflags` -lGLEW
