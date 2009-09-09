#include "triple_terrain_side_decorator.h"

namespace carcassonne
{

TripleTerrainSideDecorator::TripleTerrainSideDecorator()
{
}

TripleTerrainSideDecorator::TripleTerrainSideDecorator(Side* side) : 
	TerrainSideDecorator(side)
{
}

TripleTerrainSideDecorator::
							TripleTerrainSideDecorator(const TripleTerrainSideDecorator& src)
	: TerrainSideDecorator(src),
		segment1_(src.segment1_->Clone()),
	  segment2_(src.segment2_->Clone())
{
}

TripleTerrainSideDecorator& TripleTerrainSideDecorator::
	operator=(const TripleTerrainSideDecorator& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}
 	
void TripleTerrainSideDecorator::
	CopyFrom(const TripleTerrainSideDecorator& src)
{
}

TripleTerrainSideDecorator::~TripleTerrainSideDecorator()
{
}

}
