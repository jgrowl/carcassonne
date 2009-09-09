#ifndef CARCASSONNE_TILE_SET_H_
#define CARCASSONNE_TILE_SET_H_

#include <vector>

#include "valid_tiles.h"

namespace carcassonne
{

class TileSet
{
 public:
	TileSet();
	
	virtual Tile& starting_tile_begin();
	
	// Returns a array of Tiles that will eventually go into a bag to be drawn.
	virtual std::vector<Tile>& bagable_tiles();
		
	virtual ~TileSet();
	
 private:
 	// Initial tile that should be placed on a surface.
 	Tile starting_tile_begin_;
 
 	std::vector<Tile> bagable_tiles_;
 
 	// FUTURE: DECORATION
 	//Tile starting_tiles_end_;
 	
 	// FUTURE: DECORATION
 	//std::vector<Tile> starting_tiles_;
 	
};

}

#endif /*CARCASSONNE_TILE_SET_H_*/
