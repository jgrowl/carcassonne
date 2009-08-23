#ifndef CARCASSONNE_TILE_H_
#define CARCASSONNE_TILE_H_

#include <iostream>
#include <string>

#include <boost/scoped_ptr.hpp>

#include "side.h"

#include "top_side_connections.h"
#include "right_side_connections.h"
#include "bottom_side_connections.h"
#include "left_side_connections.h"

#include "terrain_side_decorator.h"

namespace carcassonne
{
	
class Tile
{
 public:
 	Tile() { }
 	Tile(TerrainSideDecorator& top_terrain,
	     TerrainSideDecorator& right_terrain, 
			 TerrainSideDecorator& bottom_terrain,
			 TerrainSideDecorator& left_terrain);
 
//	Tile(Terrain& top_terrain,
//	     Terrain& right_terrain, 
//			 Terrain& bottom_terrain,
//			 Terrain& left_terrain);
//		 
//	Tile(Terrain* top_terrain,
//			 Terrain* right_terrain,
//			 Terrain* bottom_terrain,
//			 Terrain* left_terrain);
	 
	/**
	 * Used for Named Parameter Idiom. Allows method chaining in constructor.
	 * http://www.parashift.com/c++-faq-lite/ctors.html#faq-10.18
	 * 
	 * @return reference to called object with a changed state.
	 */
	Tile& ConnectedTopToRight();
	Tile& ConnectedTopToBottom();
	Tile& ConnectedTopToLeft();
	Tile& ConnectedRightToBottom();
	Tile& ConnectedRightToLeft();
	Tile& ConnectedBottomToLeft();
 	
	Tile* Copy();
	std::string ToString();	
 
  virtual ~Tile();
  
 private:
	void init_terrain_(TerrainSideDecorator& top_terrain, 
							 			 TerrainSideDecorator& right_terrain,
							 			 TerrainSideDecorator& bottom_terrain,
							 			 TerrainSideDecorator& left_terrain);
 
//	void init_(Terrain& top_terrain, 
//			 			 Terrain& right_terrain,
//			 			 Terrain& bottom_terrain,
//			 			 Terrain& left_terrain);
//			 
//	void init_terrain_(Terrain& top_terrain, 
//									   Terrain& right_terrain,
//						 				 Terrain& bottom_terrain,
//						 				 Terrain& left_terrain);						 				 
			 			     	 
	void init_connections_(SideConnections& top_connections,
												 SideConnections& right_connections,
												 SideConnections& bottom_connections,
												 SideConnections& left_connections);	
												 
 	boost::scoped_ptr<Side> top_side_;
 	boost::scoped_ptr<Side> right_side_;
 	boost::scoped_ptr<Side> bottom_side_;
 	boost::scoped_ptr<Side> left_side_;
 	
};

}

#endif /*CARCASSONNE_TILE_H_*/
