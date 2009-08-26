#ifndef CARCASSONNE_BOTTOM_SIDE_CONNECTIONS_H_
#define CARCASSONNE_BOTTOM_SIDE_CONNECTIONS_H_

#include <string>
#include <vector>

#include "side_connections.h"

namespace carcassonne
{

class BottomSideConnections : public SideConnections
{
public:
	BottomSideConnections();
	BottomSideConnections(bool clockwise,
											  bool across,
											  bool counterclockwise,
											  bool middle);
	
	virtual SideConnections* Copy() const;
	
	virtual std::vector<std::string> ToStringVector() const;
	
	virtual ~BottomSideConnections();
};

}

#endif /*CARCASSONNE_BOTTOM_SIDE_CONNECTIONS_H_*/
