#include "road_segment.h"

namespace carcassonne
{

RoadSegment::RoadSegment()
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
