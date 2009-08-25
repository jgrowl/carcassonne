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

TerrainSideDecorator* CitySideDecorator::Decorate(Side* side)
{
	return new CitySideDecorator(side);
	
}

Side* CitySideDecorator::Copy()
{
	return new CitySideDecorator(side_->Copy());
	
}

std::string CitySideDecorator::ToString()
{
	return "city " + TerrainSideDecorator::ToString();
	
}

CitySideDecorator::~CitySideDecorator()
{
}

}
