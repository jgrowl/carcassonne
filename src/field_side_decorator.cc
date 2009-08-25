#include "field_side_decorator.h"
#include "terrain/field_segment.h"

namespace carcassonne
{

FieldSideDecorator::FieldSideDecorator()
{
}

FieldSideDecorator::FieldSideDecorator(Side* side) : 
	TerrainSideDecorator(side)
{
	middle_.reset(new FieldSegment);
}

TerrainSideDecorator* FieldSideDecorator::Decorate(Side* side)
{
	return new FieldSideDecorator(side);
}

Side* FieldSideDecorator::Copy()
{
	return new FieldSideDecorator(side_->Copy());
	
}

std::string FieldSideDecorator::ToString()
{
	return "field " + TerrainSideDecorator::ToString();
	
}

FieldSideDecorator::~FieldSideDecorator()
{
}

}
