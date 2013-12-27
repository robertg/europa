#ifndef FOUNDATION_H
#define FOUNDATION_H

//Represents a position in 3D space:
struct Pos {
	float X;
	float Y;
	float Z;
};

//Represents a Color:
struct Color {
	int R;
	int G;
	int B;
};

//Represents a Cell on the screen:
struct Cell {
	Pos position;
	Color color;
};
#endif
