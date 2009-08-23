#include "side_decorator.h"

namespace carcassonne
{

SideDecorator::SideDecorator()
{
}

SideDecorator::SideDecorator(Side* side)
{
	side_ = side;
}

/**
 * Sets the connection to true
 */
void SideDecorator::ConnectedToTop()
{
	side_->ConnectedToTop();
		
}
	
void SideDecorator::ConnectedToRight()
{
	side_->ConnectedToRight();
	
}
	
void SideDecorator::ConnectedToBottom()
{
	side_->ConnectedToBottom();
	
}
	
void SideDecorator::ConnectedToLeft()
{
	side_->ConnectedToLeft();
	
}

/**
 * returns true if the side is connected
 */
bool SideDecorator::IsConnectedToTop()
{
	return side_->IsConnectedToTop();
	
}
  
bool SideDecorator::IsConnectedToRight()
{
	return side_->IsConnectedToRight();
	
}
  
bool SideDecorator::IsConnectedToBottom()
{
	return side_->IsConnectedToBottom();
	
}
  
bool SideDecorator::IsConnectedToLeft()
{
	return side_->IsConnectedToLeft();
	
}

std::string SideDecorator::ToString()
{
	return side_->ToString();
	
}


SideDecorator::~SideDecorator()
{
}

}
