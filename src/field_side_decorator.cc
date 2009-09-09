#include "field_side_decorator.h"

#include <iostream>

#include "terrain/field_segment.h"

namespace carcassonne
{

FieldSideDecorator::FieldSideDecorator()
{
}

FieldSideDecorator::FieldSideDecorator(Side* side)
	:	TerrainSideDecorator(side)
{
	middle_.reset(new FieldSegment);
	
}

FieldSideDecorator::FieldSideDecorator(const FieldSideDecorator& src) 
	: TerrainSideDecorator(src)
{
	CopyFrom(src);	
}

FieldSideDecorator& FieldSideDecorator::
	operator=(const FieldSideDecorator& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}
 	
void FieldSideDecorator::
	CopyFrom(const FieldSideDecorator& src)
{
}
 
Side* FieldSideDecorator::
	Clone() const
{
	return new FieldSideDecorator(*this);
}

SideDecorator* FieldSideDecorator::Decorate(Side* side)
{
	return new FieldSideDecorator(side);
}

std::string FieldSideDecorator::ToString() const
{
	return "field " + TerrainSideDecorator::ToString();
	
}

FieldSideDecorator::~FieldSideDecorator()
{
}

}
