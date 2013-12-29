//CPP Libraries:
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <ctime>

//Glew:
#define GLEW_STATIC
#include <GL/glew.h> 
//SDL:
#include <SDL.h>
#include <SDL_opengl.h>

//Game:
#include "framework/game.h"

int main(int argc, char* argv[] ) {
	
	//Setup SDL	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window = SDL_CreateWindow("OpenGL", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(window);

	//Init GLEW:
	glewExperimental = GL_TRUE;
	glewInit();
	SDL_Event windowEvent;
	//Test GLEW:
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	printf("%u\n", vertexBuffer);

	//Seed:
	srand(time(0));
	std::vector<Cell> world = Framework::initial_startup(100);

	
	
	for(std::vector<Cell>::iterator i = world.begin(); i != world.end(); ++i) {
		printf("X:%d, Y:%d, Z: %d \n", i->position.X, i->position.Y, i->position.Z);
	}
	
	while(true) {
		if(SDL_PollEvent(&windowEvent)) {
			if(windowEvent.type == SDL_QUIT) break;
		}
		Framework::update(world);
		printf("Alive: %lu \n", world.size());
		usleep(1000000);
		SDL_GL_SwapWindow(window);
	}
	SDL_GL_DeleteContext(context);
	SDL_Quit();
	return 0;
}
