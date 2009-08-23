#include "valid_tiles.h"

namespace carcassonne
{

ValidTiles::ValidTiles()
{
	city_city_city_city_p_.reset(new Tile(city_, city_, city_, city_));
	city_city_city_city_p_->ConnectedTopToRight()
												 .ConnectedTopToBottom()
												 .ConnectedTopToLeft()
												 .ConnectedRightToBottom()
												 .ConnectedRightToLeft()
												 .ConnectedBottomToLeft();
												 
}

ValidTiles::~ValidTiles()
{
}

}
