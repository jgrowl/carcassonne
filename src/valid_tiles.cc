#include "valid_tiles.h"

namespace carcassonne
{

ValidTiles::ValidTiles()
{
	
	city_road_field_road_.reset(new Tile(city_, road_, field_, road_));
	city_road_field_road_->ConnectedRightToLeft();
	
	city_city_field_city_.reset(new Tile(city_, city_, field_, city_));
	city_city_field_city_->ConnectedTopToRight()
												.ConnectedTopToLeft()
												.ConnectedRightToLeft();
												
											
	// Add Pennant											
	city_city_field_city_p_.reset(city_city_field_city_->Copy());
												
	
	// Add Pennant
	city_city_city_city_p_.reset(new Tile(city_, city_, city_, city_));
	city_city_city_city_p_->ConnectedTopToRight()
												 .ConnectedTopToBottom()
												 .ConnectedTopToLeft()
												 .ConnectedRightToBottom()
												 .ConnectedRightToLeft()
												 .ConnectedBottomToLeft();
												 
}

Tile* ValidTiles::city_road_field_road()
{
	return city_road_field_road_->Copy();
	
}

Tile* ValidTiles::starting_tile()
{
	return city_road_field_road();
	
}

Tile* ValidTiles::city_city_field_city()
{
	return city_city_field_city_->Copy();
	
}

Tile* ValidTiles::city_city_field_city_p()
{
	return city_city_field_city_p_->Copy();
	
}

Tile* ValidTiles::city_city_city_city_p()
{
	return city_city_city_city_p_->Copy();
	
}

ValidTiles::~ValidTiles()
{
}

}
