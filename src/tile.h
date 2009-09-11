#ifndef CARCASSONNE_TILE_H_
#define CARCASSONNE_TILE_H_

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
 	Tile();
 	Tile(TerrainSideDecorator& top_terrain,
	     TerrainSideDecorator& right_terrain, 
			 TerrainSideDecorator& bottom_terrain,
			 TerrainSideDecorator& left_terrain);
	Tile(const Tile&);
	Tile& operator=(const Tile&);
	
	void CopyFrom(const Tile&);
	Tile* Clone() const;
	 
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
	
	void set_top_side(Side* top);
	void set_right_side(Side* top);
	void set_bottom_side(Side* top);
	void set_left_side(Side* top);
 	
 	virtual void Rotate();
 	
	std::string ToString() const;	
	
	/**
	 * @return The address to the relative top side of the tile adjusted by
	 * the tile's rotation.
	 */
	virtual Side* GetAdjustedTopSide() const;
	virtual Side* GetAdjustedRightSide() const;
	virtual Side* GetAdjustedBottomSide() const;
	virtual Side* GetAdjustedLeftSide() const;
	
	virtual bool IsTopTerrainMatch(Tile& top_tile) const;
	virtual bool IsRightTerrainMatch(Tile& right_tile) const;
	virtual bool IsBottomTerrainMatch(Tile& bottom_tile) const;
	virtual bool IsLeftTerrainMatch(Tile& left_tile) const;
	
  virtual ~Tile();
  
 private:
	static const int kNoRotation;
	static const int kQuarterRotation;
	static const int kFullRotation;
 
 	virtual void init_sides_();
 
	virtual void init_terrains_(TerrainSideDecorator& top_terrain, 
											 			  TerrainSideDecorator& right_terrain,
											 			  TerrainSideDecorator& bottom_terrain,
											 			  TerrainSideDecorator& left_terrain);
												 
 	boost::scoped_ptr<Side> top_side_;
 	boost::scoped_ptr<Side> right_side_;
 	boost::scoped_ptr<Side> bottom_side_;
 	boost::scoped_ptr<Side> left_side_;
 	
 	int orientation_;
 	
};

}

#endif /*CARCASSONNE_TILE_H_*/
