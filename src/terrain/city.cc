#include "city.h"

namespace carcassonne
{

City::City()
{
}

Terrain* City::GetNewTerrain()
{
	return new City();
	
}

City::~City()
{
}

}
