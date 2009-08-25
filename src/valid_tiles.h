#ifndef CARCASSONNE_VALID_TILES_H_
#define CARCASSONNE_VALID_TILES_H_

#include <boost/scoped_ptr.hpp>

#include "tile.h"
#include "field_side_decorator.h"
#include "road_side_decorator.h"
#include "city_side_decorator.h"

namespace carcassonne
{

class ValidTiles
{
 public:
	ValidTiles();
	
	Tile* city_city_field_city();
	Tile* city_city_field_city_p();
	Tile* city_city_city_city_p();
	
	virtual ~ValidTiles();
 
 private:
 	FieldSideDecorator field_;
 	RoadSideDecorator road_;
 	CitySideDecorator city_;
 	
 	boost::scoped_ptr<Tile> city_city_field_city_;
	boost::scoped_ptr<Tile> city_city_field_city_p_;
 	boost::scoped_ptr<Tile> city_city_city_city_p_;
};

}

#endif /*CARCASSONNE_VALID_TILES_H_*/
