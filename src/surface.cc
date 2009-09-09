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
#include <algorithm>

#include "valid_tiles.h"

namespace carcassonne {

Surface::Surface()
{
	open_positions_.push_back(kOriginPosition_);
}

Position& Surface::kOriginPosition()
{
	return kOriginPosition_;
}

std::vector<Position> Surface::open_positions()
{
	return open_positions_;
	
}

bool Surface::IsOpen(Position& position) const
{
	for(std::vector<Position>::const_iterator i = open_positions_.begin(),
																						e = open_positions_.end();
			i != e; ++i) {
		if(position.Equals(*i)) {
			return true;
		}			
	}
  
  return false;
}

bool Surface::IsClosed(Position& position) const
{
	if(tiles_.find(position) == tiles_.end()) {
		return false;
	}
  
  return true;
}

void Surface::PlaceTile(Position& position, Tile& tile)
{	
  // The tile cannot be added to a position that is not open.
  if(!IsOpen(position)) {
  	// Throw exception
    return;
  }

	// TODO: Make sure the tile matches the surface's terrain.

  // The position is open so add a reference to the tile on the array of
  // tiles_.
	tiles_[position] = &tile;
  
	// Get all new positions that will be created by placing the tile
	std::vector<Position> new_open_positions = GetNewOpenPositions(position);

  // Add the positions opened up by the placed tile to open_positions_.
  while(new_open_positions.size() > 0) {
  	open_positions_.push_back(new_open_positions.back());
  	new_open_positions.pop_back();
  }

  // The position is no longer open since the new tile is there so remove it
  // from the open_positions_.
  std::remove(open_positions_.begin(), open_positions_.end(), position);
}

std::vector<Position> Surface::GetNeighborPositions(Position& position)
{
	std::vector<Position> neighbors(4);
  
  neighbors.push_back(position.GetTopNeighbor());
  neighbors.push_back(position.GetRightNeighbor());
  neighbors.push_back(position.GetBottomNeighbor());
  neighbors.push_back(position.GetLeftNeighbor());
  
  return neighbors;
}

std::vector<Position> Surface::GetNewOpenPositions(Position& position)
{
	// Put all of the position's neighbor positions into a temporary variable.
	std::vector<Position> possible_positions = GetNeighborPositions(position);
	
	// Create a container to put all of the open positions from 
	// possible_positions in.
  std::vector<Position> open_positions(4);

  // Iterate through possible_positions and add any actual open position
  // to the open_positions container.
  while(possible_positions.size() > 0) {
  	Position check_position = possible_positions.back();
  	if(!IsOpen(check_position) && !IsClosed(check_position)) {
  		open_positions.push_back(check_position);
  	}
  	
  	possible_positions.pop_back();
  }

  return open_positions;
}

void Surface::Render() const
{
	std::cout << "Displaying current board...\n";
	for(std::map<Position, Tile*>::const_iterator i = tiles_.begin(),
																			 					e = tiles_.end();
			i != e; ++i) {
		std::cout << i->first.ToString() << std::endl
							<< i->second->ToString() << std::endl;
	}
	
}

Surface::~Surface()
{
}

}