all: 
	g++ -o main main.cpp `sdl2-config --libs --cflags` -lGLEW
