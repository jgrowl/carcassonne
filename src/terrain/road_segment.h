#ifndef ROAD_SEGMENT_H_
#define ROAD_SEGMENT_H_

#include "terrain_segment.h"

namespace carcassonne
{

class RoadSegment : public TerrainSegment
{
public:
	RoadSegment();
	RoadSegment(const RoadSegment&);
	RoadSegment& operator=(const RoadSegment&);
	
	void CopyFrom(const RoadSegment&);
	virtual TerrainSegment* Clone();
	
	virtual ~RoadSegment();
};

}

#endif /*ROAD_SEGMENT_H_*/
