#include "bag.h"

#include <algorithm>

#include "ptr_container_utility.h"	// For random_shuffle()

namespace carcassonne
{

Bag::Bag()
{
	tile_set_.reset(new TileSet);
	Fill();

}


void Bag::Fill()
{
	tile_set_->CopyTiles(&tiles_);
	
}

void Bag::Shuffle()
{
	random_shuffle(&tiles_);
	
}

Tile* Bag::Draw()
{
	return tiles_.pop_back().release();
	
}

Bag::~Bag()
{
}

}
