#include "left_side.h"

#include "left_side_connections.h"

namespace carcassonne
{

LeftSide::LeftSide() : Side()
{
	middle_.reset(new TerrainSegment);
	connections_.reset(new LeftSideConnections);
	
}

LeftSide::LeftSide(const LeftSide& src) : Side(src)
{
	CopyFrom(src);	
}

LeftSide& LeftSide::
	operator=(const LeftSide& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}
 	
void LeftSide::
	CopyFrom(const LeftSide& src)
{
}
 
Side* LeftSide::
	Clone() const
{
	return new LeftSide(*this);
}

void LeftSide::ConnectedToTop()
{
	connections_->set_clockwise(true);
	
}

void LeftSide::ConnectedToRight()
{
	connections_->set_across(true);
	
}

void LeftSide::ConnectedToBottom()
{
	connections_->set_counterclockwise(true);
	
}

void LeftSide::ConnectedToLeft()
{
}

bool LeftSide::IsConnectedToTop()
{
  return connections_->clockwise();
  
}

bool LeftSide::IsConnectedToRight()
{
  return connections_->across();
  
}

bool LeftSide::IsConnectedToBottom()
{
  return connections_->counterclockwise();
  
}

bool LeftSide::IsConnectedToLeft()
{
  return true;
  
}

std::string LeftSide::ToString() const
{
  return "left side with " + connections_->ToString();
  
}

LeftSide::~LeftSide()
{
}

}
