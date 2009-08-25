#include "tile_set.h"

namespace carcassonne
{

TileSet::TileSet()
{
	valid_tiles_.reset(new ValidTiles);
	tiles_.push_back(valid_tiles_->city_city_field_city());
	tiles_.push_back(valid_tiles_->city_city_field_city());
	tiles_.push_back(valid_tiles_->city_city_field_city());
	
	tiles_.push_back(valid_tiles_->city_city_field_city_p());
	
	tiles_.push_back(valid_tiles_->city_city_city_city_p());
	

}

TileSet::~TileSet()
{

}

//Make a function that pushes a certain number of tiles into the tile set
//void push_back_n(Tile**, int);

}
