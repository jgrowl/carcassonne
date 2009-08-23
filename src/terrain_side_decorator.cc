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

TerrainSideDecorator::~TerrainSideDecorator()
{
}

}
