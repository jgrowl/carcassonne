#ifndef CARCASSONNE_ROAD_H_
#define CARCASSONNE_ROAD_H_

#include "terrain.h"

namespace carcassonne
{

class Road : public Terrain
{
public:
	Road();
	
	virtual Terrain* GetNewTerrain();
	
	virtual ~Road();
};

}

#endif /*CARCASSONNE_ROAD_H_*/
