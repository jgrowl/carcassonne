#ifndef CARCASSONNE_TERRAIN_SIDE_DECORATOR_H_
#define CARCASSONNE_TERRAIN_SIDE_DECORATOR_H_

#include "side_decorator.h"

namespace carcassonne
{

class FieldSideDecorator; // Forward declarations
class RoadSideDecorator;
class CitySideDecorator;

class TerrainSideDecorator : public SideDecorator
{
 public:
 	TerrainSideDecorator();
	TerrainSideDecorator(Side*);
 	TerrainSideDecorator(const TerrainSideDecorator&);
 	TerrainSideDecorator& operator=(const TerrainSideDecorator&);
 	
 	virtual void CopyFrom(const TerrainSideDecorator&);
 	virtual Side* Clone() const = 0;
 	
 	/**
 	 * IsPotentialTerrainMatch and IsExistingTerrainMatch methods implement
 	 * the Double Dispatch Technique in order to ascertain whether or not
 	 * two terrains match
 	 */
 	virtual bool IsPotentialTerrainMatch(const TerrainSideDecorator&) const = 0;
 	
 	virtual bool IsExistingTerrainMatch(const FieldSideDecorator&) const = 0;
 	virtual bool IsExistingTerrainMatch(const RoadSideDecorator&) const = 0;
 	virtual bool IsExistingTerrainMatch(const CitySideDecorator&) const = 0;
	
	virtual SideDecorator* Decorate(Side*) = 0;
	
	virtual ~TerrainSideDecorator();
	
};

}

#endif /*CARCASSONNE_TERRAIN_SIDE_DECORATOR_H_*/
