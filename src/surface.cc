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
#include <iostream>

#include <boost/foreach.hpp>

#include "surface.h"

namespace carcassonne {

const int Surface::kMaxRows_ = 144;
const int Surface::kMaxColumns_ = 144;
const boost::scoped_ptr<Position> 
	Surface::kOriginPosition_(new Position(kMaxRows_, kMaxColumns_));

Surface::Surface()
{
  // Originally the open positions are those that surround the orgin.
  // Thus they should be added to the set initially.
  open_positions_.push_back(kOriginPosition_->GetTopNeighbor());
  open_positions_.push_back(kOriginPosition_->GetRightNeighbor());
  open_positions_.push_back(kOriginPosition_->GetBottomNeighbor());
  open_positions_.push_back(kOriginPosition_->GetLeftNeighbor());
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
  for(Pos_ptr_vec::iterator i = new_open_positions.begin(),
  													e = new_open_positions.end();
  		i != e; ++i) {
  			open_positions_.transfer(open_positions_.end(),
  															 i,
  															 new_open_positions);
  			
  }
  
  // The position is no longer open since the new tile is there so remove it
  // from the open_positions_.
  for(Pos_ptr_vec::iterator i = open_positions_.begin(), 
  													e = open_positions_.end();
  		i != e; ++i) {
  	if(position.Equals(*i)) {
  		open_positions_.erase(i);
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
  for(boost::ptr_vector<Position>::iterator	i =	possible_positions.begin(),
  																					e = possible_positions.end();
			i != e; ++i) {
		if(IsOpen(*i)) {
			open_positions.transfer(open_positions.end(), i, possible_positions);
		}
	}

  return open_positions;
}

Surface::~Surface()
{
}

}