#ifndef ROAD_SEGMENT_H_
#define ROAD_SEGMENT_H_

#include "terrain_segment.h"

namespace carcassonne
{

class RoadSegment : public TerrainSegment
{
public:
	RoadSegment();
	virtual ~RoadSegment();
};

}

#endif /*ROAD_SEGMENT_H_*/
