#include "field.h"

namespace carcassonne
{

Field::Field()
{
}

Terrain* Field::GetNewTerrain()
{
	return new Field();
	
}


Field::~Field()
{
}

}
