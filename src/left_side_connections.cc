#include "left_side_connections.h"

namespace carcassonne
{

LeftSideConnections::LeftSideConnections()
{
}

LeftSideConnections::LeftSideConnections(bool clockwise,
											 									 bool across,
											 									 bool counterclockwise,
											 									 bool middle) :
  SideConnections(clockwise, across, counterclockwise, middle)
{
}

SideConnections* LeftSideConnections::Copy()
{
	return new LeftSideConnections(clockwise_, 
																 across_,
																 counterclockwise_,
																 middle_);
																 
}   

std::vector<std::string> LeftSideConnections::ToStringVector()
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
