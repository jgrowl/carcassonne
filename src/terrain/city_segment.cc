#include "city_segment.h"

namespace carcassonne
{

CitySegment::CitySegment() : TerrainSegment()
{
}

CitySegment::CitySegment(const CitySegment& src) : TerrainSegment()
{
}

TerrainSegment* CitySegment::Copy()
{
	return new CitySegment;
	
}

CitySegment::~CitySegment()
{
}

}
