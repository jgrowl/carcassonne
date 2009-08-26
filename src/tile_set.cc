#include "tile_set.h"

namespace carcassonne
{

TileSet::TileSet()
{
	valid_tiles_.reset(new ValidTiles);
	
// TODO:Make a function that pushes a certain number of tiles into the tile 
//	 set void push_back_n(Tile**, int);
	tiles_.push_back(valid_tiles_->city_city_field_city());
	tiles_.push_back(valid_tiles_->city_city_field_city());
	tiles_.push_back(valid_tiles_->city_city_field_city());
	
	tiles_.push_back(valid_tiles_->city_city_field_city_p());
	
	tiles_.push_back(valid_tiles_->city_city_city_city_p());
	

}

void TileSet::CopyTiles(boost::ptr_vector<Tile>* tiles)
{
	for(boost::ptr_vector<Tile>::const_iterator i = tiles_.begin(), 
																							e = tiles_.end(); 
				i != e; ++i) {
		tiles->push_back(i->Copy());
	}
	
}


TileSet::~TileSet()
{

}



}
