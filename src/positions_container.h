#ifndef CARCASSONNE_OPEN_POSITIONS_H_
#define CARCASSONNE_OPEN_POSITIONS_H_

#include <string>
#include <vector>

#include <boost/ptr_container/ptr_vector.hpp>

#include "position.h"

namespace carcassonne
{

class PositionsContainer : public boost::ptr_vector<Position>
{
 public:
	PositionsContainer();
	
	virtual std::vector<std::string> ToStringVector();
	virtual std::string ToString();
	
	virtual ~PositionsContainer();
	
};

}

#endif /*CARCASSONNE_OPEN_POSITIONS_H_*/
