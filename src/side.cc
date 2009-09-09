#include "side.h"

#include "side_connections.h"
#include <iostream>

namespace carcassonne
{

Side::Side()
{
	connections_.reset(new SideConnections);
}

Side::Side(const Side& src)
	: middle_(src.middle_->Clone()), 
		connections_(src.connections_->Clone()) 
{
	CopyFrom(src);
}

Side& Side::operator=(const Side& rhs)
{
	if(this == &rhs) {
		return (*this);	
	}
	
	CopyFrom(rhs);
	
	return (*this);
}

void Side::CopyFrom(const Side& rhs)
{
}

SideConnections* Side::connections()
{
	return connections_.get();
	
}

void Side::set_connections(SideConnections& connections)
{
	connections_.reset(&connections);
	
}

void Side::ConnectedToMiddle()
{
	connections_->set_middle(true);
	
}

bool Side::IsConnectedToMiddle()
{
	return connections_->middle();
	
}

std::string Side::ToString() const
{
	return "side with " + connections_->ToString();
	
}

Side::~Side()
{
	
}

}
