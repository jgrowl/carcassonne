#ifndef CARCASSONNE_TILE_CONNECTIONS_H_
#define CARCASSONNE_TILE_CONNECTIONS_H_

#include "tile.h"

namespace carcassonne
{

class Tile; // Forward declaration for friend

class TileConnections
{
 public:
 	TileConnections();
  TileConnections(bool top_to_right, bool top_to_bottom,
                  bool top_to_left, bool top_to_middle,
                  bool right_to_bottom, bool right_to_left,
                  bool right_to_middle, bool bottom_to_left,
                  bool bottom_to_middle, bool left_to_middle);
                  
	virtual ~TileConnections();

 private:
 	// A tile needs complete control over it's connections
 	friend class Tile;
 	
  // The following booleans are the minimum connection values to fully 
  // describe the tile's connections.
  bool top_to_right_;
  bool top_to_bottom_;
  bool top_to_left_;
  bool top_to_middle_;

  bool right_to_bottom_;
  bool right_to_left_;
  bool right_to_middle_;

  bool bottom_to_left_;
  bool bottom_to_middle_;

  bool left_to_middle_;
  
  // The following booleans are not needed to describe the tile since
  // they will be determined by the booleans above.  They are only for
  // ease of use.
  bool right_to_top_;
  
  bool bottom_to_top_;
  bool bottom_to_right_;
  
  bool left_to_top_;
  bool left_to_right_;
  bool left_to_bottom_;
  
};

}

#endif /*CARCASSONNE_TILE_CONNECTIONS_H_*/
