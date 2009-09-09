#include "city_segment.h"

namespace carcassonne
{

CitySegment::CitySegment() : TerrainSegment()
{
}

CitySegment::CitySegment(const CitySegment& src)
{
	CopyFrom(src);
}

CitySegment& CitySegment::operator=(const CitySegment& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}

void CitySegment::CopyFrom(const CitySegment& src)
{
}

TerrainSegment* CitySegment::Clone()
{
	return new CitySegment(*this);
}

CitySegment::~CitySegment()
{
}

}
