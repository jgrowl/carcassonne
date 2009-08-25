#include "bottom_side.h"

#include "bottom_side_connections.h"

namespace carcassonne
{

BottomSide::BottomSide() : Side()
{
	connections_.reset(new BottomSideConnections);
	
}

BottomSide::BottomSide(TerrainSegment& middle, 
								 		   SideConnections& connections) : Side()
{
	middle_.reset(&middle);
	connections_.reset(&connections);
	
}

//BottomSide::BottomSide(Terrain& terrain) : Side(terrain)
//{
//	
//}
//
//BottomSide::BottomSide(Terrain* terrain, SideConnections* connections) :
//		Side(terrain, connections)
//{
//}

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

Side* BottomSide::Copy()
{
	return new BottomSide(*(middle_->Copy()), *(connections_->Copy()));
	
}

std::string BottomSide::ToString()
{
  return "bottom side with " + connections_->ToString();
}

BottomSide::~BottomSide()
{
}

}
