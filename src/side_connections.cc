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

SideConnections::SideConnections(const SideConnections& src)
{
	CopyFrom(src);
}

SideConnections& SideConnections::
	operator=(const SideConnections& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}

void SideConnections::
	CopyFrom(const SideConnections& src)
{
  clockwise_ = src.clockwise_;
  across_ = src.across_;
  counterclockwise_ = src.counterclockwise_;
  middle_ = src.middle_;
}

SideConnections* SideConnections::
	Clone() const
{
	return new SideConnections(*this);
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

std::vector<std::string> SideConnections::ToStringVector() const
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

std::string SideConnections::ToString() const
{
  return "connection(s) to " + commaize(ToStringVector());
}

SideConnections::~SideConnections()
{
}

}
