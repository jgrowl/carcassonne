#include "bag.h"

#include <iostream>
#include <algorithm>

#include "ptr_container_utility.h"	// For random_shuffle()

namespace carcassonne
{

Bag::Bag()
{
	tile_set_.reset(new TileSet);
	Fill();
	Shuffle();

}


void Bag::Fill()
{
	tile_set_->CopyTiles(&tiles_);
	
}

void Bag::Shuffle()
{
	random_shuffle(&tiles_);
	
}

void Bag::Draw(boost::ptr_vector<Tile>* tile)
{
	tile->push_back(tiles_.pop_back().release());
		
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
