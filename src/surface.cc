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

const Position Surface::kOriginPosition;

Surface::Surface()
{
	open_positions_.push_back(kOriginPosition);
}

std::vector<Position> Surface::open_positions() const
{
	return open_positions_;
}

bool Surface::IsOpen(const Position& position) const
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

bool Surface::IsClosed(const Position& position) const
{
	if(tiles_.find(position) == tiles_.end()) {
		return false;
	}
  
  return true;
}

/**
 * Checks to see if a Tile's top side will fit in with with the surface's
 * surrounding landscape.
 */
bool Surface::
	IsTopTerrainFit(const Position& in_position, const Tile& in_tile) const
{
	PositionMap::const_iterator top_it 
		= tiles_.find(in_position.GetTopNeighbor());
	
	const Tile& top_tile = *(top_it->second);
	
	// If there is no tile in the top position.
	if(top_it == tiles_.end()) {
		return true;	
	}
	
	if(in_tile.IsTopTerrainMatch(top_tile)) {
		return true;
	}
	
	return false;	
}

/**
 * Checks to see if a Tile's right side will fit in with with the surface's
 * surrounding landscape.
 */
bool Surface::
	IsRightTerrainFit(const Position& in_position, const Tile& in_tile) const
{
	PositionMap::const_iterator right_it 
		= tiles_.find(in_position.GetRightNeighbor());
	
	const Tile& right_tile = *(right_it->second);
	
	// If there is no tile in the right position.
	if(right_it == tiles_.end()) {
		return true;	
	}
	
	if(in_tile.IsRightTerrainMatch(right_tile)) {
		return true;
	}
	
	return false;	
}

/**
 * Checks to see if a Tile's bottom side will fit in with with the surface's
 * surrounding landscape.
 */
bool Surface::
	IsBottomTerrainFit(const Position& in_position, const Tile& in_tile) const
{
	PositionMap::const_iterator bottom_it 
		= tiles_.find(in_position.GetBottomNeighbor());
	
	const Tile& bottom_tile = *(bottom_it->second);
		
	// If there is no tile in the bottom position.
	if(bottom_it == tiles_.end()) {
		return true;	
	}

	if(in_tile.IsBottomTerrainMatch(bottom_tile)) {
		return true;
	}
	
	return false;	
}

/**
 * Checks to see if a Tile's left side will fit in with with the surface's
 * surrounding landscape.
 */
bool Surface::
	IsLeftTerrainFit(const Position& in_position, const Tile& in_tile) const
{
	PositionMap::const_iterator left_it 
		= tiles_.find(in_position.GetLeftNeighbor());
	
	const Tile& left_tile = *(left_it->second);

	// If there is no tile in the left position.
	if(left_it == tiles_.end()) {
		return true;	
	}
		
	if(in_tile.IsLeftTerrainMatch(left_tile)) {
		return true;
	}
	
	return false;	
}

bool Surface::
	IsTerrainsMatch(const Position& position, const Tile& tile) const
{
	if(IsTopTerrainFit(position, tile) 
			&& IsRightTerrainFit(position, tile)
			&& IsBottomTerrainFit(position, tile)
			&& IsLeftTerrainFit(position, tile)) {
				
		return true;
	}
	
	return false;
}

bool Surface::
	IsTileFit(const Position& position, const Tile& tile) const
{
  // The tile cannot be added to a position that is not open.
  if(!IsOpen(position)) {
		std::cout << "That position already has a tile!\n";
    return false;
  }

	if(!IsTerrainsMatch(position, tile)) {
		std::cout << "Terrain does not match!\n";
		return false;
	}
	
	return true;
}

bool Surface::PlaceTile(const Position& position, const Tile& tile)
{	
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
  
  return true;
}

/**
 * Places a tile onto the Surface's kOriginPosition
 */
bool Surface::
	PlaceStartingTile(const Tile& starting_tile)
{
	return PlaceTile(kOriginPosition, starting_tile);
}

std::vector<Position> Surface::
	GetNeighborPositions(const Position& position) const
{
	std::vector<Position> neighbors(4);
  
  neighbors.push_back(position.GetTopNeighbor());
  neighbors.push_back(position.GetRightNeighbor());
  neighbors.push_back(position.GetBottomNeighbor());
  neighbors.push_back(position.GetLeftNeighbor());
  
  return neighbors;
}

std::vector<Position> Surface::
	GetNewOpenPositions(const Position& position) const
{
	// Put all of the position's neighbor positions into a temporary variable.
	std::vector<Position> possible_positions = GetNeighborPositions(position);
	
	// Create a container to put all of the open positions from 
	// possible_positions in.
  std::vector<Position> open_positions;

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
	for(PositionMap::const_iterator i = tiles_.begin(),
																	e = tiles_.end();
			i != e; ++i) {
		std::cout << i->first.ToString() << std::endl
							<< i->second->ToString() << std::endl;
	}
	
	std::cout << "Displaying open positions...\n";
	for(unsigned int i = 0; i < open_positions_.size(); ++i) {
		std::cout << "[" << i << "] " << open_positions_[i].ToString() 
							<< std::endl; 
	}
	
}

Surface::~Surface()
{
}

}