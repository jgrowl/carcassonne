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

RightSideConnections::RightSideConnections(const RightSideConnections& src)
{
	clockwise_ = src.clockwise_;
	across_ = src.across_;
	counterclockwise_ = src.counterclockwise_;
	middle_ = src.middle_;
	
}

SideConnections* RightSideConnections::Copy() const
{
	return new RightSideConnections(clockwise_, 
															    across_, 
															    counterclockwise_, 
															    middle_);
	
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
