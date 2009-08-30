#include "tile.h"

#include "top_side.h"
#include "right_side.h"
#include "bottom_side.h"
#include "left_side.h"

namespace carcassonne
{

Tile::Tile() 
{
	init_sides_();
	
}

Tile::Tile(TerrainSideDecorator& top_terrain,
			     TerrainSideDecorator& right_terrain, 
					 TerrainSideDecorator& bottom_terrain,
					 TerrainSideDecorator& left_terrain)
{
	init_sides_();
	init_terrains_(top_terrain, right_terrain, bottom_terrain, left_terrain);
	
}

Tile::Tile(const Tile& src)
{
	
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

void Tile::set_top_side(Side* top)
{
	top_side_.reset(top);
	
}

void Tile::set_right_side(Side* right)
{
	right_side_.reset(right);
	
}

void Tile::set_bottom_side(Side* bottom)
{
	bottom_side_.reset(bottom);
	
}

void Tile::set_left_side(Side* left)
{
	left_side_.reset(left);
	
}

Tile* Tile::Copy() const
{
	Tile* tile = new Tile();
	tile->set_top_side(top_side_->Copy());
	tile->set_right_side(right_side_->Copy());
	tile->set_bottom_side(bottom_side_->Copy());
	tile->set_left_side(left_side_->Copy());
	return tile;
	
}

std::string Tile::ToString() const
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

void Tile::init_sides_()
{
	top_side_.reset(new TopSide);
	right_side_.reset(new RightSide);
	bottom_side_.reset(new BottomSide);
	left_side_.reset(new LeftSide);
	
}

void Tile::init_terrains_(TerrainSideDecorator& top_terrain, 
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
