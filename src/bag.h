#ifndef CARCASSONNE_BAG_H_
#define CARCASSONNE_BAG_H_

#include <boost/scoped_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include "tile.h"
#include "tile_set.h"

namespace carcassonne
{

class Bag
{
 public:
  Bag();
  
  void Fill();
  
  void Shuffle();
  
  /*
   * Selects a single tile from the remaining tiles
   * 
   * @return a pointer to a tile that will be placed onto a surface.
   * The returned points to a heap allocated object that must be deleted.
   */
  virtual Tile* Draw();
  
	virtual ~Bag();
 
 private:
	boost::scoped_ptr<TileSet> tile_set_;
	boost::ptr_vector<Tile> tiles_;
	

	
};

}

#endif /*CARCASSONNE_BAG_H_*/
