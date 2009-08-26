#ifndef CARCASSONNE_FIELD_SIDE_DECORATOR_H_
#define CARCASSONNE_FIELD_SIDE_DECORATOR_H_

#include "terrain_side_decorator.h"

namespace carcassonne
{

class FieldSideDecorator : public TerrainSideDecorator
{
public:
	FieldSideDecorator();
	FieldSideDecorator(Side*);

	virtual TerrainSideDecorator* Decorate(Side*);

	virtual Side* Copy() const;

	virtual std::string ToString() const;

	virtual ~FieldSideDecorator();
};

}

#endif /*CARCASSONNE_FIELD_SIDE_DECORATOR_H_*/
