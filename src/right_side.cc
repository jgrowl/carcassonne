#include "right_side.h"

#include "right_side_connections.h"

namespace carcassonne
{

RightSide::RightSide() : Side()
{
	connections_.reset(new RightSideConnections);
	
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

std::string RightSide::ToString()
{
  return "right side with " + connections_->ToString();
  
}

RightSide::~RightSide()
{
}

}
