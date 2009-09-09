#include "terrain_side_decorator.h"

namespace carcassonne
{

TerrainSideDecorator::TerrainSideDecorator()
{
}

TerrainSideDecorator::TerrainSideDecorator(Side* side) : 
	SideDecorator(side)
{
}

TerrainSideDecorator::TerrainSideDecorator(const TerrainSideDecorator& src)
	: SideDecorator(src)
{
	CopyFrom(src);
}

TerrainSideDecorator& TerrainSideDecorator::
	operator=(const TerrainSideDecorator& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}
 	
void TerrainSideDecorator::
	CopyFrom(const TerrainSideDecorator& src)
{
}

TerrainSideDecorator::~TerrainSideDecorator()
{
}

}
