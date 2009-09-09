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

RoadSideDecorator::RoadSideDecorator(const RoadSideDecorator& src) 
	: TripleTerrainSideDecorator(src)
{
	CopyFrom(src);	
}

RoadSideDecorator& RoadSideDecorator::
	operator=(const RoadSideDecorator& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}
 	
void RoadSideDecorator::
	CopyFrom(const RoadSideDecorator& src)
{
}
 
Side* RoadSideDecorator::
	Clone() const
{
	return new RoadSideDecorator(*this);
}

SideDecorator* RoadSideDecorator::Decorate(Side* side)
{
	return new RoadSideDecorator(side);
	
}

std::string RoadSideDecorator::ToString() const
{
	return "road " + TerrainSideDecorator::ToString();
	
}

RoadSideDecorator::~RoadSideDecorator()
{
}

}
