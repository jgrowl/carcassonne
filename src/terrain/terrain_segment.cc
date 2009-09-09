#include "terrain_segment.h"

namespace carcassonne
{

TerrainSegment::TerrainSegment()
{
}

TerrainSegment& TerrainSegment::operator=(const TerrainSegment& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);	
}

void TerrainSegment::CopyFrom(const TerrainSegment& src)
{
}

TerrainSegment* TerrainSegment::Clone()
{
	return new TerrainSegment(*this);
}

TerrainSegment::TerrainSegment(const TerrainSegment& src)
{
	CopyFrom(src);
}

TerrainSegment::~TerrainSegment()
{
}

}
