#include "bottom_side.h"

#include "bottom_side_connections.h"

namespace carcassonne
{

BottomSide::BottomSide() : Side()
{
	middle_.reset(new TerrainSegment);
	connections_.reset(new BottomSideConnections);	
}

BottomSide::BottomSide(const BottomSide& src) : Side(src)
{
	CopyFrom(src);
}

BottomSide& BottomSide::
	operator=(const BottomSide& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}
 	
void BottomSide::
	CopyFrom(const BottomSide& src)
{
}

Side* BottomSide::
	Clone() const
{
	return new BottomSide(*this);
}

BottomSide::BottomSide(TerrainSegment& middle, 
								 		   SideConnections& connections) : Side()
{
	middle_.reset(&middle);
	connections_.reset(&connections);
	
}

void BottomSide::ConnectedToTop()
{
	connections_->set_across(true);
	
}

void BottomSide::ConnectedToRight()
{
	connections_->set_counterclockwise(true);
	
}

void BottomSide::ConnectedToBottom()
{}

void BottomSide::ConnectedToLeft()
{
	connections_->set_clockwise(true);
}

bool BottomSide::IsConnectedToTop()
{
  return connections_->across();
}

bool BottomSide::IsConnectedToRight()
{
  return connections_->counterclockwise();
}

bool BottomSide::IsConnectedToBottom()
{
  return true;
}

bool BottomSide::IsConnectedToLeft()
{
  return connections_->clockwise();
}

std::string BottomSide::ToString() const
{
  return "bottom side with " + connections_->ToString();
}

BottomSide::~BottomSide()
{
}

}
