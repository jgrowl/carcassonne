#include "right_side_connections.h"

namespace carcassonne
{

RightSideConnections::RightSideConnections()
{
}

RightSideConnections::RightSideConnections(bool clockwise,
										 											 bool across,
										 											 bool counterclockwise,
										 											 bool middle) :
  SideConnections(clockwise, across, counterclockwise, middle)
{
}

SideConnections* RightSideConnections::Copy()
{
	return new RightSideConnections(clockwise_, 
															    across_, 
															    counterclockwise_, 
															    middle_);
	
}

std::vector<std::string> RightSideConnections::ToStringVector()
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
