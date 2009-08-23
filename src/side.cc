#include "side.h"

namespace carcassonne
{

Side::Side()
{
}

//Side::Side(Terrain& terrain)
//{
//	terrain_.reset(terrain.GetNewTerrain());
//	
//}
//
//Side::Side(Terrain* terrain, SideConnections* connections)
//{
//	terrain_.reset(terrain->GetNewTerrain());
//	connections_.reset(connections->Copy());
//	
//}

SideConnections* Side::connections()
{
	return connections_.get();
	
}

Terrain* Side::terrain() 
{ 
	return terrain_.get();

}

void Side::set_connections(SideConnections& connections)
{
	connections_.reset(connections.Copy());
	
}

void Side::ConnectedToMiddle()
{
	connections_->set_middle(true);
	
}

bool Side::IsConnectedToMiddle()
{
	return connections_->middle();
	
}

std::string Side::ToString()
{
	return "side with " + connections_->ToString();
	
}

Side::~Side()
{
	
}

}
