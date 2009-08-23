#ifndef CARCASSONNE_RIGHT_SIDE_CONNECTIONS_H_
#define CARCASSONNE_RIGHT_SIDE_CONNECTIONS_H_

#include <string>
#include <vector>

#include "side_connections.h"

namespace carcassonne
{

class RightSideConnections : public SideConnections
{
 public:
	RightSideConnections();
	RightSideConnections(bool clockwise,
											 bool across,
											 bool counterclockwise,
											 bool middle);
	
	virtual SideConnections* Copy();   
	
	virtual std::vector<std::string> ToStringVector();
	
	virtual ~RightSideConnections();
};

}

#endif /*CARCASSONNE_RIGHT_SIDE_CONNECTIONS_H_*/
