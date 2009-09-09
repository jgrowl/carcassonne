#include "top_side.h"
#include "top_side_connections.h"

namespace carcassonne
{

TopSide::TopSide() : Side()
{
	middle_.reset(new TerrainSegment);
	connections_.reset(new TopSideConnections);
	
}

TopSide::TopSide(const TopSide& src) : Side(src)
{
	CopyFrom(src);	
}

TopSide& TopSide::
	operator=(const TopSide& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}
 	
void TopSide::
	CopyFrom(const TopSide& src)
{
}
 
Side* TopSide::
	Clone() const
{
	return new TopSide(*this);
}

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

std::string TopSide::ToString() const
{
  return "top side with " + connections_->ToString();
  
}

TopSide::~TopSide()
{
}

}
