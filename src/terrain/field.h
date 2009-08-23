#ifndef CARCASSONNE_FIELD_H_
#define CARCASSONNE_FIELD_H_

#include "terrain.h"

namespace carcassonne
{

class Field : public Terrain
{
public:
	Field();
	
	virtual Terrain* GetNewTerrain();
	
	virtual ~Field();
};

}

#endif /*CARCASSONNE_FIELD_H_*/
