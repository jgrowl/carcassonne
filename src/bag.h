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
  
  virtual void Draw(boost::scoped_ptr<Tile>* tile);
  
  virtual int TilesLeft();
  virtual bool IsEmpty();
  
	virtual ~Bag();
 
 private:
	boost::scoped_ptr<TileSet> tile_set_;
	boost::ptr_vector<Tile> tiles_;
	

	
};

}

#endif /*CARCASSONNE_BAG_H_*/
