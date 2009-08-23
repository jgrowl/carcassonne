#include "road.h"

namespace carcassonne
{

Road::Road()
{
}

Terrain* Road::GetNewTerrain()
{
	return new Road();
	
}

Road::~Road()
{
}

}
