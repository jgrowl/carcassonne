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
 	TerrainSideDecorator(const TerrainSideDecorator&);
 	TerrainSideDecorator& operator=(const TerrainSideDecorator&);
 	
 	virtual void CopyFrom(const TerrainSideDecorator&);
 	virtual Side* Clone() const = 0;
	
	virtual SideDecorator* Decorate(Side*) = 0;
	
	virtual ~TerrainSideDecorator();
	
};

}

#endif /*CARCASSONNE_TERRAIN_SIDE_DECORATOR_H_*/
