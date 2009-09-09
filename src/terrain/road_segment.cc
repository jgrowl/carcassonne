#include "road_segment.h"

namespace carcassonne
{

RoadSegment::RoadSegment()
{
}

RoadSegment::RoadSegment(const RoadSegment& src)
{
	CopyFrom(src);
}

RoadSegment& RoadSegment::operator=(const RoadSegment& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}

void RoadSegment::CopyFrom(const RoadSegment& src)
{
}

TerrainSegment* RoadSegment::Clone()
{
	return new RoadSegment(*this);
}

RoadSegment::~RoadSegment()
{
}

}
