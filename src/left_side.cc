#include "left_side.h"

#include "left_side_connections.h"

namespace carcassonne
{

LeftSide::LeftSide() : Side()
{
	middle_.reset(new TerrainSegment);
	connections_.reset(new LeftSideConnections);
	
}

LeftSide::LeftSide(TerrainSegment& middle, 
								 	 SideConnections& connections) : Side()
{
	middle_.reset(&middle);
	connections_.reset(&connections);
	
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

Side* LeftSide::Copy() const
{
	return new LeftSide(*(middle_->Copy()), *(connections_->Copy()));
	
}

std::string LeftSide::ToString() const
{
  return "left side with " + connections_->ToString();
  
}

LeftSide::~LeftSide()
{
}

}
