#include "city_side_decorator.h"

#include "terrain/city_segment.h"

namespace carcassonne
{

CitySideDecorator::CitySideDecorator()
{
}

CitySideDecorator::CitySideDecorator(Side* side) : TerrainSideDecorator(side)
{
	middle_.reset(new CitySegment);
}

SideDecorator* CitySideDecorator::Decorate(Side* side)
{
	return new CitySideDecorator(side);
}

CitySideDecorator::CitySideDecorator(const CitySideDecorator& src)
	: TerrainSideDecorator(src)
{
	CopyFrom(src);	
}

CitySideDecorator& CitySideDecorator::
	operator=(const CitySideDecorator& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}
 	
void CitySideDecorator::
	CopyFrom(const CitySideDecorator& src)
{
}
 
Side* CitySideDecorator::
	Clone() const
{
	return new CitySideDecorator(*this);
}

std::string CitySideDecorator::ToString() const
{
	return "city " + TerrainSideDecorator::ToString();
	
}

bool CitySideDecorator::
	IsPotentialTerrainMatch(const TerrainSideDecorator& 
														inTerrainSideDecorator) const
{
	return inTerrainSideDecorator.IsExistingTerrainMatch(*this);
}
 	
bool CitySideDecorator:: 
	IsExistingTerrainMatch(const FieldSideDecorator& inFieldSideDecorator) const
{
	return false;
}

bool CitySideDecorator:: 
	IsExistingTerrainMatch(const RoadSideDecorator& inRoadSideDecorator) const
{
	return false;
}

bool CitySideDecorator::
	IsExistingTerrainMatch(const CitySideDecorator& inCitySideDecorator) const
{
	return true;
}

CitySideDecorator::~CitySideDecorator()
{
}

}
