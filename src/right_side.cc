#include "right_side.h"

#include "right_side_connections.h"

namespace carcassonne
{

RightSide::RightSide() : Side()
{
	middle_.reset(new TerrainSegment);
	connections_.reset(new RightSideConnections);
}

RightSide::RightSide(const RightSide& src) : Side(src)
{
	CopyFrom(src);	
}

RightSide& RightSide::
	operator=(const RightSide& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}
 	
void RightSide::
	CopyFrom(const RightSide& src)
{
}
 
Side* RightSide::
	Clone() const
{
	return new RightSide(*this);
}

void RightSide::ConnectedToTop()
{
	connections_->set_counterclockwise(true);
	
}

void RightSide::ConnectedToRight()
{}

void RightSide::ConnectedToBottom()
{
	connections_->set_clockwise(true);
	
}

void RightSide::ConnectedToLeft()
{
	connections_->set_across(true);
	
}

bool RightSide::IsConnectedToTop()
{
  return connections_->counterclockwise();
}

bool RightSide::IsConnectedToRight()
{
  return true;
}

bool RightSide::IsConnectedToBottom()
{
  return connections_->clockwise();
}

bool RightSide::IsConnectedToLeft()
{
  return connections_->across();
}

std::string RightSide::ToString() const
{
  return "right side with " + connections_->ToString();
  
}

RightSide::~RightSide()
{
}

}
