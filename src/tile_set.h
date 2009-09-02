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
	
	virtual void CopyTiles(boost::ptr_vector<Tile>* tiles);
	
	virtual ~TileSet();
	
 private:
	boost::ptr_vector<Tile> starting_tile_;
 	boost::scoped_ptr<ValidTiles> valid_tiles_;
 	boost::ptr_vector<Tile> tiles_;
};

}

#endif /*CARCASSONNE_TILE_SET_H_*/
