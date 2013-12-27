#include <vector>
#include "foundation/foundation.h"
#include "game.h"

//update: &vector<Life> -> NULL
//Takes in a vector containing all the life forms on the screen and updates them.
void Framework::update(std::vector<Cell> &world) {
	for(std::vector<Cell>::iterator i = world.begin(); i != world.end(); ++i) {

		std::vector<Cell> neighbours = pos_neighbours(*i);
		int count_alive = neighbour_scan(*i, world);	

		switch(count_alive) {
			case 2:
			case 3:
				//This cell lives to the next generation.	
				break;
				//This cell dies:
			default:
				(*i).alive = false;
		}

		for(std::vector<Cell>::iterator q = neighbours.begin(); q != neighbours.end(); ++q) {
			if(!exists(*q, world)) {
				//This cell should be alive:
				if(neighbour_scan(*q, world) == 3) {
					(*q).alive = true;
					(*q).color = blend_color((*q).color, (*i).color);
					world.push_back(*q);
				}
			}
		}
	}

	purge_dead(world);
}

//pos_neighbours: Cell -> vector<Cell>
//Returns the location of all cells around a pivot, whether alive or dead.
std::vector<Cell> Framework::pos_neighbours(Cell pivot) {
	//This should return 6 neighbours.	
	return std::vector<Cell>();
}

//neighbour_scan: Cell vector<Cell> -> int
//Finds the count of neighbours currently in a position in 3D space.
int Framework::neighbour_scan(Cell pivot, std::vector<Cell> &world) {
	//A neighbour constitutes as something parallel to a cell.	
	return 0;
}

//exists?: Cell vector<Cell> -> bool
//Checks if a cell exists in the world.
bool Framework::exists(Cell pivot, std::vector<Cell> &world) {
	return true;
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
		if(!(*it).alive) {
			world.erase(it);
		}
	}
}
