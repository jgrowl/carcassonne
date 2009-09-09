#ifndef CARCASSONNE_VALID_TILES_H_
#define CARCASSONNE_VALID_TILES_H_

#include <boost/scoped_ptr.hpp>

#include "tile.h"

namespace carcassonne
{

class ValidTiles
{
 public:
	ValidTiles();
	
	Tile city_road_field_road_copy();
	Tile city_city_field_city_copy();
	Tile city_city_field_city_p_copy();
	Tile city_city_city_city_p_copy();
	
	virtual ~ValidTiles();
 
 private:
 	Tile city_road_field_road_;
 	Tile city_city_field_city_;
	Tile city_city_field_city_p_;
 	Tile city_city_city_city_p_;
 	
};

}

#endif /*CARCASSONNE_VALID_TILES_H_*/
