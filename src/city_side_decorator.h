#ifndef CARCASSONNE_CITY_SIDE_DECORATOR_H_
#define CARCASSONNE_CITY_SIDE_DECORATOR_H_

#include "terrain_side_decorator.h"

namespace carcassonne
{

class CitySideDecorator : public TerrainSideDecorator
{
public:
	CitySideDecorator();
	CitySideDecorator(Side*);
	
	virtual TerrainSideDecorator* Decorate(Side*);
	
	virtual Side* Copy();
	
	virtual std::string ToString();
	
	virtual ~CitySideDecorator();
};

}

#endif /*CARCASSONNE_CITY_SIDE_DECORATOR_H_*/