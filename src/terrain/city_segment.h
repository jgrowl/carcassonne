#ifndef CARCASSONNE_CITY_SEGMENT_H_
#define CARCASSONNE_CITY_SEGMENT_H_

#include "terrain_segment.h"

namespace carcassonne
{

class CitySegment : public TerrainSegment
{
public:
	CitySegment();
	
	virtual TerrainSegment* Copy();
	
	virtual ~CitySegment();
};

}

#endif /*CARCASSONNE_CITY_SEGMENT_H_*/
