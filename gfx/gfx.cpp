//Glew:
#define GLEW_STATIC
#include <GL/glew.h> 

//SDL:
#include <SDL.h>
#include <SDL_opengl.h>

#include <vector>

#include "gfx.h"

void Gfx::draw(std::vector<Cell> &world, float rotate_x, float rotate_y) {
	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


	for(std::vector<Cell>::iterator it = world.begin(); it != world.end(); ++it) {

		//Reset transformations
		glLoadIdentity();

		//Rotate with rotate_x and rotate_y
		glRotatef( rotate_x, 1.0, 0.0, 0.0 );
		glRotatef( rotate_y, 0.0, 1.0, 0.0 );
		glScalef( 0.05f, 0.05f, 0.05f );

		//FRONT
		glBegin(GL_POLYGON);
		glColor3f( 0.0, 1.0, 0.0 );
		glVertex3f(  0.5 + it->position.X, -0.5 + it->position.Y, -0.5 + it->position.Z );      
		glVertex3f(  0.5 + it->position.X,  0.5 + it->position.Y, -0.5 + it->position.Z );     
		glVertex3f( -0.5 + it->position.X,  0.5 + it->position.Y, -0.5 + it->position.Z );    
		glVertex3f( -0.5 + it->position.X, -0.5 + it->position.Y, -0.5 + it->position.Z);    

		glEnd();

		//BACK
		glBegin(GL_POLYGON);
		glColor3f( 0.0, 1.0, 0.0 );
		glVertex3f(  0.5 + it->position.X, -0.5 + it->position.Y, 0.5 + it->position.Z );
		glVertex3f(  0.5 + it->position.X,  0.5 + it->position.Y, 0.5 + it->position.Z );
		glVertex3f( -0.5 + it->position.X,  0.5 + it->position.Y, 0.5 + it->position.Z );
		glVertex3f( -0.5 + it->position.X, -0.5 + it->position.Y, 0.5 + it->position.Z );
		glEnd();

		//RIGHT
		glBegin(GL_POLYGON);
		glColor3f( 0.0, 1.0, 0.0 );
		glVertex3f( 0.5 + it->position.X, -0.5 + it->position.Y, -0.5 + it->position.Z );
		glVertex3f( 0.5 + it->position.X,  0.5 + it->position.Y, -0.5 + it->position.Z );
		glVertex3f( 0.5 + it->position.X,  0.5 + it->position.Y,  0.5 + it->position.Z );
		glVertex3f( 0.5 + it->position.X, -0.5 + it->position.Y,  0.5 + it->position.Z );
		glEnd();

		// LEFT
		glBegin(GL_POLYGON);
		glColor3f( 0.0, 1.0, 0.0 );
		glVertex3f( -0.5  + it->position.X, -0.5 + it->position.Y,  0.5 + it->position.Z );
		glVertex3f( -0.5  + it->position.X,  0.5 + it->position.Y,  0.5 + it->position.Z );
		glVertex3f( -0.5  + it->position.X,  0.5 + it->position.Y, -0.5 + it->position.Z );
		glVertex3f( -0.5  + it->position.X, -0.5 + it->position.Y, -0.5 + it->position.Z );
		glEnd();

		//TOP
		glBegin(GL_POLYGON);
		glColor3f( 0.0, 1.0, 0.0 );
		glVertex3f(  0.5  + it->position.X,  0.5 + it->position.Y,  0.5 + it->position.Z );
		glVertex3f(  0.5  + it->position.X,  0.5 + it->position.Y, -0.5 + it->position.Z );
		glVertex3f( -0.5  + it->position.X,  0.5 + it->position.Y, -0.5 + it->position.Z );
		glVertex3f( -0.5  + it->position.X,  0.5 + it->position.Y,  0.5 + it->position.Z );
		glEnd();

		//BOTTOM
		glBegin(GL_POLYGON);
		glColor3f( 0.0, 1.0, 0.0 );  
		glVertex3f(  0.5  + it->position.X, -0.5 + it->position.Y, -0.5 + it->position.Z );
		glVertex3f(  0.5  + it->position.X, -0.5 + it->position.Y,  0.5 + it->position.Z );
		glVertex3f( -0.5  + it->position.X, -0.5 + it->position.Y,  0.5 + it->position.Z );
		glVertex3f( -0.5  + it->position.X, -0.5 + it->position.Y, -0.5 + it->position.Z );
		glEnd();

	}	
}
