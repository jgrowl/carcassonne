#include "field_segment.h"

namespace carcassonne
{

FieldSegment::FieldSegment()
{
}

TerrainSegment* FieldSegment::Copy()
{
	return new FieldSegment;
	
}

FieldSegment::~FieldSegment()
{
}

}
