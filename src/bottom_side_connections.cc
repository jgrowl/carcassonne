#include "bottom_side_connections.h"

namespace carcassonne
{

BottomSideConnections::BottomSideConnections() : SideConnections()
{
}

BottomSideConnections::BottomSideConnections(const BottomSideConnections& src)
	: SideConnections(src)
{
	CopyFrom(src);
}

BottomSideConnections& BottomSideConnections::
	operator=(const BottomSideConnections& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}

void BottomSideConnections::
	CopyFrom(const BottomSideConnections& src)
{										  
}

SideConnections* BottomSideConnections::
	Clone() const
{
	return new BottomSideConnections(*this);
}

std::vector<std::string> BottomSideConnections::ToStringVector() const
{
  std::vector<std::string> connections;

  connections.push_back("Bottom(itself)");

  if(clockwise_) {
    connections.push_back("Left");
  }

  if(across_) {
    connections.push_back("Top");
  }

  if(counterclockwise_) {
    connections.push_back("Right");
  }

  return connections;
  
}

BottomSideConnections::~BottomSideConnections()
{
}

}
