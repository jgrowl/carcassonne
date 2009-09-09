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

CitySideDecorator::~CitySideDecorator()
{
}

}
