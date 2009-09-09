#ifndef CARCASSONNE_ROAD_SIDE_DECORATOR_H_
#define CARCASSONNE_ROAD_SIDE_DECORATOR_H_

#include "triple_terrain_side_decorator.h"

namespace carcassonne
{

class RoadSideDecorator : public TripleTerrainSideDecorator
{
public:
	RoadSideDecorator();
	RoadSideDecorator(Side*);
 	RoadSideDecorator(const RoadSideDecorator&);
 	RoadSideDecorator& operator=(const RoadSideDecorator&);
 	
 	virtual void CopyFrom(const RoadSideDecorator&);
 	virtual Side* Clone() const;
	
	virtual SideDecorator* Decorate(Side*);
	
	
	virtual std::string ToString() const;
	
	virtual ~RoadSideDecorator();
};

}

#endif /*CARCASSONNE_ROAD_SIDE_DECORATOR_H_*/
