#include "tile_connections.h"

namespace carcassonne
{

TileConnections::TileConnections()
{
 	top_to_right_ = false; 
	top_to_bottom_ = false;
	top_to_left_ = false;
	top_to_middle_ = false;
	right_to_top_ = false;
	right_to_bottom_ = false; 
	right_to_left_ = false;
	right_to_middle_ = false;
	bottom_to_top_ = false;
	bottom_to_right_ = false;
	bottom_to_left_ = false;
	bottom_to_middle_ = false; 
	left_to_top_ = false;
	left_to_right_ = false; 
	left_to_bottom_ = false; 
	left_to_middle_ = false;
}

TileConnections::TileConnections(bool top_to_right, bool top_to_bottom,
                                bool top_to_left, bool top_to_middle,
                                bool right_to_bottom, bool right_to_left,
                                bool right_to_middle, bool bottom_to_left,
                                bool bottom_to_middle, bool left_to_middle)
{
  top_to_right_ = top_to_right;
  top_to_bottom_ = top_to_bottom;
  top_to_left_ = top_to_left;
  top_to_middle_ = top_to_middle;

  right_to_top_ = top_to_right;
  right_to_bottom_ = right_to_bottom;
  right_to_left_ = right_to_left;
  right_to_middle_ = right_to_middle;

	bottom_to_top_ = top_to_bottom;
  bottom_to_right_ = right_to_bottom;
  bottom_to_left_ = bottom_to_left;
  bottom_to_middle_ = bottom_to_middle;

	left_to_top_ = top_to_left;
  left_to_right_ = right_to_left;
  left_to_bottom_ = bottom_to_left;
  left_to_middle_ = left_to_middle;
   
}

TileConnections::~TileConnections()
{
}

}
