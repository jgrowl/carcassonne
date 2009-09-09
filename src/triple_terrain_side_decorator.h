#ifndef CARCASSONNE_TRIPLE_TERRAIN_SIDE_DECORATOR_H_
#define CARCASSONNE_TRIPLE_TERRAIN_SIDE_DECORATOR_H_

#include <boost/scoped_ptr.hpp>

#include "terrain_side_decorator.h"

namespace carcassonne
{

class TripleTerrainSideDecorator : public TerrainSideDecorator
{
 public:
 	TripleTerrainSideDecorator();
	TripleTerrainSideDecorator(Side*);
 	TripleTerrainSideDecorator(const TripleTerrainSideDecorator&);
 	TripleTerrainSideDecorator& operator=(const TripleTerrainSideDecorator&);
 	
 	virtual void CopyFrom(const TripleTerrainSideDecorator&);
 	virtual Side* Clone() const = 0;
 	
 	virtual SideDecorator* Decorate(Side*) = 0;
	
	virtual ~TripleTerrainSideDecorator();
	
 protected:
	boost::scoped_ptr<TerrainSegment> segment1_;
	boost::scoped_ptr<TerrainSegment> segment2_;
	
};

}

#endif /*CARCASSONNE_TRIPLE_TERRAIN_SIDE_DECORATOR_H_*/
