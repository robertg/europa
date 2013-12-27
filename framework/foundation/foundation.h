#ifndef FOUNDATION_H
#define FOUNDATION_H

//Represents a position in 3D space:
structure Pos {
	float X;
	float Y;
	float Z;
}

//Represents a Color:
structure Color {
	int R;
	int G;
	int B;
}

//Represents a Cell on the screen:
structure Cell {
	Pos position;
	Color color;
}
#endif
