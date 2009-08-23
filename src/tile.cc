#include "tile.h"

#include "terrain/terrain.h"
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

//Tile::Tile(Terrain& top_terrain,
//					 Terrain& right_terrain, 
//					 Terrain& bottom_terrain, 
//					 Terrain& left_terrain)
//{
//	init_(top_terrain, right_terrain, bottom_terrain, left_terrain);
//	
//}
//
//Tile::Tile(Terrain* top_terrain,
//					 Terrain* right_terrain,
//					 Terrain* bottom_terrain, 
//					 Terrain* left_terrain)
//{
//	init_(*top_terrain, *right_terrain, *bottom_terrain, *left_terrain);
//	
//}  

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
//	//TODO: Copy connections
//	return new Tile(*top_side_,
//									*right_side_,
//									*bottom_side_,
//									*left_side_);
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

//void Tile::init_(Terrain& top_terrain, 
//								 Terrain& right_terrain,
//			 			     Terrain& bottom_terrain,
//			 			     Terrain& left_terrain)
//{
//	init_terrain_(top_terrain, right_terrain, bottom_terrain, left_terrain);
//	
//}

//void Tile::init_terrain_(Terrain& top_terrain, 
//								   			 Terrain& right_terrain,
//					 				  	   Terrain& bottom_terrain,
//					 				 			 Terrain& left_terrain)
//{
//	// remove sending terrain to each side and decorate with the correct
//	// terrain decorator.  ex. top_terrain.Decorate(new TopSide)
//	top_side_.reset(new TopSide(top_terrain));
//	right_side_.reset(new RightSide(right_terrain));
//	bottom_side_.reset(new BottomSide(bottom_terrain));
//	left_side_.reset(new LeftSide(left_terrain));
//		
//}					 				 			 		

void Tile::init_connections_(SideConnections& top_connections,
												 		 SideConnections& right_connections,
												 		 SideConnections& bottom_connections,
												 		 SideConnections& left_connections)
{
	top_side_->set_connections(top_connections);
	right_side_->set_connections(right_connections);
	bottom_side_->set_connections(bottom_connections);
	left_side_->set_connections(left_connections);
}												 						

}
