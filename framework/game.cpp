#include <vector>
#include <queue>
#include <cstdlib>
#include <stdio.h>

#include "foundation/foundation.h" 
#include "game.h"

//update: &vector<Life> -> NULL
//Takes in a vector containing all the life forms on the screen and updates them.
void Framework::update(std::vector<Cell> &world) {
	std::queue<Cell> to_add = std::queue<Cell>();

	for(unsigned int i = 0; i < world.size(); i++) {

		std::vector<Cell> neighbours = Framework::pos_neighbours(world[i], world);
		int count_alive = Framework::neighbour_scan(world[i], world);	

		//printf("Neighbour Scan: %i\n", count_alive);

		switch(count_alive) {
			case 4:
			case 5:
				//This cell lives to the next generation.	
				break;
				//This cell dies:
			default:
				world[i].alive = false;
		}

		for(std::vector<Cell>::iterator q = neighbours.begin(); q != neighbours.end(); ++q) {
			//This cell should be alive:
			if(Framework::neighbour_scan(*q, world) == 5) {
				q->alive = true;
				q->color = blend_color(q->color, world[i].color); 
				to_add.push(*q);
			}
		}
	}

	//Add all the new elements to the world:
	while(!to_add.empty()) {
		world.push_back(to_add.front());
		to_add.pop();
	}

	purge_dead(world);
}

//pos_neighbours: Cell vector<Cell> -> vector<Cell>
//Returns the location of all cells around a pivot, whether alive or dead.
std::vector<Cell> Framework::pos_neighbours(Cell pivot, std::vector<Cell> &world) {
	std::vector<Cell> neighbours;

	for(int x_ = -1; x_ < 2; x_++) {
		for(int y_ = -1; y_ < 2; y_++) {
			for(int z_ = -1; z_ < 2; z_++) {

				if(x_ != 0 || y_ != 0 || z_ != 0) {
					Pos dummy = pivot.position;
					dummy.X += x_;
					dummy.Y += y_;	
					dummy.Z += z_;

					Cell temp;
					temp.alive = false;
					temp.position = dummy;
					neighbours.push_back(temp);
				}
			}
		}
	}
	return neighbours;
}

//neighbour_scan: Cell vector<Cell> -> int
//Finds the count of neighbours currently in a position in 3D space.
int Framework::neighbour_scan(Cell pivot, std::vector<Cell> &world) {
	int count = 0;

	//A neighbour constitutes as something parallel to a cell.	
	for(int x_ = -1; x_ < 2; x_++) {
		for(int y_ = -1; y_ < 2; y_++) {
			for(int z_ = -1; z_ < 2; z_++) {

				if(x_ != 0 || y_ != 0 || z_ != 0) {
					Pos dummy = pivot.position;
					dummy.X += x_;
					dummy.Y += y_;	
					dummy.Z += z_;
					if(Framework::exists(dummy, world)) {
						count++;
					}
				}
			}
		}
	}
	return count;
}

//exists?: Cell vector<Cell> -> bool
//Checks if a cell exists in the world.
bool Framework::exists(Cell pivot, std::vector<Cell> &world) {
	for(std::vector<Cell>::iterator it = world.begin(); it != world.end(); ++it) {
		if(*it == pivot) {
			return true;
		}
	}
	return false;
}
//exists?: Position vector<Cell> -> bool
//Checks if a cell exists in the world.
bool Framework::exists(Pos position, std::vector<Cell> &world) {
	for(std::vector<Cell>::iterator it = world.begin(); it != world.end(); ++it) {
		if(it->position == position) {
			return true;
		}
	}
	return false;
}
//exists?: Position vector<Cell> vector<Cell>::iterator -> bool
//Checks if a cell exists in the world.
bool Framework::exists(Pos position, std::vector<Cell> &world, std::vector<Cell>::iterator it) {
	for(; it != world.end(); ++it) {
		if(it->position == position) {
			return true;
		}
	}
	return false;
}
//get_cell: Pos vector<Cell> -> Cell
//Returns a cell from a position that exists in the vector.
Cell Framework::get_cell(Pos position, std::vector<Cell> &world) {
	Cell to_return;
	for(std::vector<Cell>::iterator it = world.begin(); it != world.end(); ++it) {
		if(it->position == position) {
			to_return = *it;
		}
	}

	return to_return;
}

//blend: Color Color -> Color
//Blends two colors together.
Color Framework::blend_color(Color a, Color b) {
	Color new_color;
	new_color.R = (a.R + b.R) / 2;
	new_color.B = (a.B + b.B) / 2;
	new_color.G = (a.G + b.G) / 2;
	return new_color;
}

//purge_dead: vector<Cell> -> NULL
//Removes any dead cells found in the vector of cells.
void Framework::purge_dead(std::vector<Cell> &world) {
	for(std::vector<Cell>::iterator it = world.begin(); it != world.end(); ++it) {
		if(!it->alive || exists(it->position, world, it + 1)) {
			//Erase, continue.
			it = world.erase(it);
			--it;
		}
	}
}

//initial_startup: Int -> vector<Cell>
//Generates cells in a starting area of a radius of 250 cells.
std::vector<Cell> Framework::initial_startup(int count, int radius) {
	std::vector<Cell> to_return;
	for(int i = 0; i < count; i++) {

		Cell generated;
		generated.alive = true;

		//Generate a color:
		Color color;
		color.R = rand() % 255;
		color.G = rand() % 255;
		color.B = rand() % 255;

		generated.color = color;

		//Generate a position:
		Pos pos;
		pos.X = Framework::maybe_negative() * (rand() % radius);
		pos.Y = Framework::maybe_negative() * (rand() % radius);
		pos.Z = Framework::maybe_negative() * (rand() % radius);

		generated.position = pos;

		to_return.push_back(generated);
	}

	return to_return;
}


//maybe_negative: NULL -> Int
//Returns a scalar that might be negative, based on chance.
int Framework::maybe_negative() {
	int gen = rand() % 2;
	if(gen == 1) {
		return 1;
	}
	return -1;
}
