#include "valid_tiles.h"

#include <iostream>

#include "field_side_decorator.h"
#include "road_side_decorator.h"
#include "city_side_decorator.h"

namespace carcassonne
{

ValidTiles::ValidTiles()
{
	// Create SideDecorators for use in initialization.
	FieldSideDecorator field_;
 	RoadSideDecorator road_;
 	CitySideDecorator city_;
 	
	city_road_field_road_ = Tile(city_, road_, field_, road_);
	city_road_field_road_.ConnectedRightToLeft();

 	city_city_field_city_ = Tile(city_, city_, field_, city_);
 	city_city_field_city_.ConnectedTopToRight()
											 .ConnectedTopToLeft()
											 .ConnectedRightToLeft();

	// Add Pennant											
	city_city_field_city_p_ = Tile(city_city_field_city_);
												
	
	// Add Pennant
 	city_city_city_city_p_ = Tile(city_, city_, city_, city_);
 	city_city_city_city_p_.ConnectedTopToRight()
												.ConnectedTopToBottom()
												.ConnectedTopToLeft()
												.ConnectedRightToBottom()
												.ConnectedRightToLeft()
												.ConnectedBottomToLeft();
												 
}

Tile ValidTiles::city_road_field_road_copy()
{
	return Tile(city_road_field_road_);
}

Tile ValidTiles::city_city_field_city_copy()
{
	return Tile(city_city_field_city_);
	
}

Tile ValidTiles::city_city_field_city_p_copy()
{
	return Tile(city_city_field_city_p_);
	
}

Tile ValidTiles::city_city_city_city_p_copy()
{
	return Tile(city_city_city_city_p_);
	
}

ValidTiles::~ValidTiles()
{
}

}
