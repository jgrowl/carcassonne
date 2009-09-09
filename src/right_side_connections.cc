#include "right_side_connections.h"

namespace carcassonne
{

RightSideConnections::RightSideConnections()
{
}

RightSideConnections::RightSideConnections(const RightSideConnections& src)
	: SideConnections(src)
{
	CopyFrom(src);
}

RightSideConnections& RightSideConnections::
	operator=(const RightSideConnections& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}

void RightSideConnections::
	CopyFrom(const RightSideConnections& src)
{										  
}

SideConnections* RightSideConnections::
	Clone() const
{
	return new RightSideConnections(*this);
}

std::vector<std::string> RightSideConnections::ToStringVector() const
{
  std::vector<std::string> connections;

  connections.push_back("Right(itself)");

  if(clockwise_) {
    connections.push_back("Bottom");
  }

  if(across_) {
    connections.push_back("Left");
  }

  if(counterclockwise_) {
    connections.push_back("Top");
  }

  return connections;
  
}

RightSideConnections::~RightSideConnections()
{
}

}
