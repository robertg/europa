//CPP Stuff:
#include <vector>
//Glew:
#define GLEW_STATIC
#include <GL/glew.h> 

//SDL:
#include <SDL.h>
#include <SDL_opengl.h>

//Game:
#include "../framework/foundation/foundation.h"

namespace Gfx {
	void draw(std::vector<Cell> &world);
}
