#include "bag.h"

#include <iostream>
#include <algorithm>

#include "vector_utility.h"	// For utility::shuffle()

namespace carcassonne
{

Bag::Bag()
{
}


void Bag::Fill(std::vector<Tile>& tiles)
{
	for(std::vector<Tile>::iterator i = tiles.begin(), e = tiles.end();
			i != e; ++i) {
		tiles_.push_back(&(*i));	
	}
}

void Bag::Shuffle()
{
	utility::shuffle(tiles_);
}


Tile* Bag::Draw()
{
	// Get a tile.
	Tile* tile = tiles_.back();
	
	// Remove that tile from the rest of the tiles.
	tiles_.pop_back();
	
	// Return the tile
	return tile;
		
}

int Bag::TilesLeft()
{
	return tiles_.size();
	
}

bool Bag::IsEmpty()
{
	return !TilesLeft();
	
}

Bag::~Bag()
{
}

}
