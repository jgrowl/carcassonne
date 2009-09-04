#include "bag.h"

#include <iostream>
#include <algorithm>

#include "vector_utility.h"	// For utility::shuffle()

namespace carcassonne
{

Bag::Bag()
{
//	Fill();
//	Shuffle();

}


void Bag::Fill(std::vector<Tile*> tiles)
{
	tiles_ = tiles;
	
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
	std::cout << "Destructing bag...\n";
}

}
