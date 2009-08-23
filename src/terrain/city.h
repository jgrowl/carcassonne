#ifndef CARCASSONNE_CITY_H_
#define CARCASSONNE_CITY_H_

#include "terrain.h"

namespace carcassonne
{

class City : public Terrain
{
public:
	City();
	
	virtual Terrain* GetNewTerrain();
	
	virtual ~City();
};

}

#endif /*CARCASSONNE_CITY_H_*/
