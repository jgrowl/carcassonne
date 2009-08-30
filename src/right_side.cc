#include "right_side.h"

#include "right_side_connections.h"

namespace carcassonne
{

RightSide::RightSide() : Side()
{
	middle_.reset(new TerrainSegment);
	connections_.reset(new RightSideConnections);
	
}

RightSide::RightSide(TerrainSegment& middle, 
								 		 SideConnections& connections) : Side()
{
	middle_.reset(&middle);
	connections_.reset(&connections);
	
}

//RightSide::RightSide(Terrain& terrain) : Side(terrain)
//{
//
//}
//
//RightSide::RightSide(Terrain* terrain, SideConnections* connections) :
//   Side(terrain, connections)
//{
//}

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

Side* RightSide::Copy() const
{
	return new RightSide(*(middle_->Copy()), *(connections_->Copy()));
	
}

std::string RightSide::ToString() const
{
  return "right side with " + connections_->ToString();
  
}

RightSide::~RightSide()
{
}

}
