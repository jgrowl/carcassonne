#ifndef CARCASSONNE_TILE_SET_H_
#define CARCASSONNE_TILE_SET_H_

#include <vector>

#include <boost/scoped_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include "valid_tiles.h"

namespace carcassonne
{

class TileSet
{
 public:
	TileSet();
	
	virtual Tile* starting_tile_begin_copy();
	
	// Returns a array of Tiles that will eventually go into a bag to be drawn.
	virtual boost::ptr_vector<Tile> bagable_tiles_copy();
	
	// Depreciated
	virtual void CopyTiles(boost::ptr_vector<Tile>* tiles);
	
	virtual ~TileSet();
	
 private:
 	boost::scoped_ptr<ValidTiles> valid_tiles_;

 	// Initial tile that should be placed on a surface.
 	boost::scoped_ptr<Tile> starting_tile_begin_;
 
 	boost::ptr_vector<Tile> bagable_tiles_;
 
 
 
 	// FUTURE: DECORATION
 	//boost::scoped_ptr<Tile> starting_tiles_end_;
 	
 	// FUTURE: DECORATION
 	//boost::ptr_vector<Tile> starting_tiles_;
 	


 	
 	// Don't use while fixing design problem.
	boost::ptr_vector<Tile> starting_tile_;
 	
 	// Depreciated...
 	boost::ptr_vector<Tile> tiles_;
 	

 	
};

}

#endif /*CARCASSONNE_TILE_SET_H_*/
