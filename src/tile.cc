#include "tile.h"

#include "top_side.h"
#include "right_side.h"
#include "bottom_side.h"
#include "left_side.h"

namespace carcassonne
{

Tile::Tile(TerrainSideDecorator& top_terrain,
			     TerrainSideDecorator& right_terrain, 
					 TerrainSideDecorator& bottom_terrain,
					 TerrainSideDecorator& left_terrain)
{
	init_terrain_(top_terrain, right_terrain, bottom_terrain, left_terrain);
	
}

Tile& Tile::ConnectedTopToRight()
{
	top_side_->ConnectedToRight();
	right_side_->ConnectedToTop();
	return *this;
	
}

Tile& Tile::ConnectedTopToBottom()
{
	top_side_->ConnectedToBottom();
	bottom_side_->ConnectedToTop();
	return *this;
	
}

Tile& Tile::ConnectedTopToLeft()
{
	top_side_->ConnectedToLeft();
	left_side_->ConnectedToTop();
	return *this;
	
}

Tile& Tile::ConnectedRightToBottom()
{
	right_side_->ConnectedToBottom();
	bottom_side_->ConnectedToRight();
	return *this;
	
}

Tile& Tile::ConnectedRightToLeft()
{
	right_side_->ConnectedToLeft();
	left_side_->ConnectedToRight();
	return *this;
	
}

Tile& Tile::ConnectedBottomToLeft()
{
	bottom_side_->ConnectedToLeft();
	left_side_->ConnectedToBottom();
	return *this;
	
}


Tile* Tile::Copy()
{
	


	return new Tile();

}

std::string Tile::ToString()
{
	return	"tile with: \n\t" +
					top_side_->ToString() + "\n\t" +
					right_side_->ToString() + "\n\t" +
					bottom_side_->ToString() + "\n\t" +
				  left_side_->ToString() + "\n\n";
	
}	 

Tile::~Tile()
{
	
}

void Tile::init_terrain_(TerrainSideDecorator& top_terrain, 
									 			 TerrainSideDecorator& right_terrain,
									 			 TerrainSideDecorator& bottom_terrain,
									 			 TerrainSideDecorator& left_terrain)
{
	top_side_.reset(top_terrain.Decorate(new TopSide));
	right_side_.reset(right_terrain.Decorate(new RightSide));
	bottom_side_.reset(bottom_terrain.Decorate(new BottomSide));
	left_side_.reset(left_terrain.Decorate(new LeftSide));
	
}			 				 			 		

void Tile::init_connections_(SideConnections& top_connections,
												 		 SideConnections& right_connections,
												 		 SideConnections& bottom_connections,
												 		 SideConnections& left_connections)
{
	top_side_->set_connections(*top_connections.Copy());
	right_side_->set_connections(*right_connections.Copy());
	bottom_side_->set_connections(*bottom_connections.Copy());
	left_side_->set_connections(*left_connections.Copy());
	
}												 						

}
