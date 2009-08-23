#include "left_side.h"

#include "left_side_connections.h"

namespace carcassonne
{

LeftSide::LeftSide() : Side()
{
	connections_.reset(new LeftSideConnections);
	
}

//LeftSide::LeftSide(Terrain& terrain) : Side(terrain)
//{
//}
//
//LeftSide::LeftSide(Terrain* terrain, SideConnections* connections) :
//   Side(terrain, connections) 
//{
//}

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

std::string LeftSide::ToString()
{
  return "left side with " + connections_->ToString();
  
}

LeftSide::~LeftSide()
{
}

}
