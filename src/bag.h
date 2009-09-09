#ifndef CARCASSONNE_BAG_H_
#define CARCASSONNE_BAG_H_

#include <vector>

#include "tile.h"
#include "tile_set.h"

namespace carcassonne
{

class Bag
{
 public:
  Bag();
  
  virtual void Fill(std::vector<Tile>& tiles);
  
//  void Fill();
//  
  virtual void Shuffle();
  
  virtual Tile* Draw();
  
  virtual int TilesLeft();
  virtual bool IsEmpty();
  
	virtual ~Bag();
 
 private:
	std::vector<Tile*> tiles_;
	

	
};

}

#endif /*CARCASSONNE_BAG_H_*/
