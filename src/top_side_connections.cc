#include <iostream>

#include "string_utility.h"
#include "top_side_connections.h"

namespace carcassonne
{

TopSideConnections::TopSideConnections() : SideConnections()
{
}

TopSideConnections::TopSideConnections(const TopSideConnections& src)
	: SideConnections(src)
{
	CopyFrom(src);
}

TopSideConnections& TopSideConnections::
	operator=(const TopSideConnections& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}

void TopSideConnections::
	CopyFrom(const TopSideConnections& src)
{										  
}

SideConnections* TopSideConnections::
	Clone() const
{
	return new TopSideConnections(*this);
}

std::vector<std::string> TopSideConnections::ToStringVector() const
{
  std::vector<std::string> connections;

  connections.push_back("Top(itself)");

  if(clockwise_) {
    connections.push_back("Right");
  }

  if(across_) {
    connections.push_back("Bottom");
  }

  if(counterclockwise_) {
    connections.push_back("Left");
  }

  return connections;
  
}

TopSideConnections::~TopSideConnections()
{
}

}
