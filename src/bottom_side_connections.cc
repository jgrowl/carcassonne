#include "bottom_side_connections.h"

namespace carcassonne
{

BottomSideConnections::BottomSideConnections()
{
}

BottomSideConnections::BottomSideConnections(bool clockwise,
											 											 bool across,
											 											 bool counterclockwise,
											 											 bool middle) :
  SideConnections(clockwise, across, counterclockwise, middle)
{
}

SideConnections* BottomSideConnections::Copy()
{
	return new BottomSideConnections(clockwise_, 
																  across_, 
																  counterclockwise_, 
																  middle_);	
}

std::vector<std::string> BottomSideConnections::ToStringVector()
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
