#include "tile_set.h"

namespace carcassonne
{

TileSet::TileSet()
{
	ValidTiles valid_tiles_;

	starting_tile_begin_ = valid_tiles_.city_road_field_road_copy();
	
// TODO:Make a function that pushes a certain number of tiles into the tile 
//	 set void push_back_n(Tile**, int);
	bagable_tiles_.push_back(valid_tiles_.city_city_field_city_copy());
	bagable_tiles_.push_back(valid_tiles_.city_city_field_city_copy());
	bagable_tiles_.push_back(valid_tiles_.city_city_field_city_copy());
	
	bagable_tiles_.push_back(valid_tiles_.city_city_field_city_p_copy());
	
	bagable_tiles_.push_back(valid_tiles_.city_city_city_city_p_copy());
	
}

Tile& TileSet::starting_tile_begin()
{
	return starting_tile_begin_;
}

std::vector<Tile>& TileSet::bagable_tiles()
{
	return bagable_tiles_;
}

TileSet::~TileSet()
{

}



}
