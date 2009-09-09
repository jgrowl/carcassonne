#include "left_side_connections.h"

namespace carcassonne
{

LeftSideConnections::LeftSideConnections()
{
}

LeftSideConnections::LeftSideConnections(const LeftSideConnections& src)
	: SideConnections(src)
{
	CopyFrom(src);
}

LeftSideConnections& LeftSideConnections::
	operator=(const LeftSideConnections& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}

void LeftSideConnections::
	CopyFrom(const LeftSideConnections& src)
{										  
}

SideConnections* LeftSideConnections::
	Clone() const
{
	return new LeftSideConnections(*this);
}

std::vector<std::string> LeftSideConnections::ToStringVector() const
{
  std::vector<std::string> connections;

  connections.push_back("Left(itself)");

  if(clockwise_) {
    connections.push_back("Top");
  }

  if(across_) {
    connections.push_back("Right");
  }

  if(counterclockwise_) {
    connections.push_back("Bottom");
  }

  return connections;
  
}

LeftSideConnections::~LeftSideConnections()
{
}

}
