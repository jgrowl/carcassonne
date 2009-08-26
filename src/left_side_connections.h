#ifndef CARCASSONNE_LEFT_SIDE_CONNECTIONS_H_
#define CARCASSONNE_LEFT_SIDE_CONNECTIONS_H_

#include "side_connections.h"

namespace carcassonne
{

class LeftSideConnections : public SideConnections
{
 public:
	LeftSideConnections();
	LeftSideConnections(bool clockwise,
											bool across,
											bool counterclockwise,
											bool middle);
	
	
	virtual SideConnections* Copy() const;   
	
	std::vector<std::string> ToStringVector() const;
	
	virtual ~LeftSideConnections();
};

}

#endif /*CARCASSONNE_LEFT_SIDE_CONNECTIONS_H_*/
