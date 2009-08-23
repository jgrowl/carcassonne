#ifndef CARCASSONNE_BAG_H_
#define CARCASSONNE_BAG_H_

#include <vector>

#include <boost/scoped_ptr.hpp>

#include "tile.h"
#include "valid_tiles.h"

namespace carcassonne
{

class Bag
{
 public:
  Bag();
  
  /*
   * Selects a single tile from the remaining tiles
   * 
   * @return a pointer to a tile that will be placed onto a surface.
   * The returned points to a heap allocated object that must be deleted.
   */
  Tile* Draw();
  
	virtual ~Bag();
 
 private:
//	std::vector<Tile*> tiles_;
	boost::scoped_ptr<ValidTiles> valid_tiles_;
	
};

}

#endif /*CARCASSONNE_BAG_H_*/
