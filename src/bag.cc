#include "bag.h"

namespace carcassonne
{

Bag::Bag()
{
	TileSet tile_set;
	Fill(tile_set);
	
}

Bag::Bag(TileSet& tile_set)
{
	Fill(tile_set);
	
}

void Bag::Fill(TileSet& tile_set)
{
	
}

Bag::~Bag()
{
}

}
