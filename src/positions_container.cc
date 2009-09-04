#include "positions_container.h"

#include "string_utility.h"
#include "convert.h"

namespace carcassonne
{

PositionsContainer::PositionsContainer()
{
}

std::vector<std::string> PositionsContainer::ToStringVector()
{
	std::vector<std::string> tmp_vector;
	int index = 0;
	for(boost::ptr_vector<Position>::iterator i = begin(), 
																						e = end(); i != e; ++i) {
		tmp_vector.push_back(std::string("[") + stringify(index++)
			+ std::string("] ") + i->ToString());																		
	}
	
	return tmp_vector;
	
}

std::string PositionsContainer::ToString()
{
	return lineize(ToStringVector());
	
}

PositionsContainer::~PositionsContainer()
{
}

}
