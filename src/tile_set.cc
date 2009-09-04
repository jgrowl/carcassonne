#include "tile_set.h"

namespace carcassonne
{

TileSet::TileSet()
{
	valid_tiles_.reset(new ValidTiles);

	starting_tile_begin_.reset(valid_tiles_->starting_tile());
	
// TODO:Make a function that pushes a certain number of tiles into the tile 
//	 set void push_back_n(Tile**, int);
	bagable_tiles_.push_back(valid_tiles_->city_city_field_city());
	bagable_tiles_.push_back(valid_tiles_->city_city_field_city());
	bagable_tiles_.push_back(valid_tiles_->city_city_field_city());
	
	bagable_tiles_.push_back(valid_tiles_->city_city_field_city_p());
	
	bagable_tiles_.push_back(valid_tiles_->city_city_city_city_p());
	
}

Tile* TileSet::starting_tile_begin_copy()
{
	return starting_tile_begin_->Copy();
	
}

boost::ptr_vector<Tile> TileSet::bagable_tiles_copy()
{
	boost::ptr_vector<Tile> bagable_tiles;
	
	for(boost::ptr_vector<Tile>::const_iterator i = bagable_tiles_.begin(), 
																							e = bagable_tiles_.end(); 
				i != e; ++i) {
		bagable_tiles.push_back(i->Copy());
	}
	
	return bagable_tiles;
	
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
