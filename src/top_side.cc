#include "top_side.h"

#include "top_side_connections.h"

namespace carcassonne
{

TopSide::TopSide() : Side()
{
	connections_.reset(new TopSideConnections);
	
}

TopSide::TopSide(TerrainSegment& middle, 
								 SideConnections& connections) : Side()
{
	middle_.reset(&middle);
	connections_.reset(&connections);
	
}

//TopSide::TopSide(Terrain& terrain): Side(terrain)
//{
//
//}
//
//TopSide::TopSide(Terrain* terrain, SideConnections* connections) :
//   Side(terrain, connections)
//{
//}

/**
 * Sets the connection to true
 */
void TopSide::ConnectedToTop()
{
}

/**
 * Sets the connection to true
 */
void TopSide::ConnectedToRight()
{
	connections_->set_counterclockwise(true);
	
}

/**
 * Sets the connection to true
 */
void TopSide::ConnectedToBottom()
{
	connections_->set_clockwise(true);
	
}

/**
 * Sets the connection to true
 */
void TopSide::ConnectedToLeft()
{
	connections_->set_across(true);
	
}


/**
 * returns true if the side is connected
 */
bool TopSide::IsConnectedToTop()
{
  return true;
  
}

/**
 * returns true if the side is connected
 */
bool TopSide::IsConnectedToRight()
{
  return connections_->clockwise();
  
}

/**
 * returns true if the side is connected
 */
bool TopSide::IsConnectedToBottom()
{
  return connections_->across();
  
}

/**
 * returns true if the side is connected
 */
bool TopSide::IsConnectedToLeft()
{
  return connections_->counterclockwise();
  
}

Side* TopSide::Copy()
{
	return new TopSide(*(middle_->Copy()), *(connections_->Copy()));
	
}

std::string TopSide::ToString()
{
  return "top side with " + connections_->ToString();
  
}

TopSide::~TopSide()
{
}

}
