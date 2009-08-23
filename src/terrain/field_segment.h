#ifndef CARCASSONNE_FIELD_SEGMENT_H_
#define CARCASSONNE_FIELD_SEGMENT_H_

#include "terrain_segment.h"

namespace carcassonne
{

class FieldSegment : public TerrainSegment
{
public:
	FieldSegment();
	virtual ~FieldSegment();
};

}

#endif /*CARCASSONNE_FIELD_SEGMENT_H_*/
