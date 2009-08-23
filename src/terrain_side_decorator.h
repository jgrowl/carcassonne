#ifndef CARCASSONNE_TERRAIN_SIDE_DECORATOR_H_
#define CARCASSONNE_TERRAIN_SIDE_DECORATOR_H_

#include "side_decorator.h"

namespace carcassonne
{

class TerrainSideDecorator : public SideDecorator
{
 public:
 	TerrainSideDecorator();
	TerrainSideDecorator(Side*);
	
	virtual TerrainSideDecorator* Decorate(Side*) = 0;
	
	virtual ~TerrainSideDecorator();
	
};

}

#endif /*CARCASSONNE_TERRAIN_SIDE_DECORATOR_H_*/
