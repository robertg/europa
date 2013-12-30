#//CPP Stuff:
#include <vector>
//Glew:
#define GLEW_STATIC
#include <GL/glew.h> 

//SDL:
#include <SDL.h>
#include <SDL_opengl.h>

#include "gfx.h"

void Gfx::draw(std::vector<Cell> &world) {
	for(std::vector<Cell>::iterator it = world.begin(); it != world.end(); ++it) {

		//Multi-colored side - FRONT
		glBegin(GL_POLYGON);

		glColor3f( 1.0, 0.0, 0.0 );     
		glVertex3f(  0.5, -0.5, -0.5 );      // P1 is red
		glColor3f( 0.0, 1.0, 0.0 );     
		glVertex3f(  0.5,  0.5, -0.5 );      // P2 is green
		glColor3f( 0.0, 0.0, 1.0 );     
		glVertex3f( -0.5,  0.5, -0.5 );      // P3 is blue
		glColor3f( 1.0, 0.0, 1.0 );     
		glVertex3f( -0.5, -0.5, -0.5 );      // P4 is purple

		glEnd();

		// White side - BACK
		glBegin(GL_POLYGON);
		glColor3f(   1.0,  1.0, 1.0 );
		glVertex3f(  0.5, -0.5, 0.5 );
		glVertex3f(  0.5,  0.5, 0.5 );
		glVertex3f( -0.5,  0.5, 0.5 );
		glVertex3f( -0.5, -0.5, 0.5 );
		glEnd();

		// Purple side - RIGHT
		glBegin(GL_POLYGON);
		glColor3f(  1.0,  0.0,  1.0 );
		glVertex3f( 0.5, -0.5, -0.5 );
		glVertex3f( 0.5,  0.5, -0.5 );
		glVertex3f( 0.5,  0.5,  0.5 );
		glVertex3f( 0.5, -0.5,  0.5 );
		glEnd();

		// Green side - LEFT
		glBegin(GL_POLYGON);
		glColor3f(   0.0,  1.0,  0.0 );
		glVertex3f( -0.5, -0.5,  0.5 );
		glVertex3f( -0.5,  0.5,  0.5 );
		glVertex3f( -0.5,  0.5, -0.5 );
		glVertex3f( -0.5, -0.5, -0.5 );
		glEnd();

		// Blue side - TOP
		glBegin(GL_POLYGON);
		glColor3f(   0.0,  0.0,  1.0 );
		glVertex3f(  0.5,  0.5,  0.5 );
		glVertex3f(  0.5,  0.5, -0.5 );
		glVertex3f( -0.5,  0.5, -0.5 );
		glVertex3f( -0.5,  0.5,  0.5 );
		glEnd();

		// Red side - BOTTOM
		glBegin(GL_POLYGON);
		glColor3f(   1.0,  0.0,  0.0 );
		glVertex3f(  0.5, -0.5, -0.5 );
		glVertex3f(  0.5, -0.5,  0.5 );
		glVertex3f( -0.5, -0.5,  0.5 );
		glVertex3f( -0.5, -0.5, -0.5 );
		glEnd();

	}	
}
