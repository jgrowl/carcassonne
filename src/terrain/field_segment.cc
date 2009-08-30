#include "field_segment.h"

namespace carcassonne
{

FieldSegment::FieldSegment()
{
}

FieldSegment::FieldSegment(const FieldSegment& src) : TerrainSegment()
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
