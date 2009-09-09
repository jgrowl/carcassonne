#include "field_segment.h"

namespace carcassonne
{

FieldSegment::FieldSegment()
{
}

FieldSegment::FieldSegment(const FieldSegment& src)
{
	CopyFrom(src);
}

FieldSegment& FieldSegment::operator=(const FieldSegment& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}

void FieldSegment::CopyFrom(const FieldSegment& src)
{
}


TerrainSegment* FieldSegment::Clone()
{
	return new FieldSegment(*this);
}

FieldSegment::~FieldSegment()
{
}

}
