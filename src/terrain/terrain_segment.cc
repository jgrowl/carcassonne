#include "terrain_segment.h"

namespace carcassonne
{

TerrainSegment::TerrainSegment()
{
}

TerrainSegment* TerrainSegment::Copy()
{
	return new TerrainSegment;
}

TerrainSegment::TerrainSegment(const TerrainSegment& src)
{
}

TerrainSegment::~TerrainSegment()
{
}

}
