//CPP Libraries:
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <iostream>

//Glew:
#define GLEW_STATIC 
#include <GL/glew.h> 
//SDL:
#include <SDL.h>
#include <SDL_opengl.h>

//Game:
#include "framework/game.h"
#include "gfx/gfx.h"

int main(int argc, char* argv[] ) {

	//Ask user:
	unsigned int startup_size = 0;
	unsigned int radius_size = 0;
	std::cout << "WELCOME TO 3D CONWAY'S GAME OF LIFE, By Robert Gawdzik!\nHow many cells do you want to display?: ";
	std::cin >> startup_size;
	std::cout << "Awesome! Now what is the radius of the starting area?: ";
	std::cin >> radius_size;

	//INIT GAME:
	//---------
	//Seed:
	srand(time(0));
	std::vector<Cell> world = Framework::initial_startup(startup_size, radius_size);
	//---------

	//Setup SDL	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window = SDL_CreateWindow("OpenGL", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(window);

	//Init GLEW:
	glewExperimental = GL_TRUE;
	glewInit();
	SDL_Event windowEvent;


	//Display all initial positions:	
	//for(std::vector<Cell>::iterator i = world.begin(); i != world.end(); ++i) {
	//    printf("X:%d, Y:%d, Z: %d \n", i->position.X, i->position.Y, i->position.Z);
	//}

	float rotate_x = 40;
	float rotate_y = 40;
	float timer_reset = 0;

	while(true) {
		if(SDL_PollEvent(&windowEvent)) {
			if(windowEvent.type == SDL_QUIT) break;
		}

		//Update:
		timer_reset++;
		if(timer_reset == 4000) {
			Framework::update(world);
			printf("Alive: %lu \n", world.size());
			timer_reset = 0;
		}

		//Draw:	
		rotate_x += 0.01f;
		rotate_y += 0.01f;
		Gfx::draw(world, rotate_x, rotate_y);

		SDL_GL_SwapWindow(window);
	}
	SDL_GL_DeleteContext(context);
	SDL_Quit();
	return 0;
}
