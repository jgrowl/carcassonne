#include "city_segment.h"

namespace carcassonne
{

CitySegment::CitySegment()
{
}

TerrainSegment* CitySegment::Copy()
{
	return new CitySegment();
	
}

CitySegment::~CitySegment()
{
}

}
