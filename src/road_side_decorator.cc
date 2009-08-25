#include "road_side_decorator.h"
#include "terrain/road_segment.h"
#include "terrain/field_segment.h"

namespace carcassonne
{

RoadSideDecorator::RoadSideDecorator()
{
}

RoadSideDecorator::RoadSideDecorator(Side* side) : 
	TripleTerrainSideDecorator(side)
{
	segment1_.reset(new FieldSegment);
	middle_.reset(new RoadSegment);
	segment2_.reset(new FieldSegment);
	
}

TerrainSideDecorator* RoadSideDecorator::Decorate(Side* side)
{
	return new RoadSideDecorator(side);
	
}

Side* RoadSideDecorator::Copy()
{
	return new RoadSideDecorator(side_->Copy());
	
}

std::string RoadSideDecorator::ToString()
{
	return "road " + TerrainSideDecorator::ToString();
	
}

RoadSideDecorator::~RoadSideDecorator()
{
}

}
