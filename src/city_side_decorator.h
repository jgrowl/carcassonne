#ifndef CARCASSONNE_CITY_SIDE_DECORATOR_H_
#define CARCASSONNE_CITY_SIDE_DECORATOR_H_

#include "terrain_side_decorator.h"

namespace carcassonne
{

class CitySideDecorator : public TerrainSideDecorator
{
public:
	CitySideDecorator();
	CitySideDecorator(Side*);
 	CitySideDecorator(const CitySideDecorator&);
 	CitySideDecorator& operator=(const CitySideDecorator&);
 	
 	virtual void CopyFrom(const CitySideDecorator&);
 	virtual Side* Clone() const;
	
	virtual SideDecorator* Decorate(Side*);
	
	virtual std::string ToString() const;
	
	virtual bool IsPotentialTerrainMatch(const TerrainSideDecorator&) const;
 	
 	virtual bool IsExistingTerrainMatch(const FieldSideDecorator&) const;
 	virtual bool IsExistingTerrainMatch(const RoadSideDecorator&) const;
 	virtual bool IsExistingTerrainMatch(const CitySideDecorator&) const;
	
	virtual ~CitySideDecorator();
};

}

#endif /*CARCASSONNE_CITY_SIDE_DECORATOR_H_*/
