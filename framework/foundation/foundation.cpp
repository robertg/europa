#include <vector>
#include "foundation.h"

//Function Definitions for Pos:
bool Pos::operator==(Pos other) {
	if(other.X != X || other.Y != Y || other.Z != Z) {
		return false;
	}
	return true;
}

//Function Definitions for Color:
bool Color::operator==(Color other) {
	if(other.R != R || other.B != B || other.G != G) {
		return false;
	}
	return true;
}

//Function Definitions for Cell:
bool Cell::operator==(Cell other) {
	if(!(other.position == position) || !(other.alive == alive) || !(other.color == color)) {
		return false;
	}
	return false;
}

