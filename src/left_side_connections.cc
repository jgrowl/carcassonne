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

LeftSideConnections::LeftSideConnections(const LeftSideConnections& src)
{
	clockwise_ = src.clockwise_;
	across_ = src.across_;
	counterclockwise_ = src.counterclockwise_;
	middle_ = src.middle_;
	
}

SideConnections* LeftSideConnections::Copy() const
{
	return new LeftSideConnections(clockwise_, 
																 across_,
																 counterclockwise_,
																 middle_);
																 
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
