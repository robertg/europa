#ifndef GAME_H
#define GAME_H

#include <vector>
#include "foundation/foundation.h"

namespace Framework {
	void update(std::vector<Cell> &world);
	std::vector<Cell> pos_neighbours(Cell pivot, std::vector<Cell> &world);
	int neighbour_scan(Cell pivot, std::vector<Cell> &world);
	bool exists(Cell pivot, std::vector<Cell> &world);
	bool exists(Pos position, std::vector<Cell> &world);
	bool exists(Pos position, std::vector<Cell> &world, std::vector<Cell>::iterator it);
	Cell get_cell(Pos position, std::vector<Cell> &world);
	Color blend_color(Color a, Color b);
	void purge_dead(std::vector<Cell> &world);
	std::vector<Cell> initial_startup(int count);
	int maybe_negative();
}

#endif
