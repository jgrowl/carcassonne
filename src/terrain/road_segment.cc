#include "road_segment.h"

namespace carcassonne
{

RoadSegment::RoadSegment()
{
}

RoadSegment::RoadSegment(const RoadSegment& src) : TerrainSegment()
{
}

TerrainSegment* RoadSegment::Copy()
{
	return new RoadSegment;
	
}

RoadSegment::~RoadSegment()
{
}

}
