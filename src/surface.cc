/**
 * @file surface.cc
 * @author Jonathan Rowlands <j.growl1983@gmail.com>
 * 
 * @section LICENSE
 * 
 *      This file is part of carcassone.
 *
 * carcassonne is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * carcassonne is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with carcassonne.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "surface.h"

#include <iostream>

#include <boost/foreach.hpp>

#include "valid_tiles.h"

namespace carcassonne {

const int Surface::kMaxRows_ = 156;
const int Surface::kMaxColumns_ = 156;
boost::scoped_ptr<Position> 
	Surface::kOriginPosition_(new Position(kMaxRows_/2, kMaxColumns_/2));

Surface::Surface()
{
	open_positions_.push_back(kOriginPosition());
	
	// This is hackish...  Needs to be structured better. 
  ValidTiles valid_tiles;
  boost::ptr_vector<Tile> starting_tiles;
  starting_tiles.push_back(valid_tiles.starting_tile());
  std::cout << "Placing starting tile...\n";
  PlaceTile(*kOriginPosition(), &starting_tiles);

}

Position* Surface::kOriginPosition()
{
	return kOriginPosition_.get();
	
}

PositionsContainer& Surface::open_positions()
{
	return open_positions_;
	
}

bool Surface::IsOpen(Position& position) const
{
  BOOST_FOREACH(Position open_position, open_positions_) {
    if(position.Equals(open_position)) {
      return true;
    }
  }
  return false;
}

void Surface::PlaceTile(Position& position, boost::ptr_vector<Tile>* tile)
{
	typedef boost::ptr_vector<Position> Pos_ptr_vec;
	
  // The tile cannot be added to a position that is not open.
  if(!IsOpen(position)) {
  	// Throw exception
//    return;
  }

	// TODO: Make sure the tile matches the surface's terrain.

  // The position is open so add a reference to the tile on the array of
  // tiles_.
	tiles_[position.dimension1()].replace(position.dimension2(), 
																				tile->pop_back().release());
  
	// Get all new positions that will be created by placing the tile
	Pos_ptr_vec new_open_positions = GetNewOpenPositions(position);

  // Add the positions opened up by the placed tile to open_positions_.
  while(new_open_positions.size() > 0) {
  	open_positions_.push_back(new_open_positions.pop_back().release());
  			
  }
  
  // The position is no longer open since the new tile is there so remove it
  // from the open_positions_.
  for(unsigned int i = 0; i < open_positions_.size(); ++i) {
		if(position.Equals(open_positions_[i])) {
			closed_positions_.push_back(open_positions_
				.release(open_positions_.begin() + i).release());
		
		}
  
  }
   
}

boost::ptr_vector<Position> Surface::GetNeighborPositions(Position& position)
{
	boost::ptr_vector<Position> neighbors(4);
  
  neighbors.push_back(position.GetTopNeighbor());
  neighbors.push_back(position.GetRightNeighbor());
  neighbors.push_back(position.GetBottomNeighbor());
  neighbors.push_back(position.GetLeftNeighbor());
  
  return neighbors;
  
}

boost::ptr_vector<Position> Surface::GetNewOpenPositions(Position& position)
{
	// Put all of the position's neighbor positions into a temporary variable.
	boost::ptr_vector<Position> possible_positions = 
																							GetNeighborPositions(position);
	
	// Create a container to put all of the open positions from 
	// possible_positions in.
  boost::ptr_vector<Position> open_positions(4);

  // Iterate through possible_positions and add any actual open position
  // to the open_positions container.
  while(possible_positions.size() > 0) {
  	if(!IsOpen(possible_positions.back())) {
  		open_positions.push_back(possible_positions.pop_back().release());
  	
  	} else {
  		// If the position is not open then it must already exist in the open
  		// positions, so throw it away.
  		possible_positions.pop_back();
  	}
  		
  }

  return open_positions;
}

void Surface::Render()
{
	std::cout << "Displaying current board...\n";
	for(PositionsContainer::iterator i = closed_positions_.begin(),
																	 e = closed_positions_.end(); i != e; ++i) {
		std::cout << i->ToString();
		std::cout << tiles_[i->dimension1()][i->dimension2()].ToString();

	}
	
}

Surface::~Surface()
{
}

}