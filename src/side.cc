#include "side.h"

namespace carcassonne
{

Side::Side()
{
}

SideConnections* Side::connections()
{
	return connections_.get();
	
}

//Terrain* Side::terrain() 
//{ 
//	return terrain_.get();
//
//}

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
