#include "side_decorator.h"
#include <iostream>

namespace carcassonne
{

SideDecorator::SideDecorator() : Side()
{
}

SideDecorator::SideDecorator(Side* side) : Side()
{
	side_ = side;
}

SideDecorator::SideDecorator(const SideDecorator& src)
	: Side(src)
{
	CopyFrom(src);
}

SideDecorator& SideDecorator::
	operator=(const SideDecorator& rhs)
{
	if(this == &rhs) {
		return (*this);
	}
	
	CopyFrom(rhs);
	
	return (*this);
}

void SideDecorator::
	CopyFrom(const SideDecorator& src)
{
	// FIX: Clone returns a specific side but a generic connection?
	side_ = src.side_->Clone();  
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

std::string SideDecorator::ToString() const
{
	return side_->ToString();
	
}


SideDecorator::~SideDecorator()
{
}

}
