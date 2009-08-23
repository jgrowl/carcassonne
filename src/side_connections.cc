#include "string_utility.h"
#include "side_connections.h"

namespace carcassonne
{

SideConnections::SideConnections()
{
  clockwise_ = false;
  across_ = false;
  counterclockwise_ = false;
  middle_ = false;	
  
}

SideConnections::SideConnections(bool clockwise, 
																 bool across,
                                 bool counterclockwise, 
                                 bool middle)
{
  clockwise_ = clockwise;
  across_ = across;
  counterclockwise_ = counterclockwise;
  middle_ = middle;
  
}

bool SideConnections::clockwise() { return clockwise_; }
bool SideConnections::across() { return across_; }
bool SideConnections::counterclockwise() { return counterclockwise_; }
bool SideConnections::middle() { return middle_; }

void SideConnections::set_clockwise(bool clockwise)
{ 
	clockwise_ = clockwise; 

}

void SideConnections::set_across(bool across)
{
	across_ = across;
	
}

void SideConnections::set_counterclockwise(bool counterclockwise)
{
	counterclockwise_ = counterclockwise;
		
}

void SideConnections::set_middle(bool middle)
{
	middle_ = middle;
	
}

std::vector<std::string> SideConnections::ToStringVector()
{
  std::vector<std::string> tmp;

  if(clockwise_) {
    tmp.push_back("clockwise");
  }

  if(across_) {
    tmp.push_back("across");
  }

  if(counterclockwise_) {
    tmp.push_back("counterclockwise");
  }

  return tmp;
}

std::string SideConnections::ToString()
{
  return "connection(s) to " + commaize(ToStringVector());
}

SideConnections::~SideConnections()
{
}

}
