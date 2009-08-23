#include "string_utility.h"
#include "top_side_connections.h"

namespace carcassonne
{

TopSideConnections::TopSideConnections() : SideConnections()
{
}

TopSideConnections::TopSideConnections(bool clockwise,
                                       bool across,
                                       bool counterclockwise,
                                       bool middle) :
  SideConnections(clockwise, across, counterclockwise, middle)
{
}

SideConnections* TopSideConnections::Copy()
{
	return new TopSideConnections(clockwise_, 
															 across_, 
															 counterclockwise_, 
															 middle_);
}  

std::vector<std::string> TopSideConnections::ToStringVector()
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
