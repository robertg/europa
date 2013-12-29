#ifndef FOUNDATION_H
#define FOUNDATION_H

//Represents a position in 3D space:
struct Pos {
	int X;
	int Y;
	int Z;
	bool operator==(const Pos other);
};

//Represents a Color:
struct Color {
	int R;
	int G;
	int B;
	bool operator==(const Color other);
};

//Represents a Cell on the screen:
struct Cell {
	Pos position;
	Color color;
	bool alive;
	bool operator==(const Cell other);
};
#endif
