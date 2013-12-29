all: 
	g++ -o main main.cpp framework/game.cpp framework/foundation/foundation.cpp `sdl2-config --libs --cflags` -lGLEW -g
