/**
 * @file surface.h
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
#ifndef CARCASSONNE_SURFACE_H_
#define CARCASSONNE_SURFACE_H_

#include <map>

#include <boost/ptr_container/ptr_vector.hpp>

#include "tile.h"
#include "position.h"

#ifndef DISALLOW_COPY_AND_ASSIGN
// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)
#endif

namespace carcassonne {

class Surface {
 public:
  Surface();

	std::vector<Position> open_positions() const;

  /**
   * Checks to see if a position is an open position
   * 
   * @param position Position object that is to be checked in the open 
   *        positions.
   */
  bool IsOpen(const Position& position) const;

  /**
   * Checks to see if a position is a closed position
   * 
   * @param position Position object that is to be checked in the closed 
   *        positions.
   */
  bool IsClosed(const Position& position) const;
  
  /**
   * Checks to see if a Tile's top side will fit in with with the surface's
   * surrounding landscape.
   */
	bool IsTopTerrainFit(const Position& position, const Tile& top_tile) const;
	
	/**
   * Checks to see if a Tile's right side will fit in with with the surface's
   * surrounding landscape.
   */
	bool IsRightTerrainFit(const Position& position,
												 const Tile& right_tile) const;

  /**
   * Checks to see if a Tile's bottom side will fit in with with the surface's
   * surrounding landscape.
   */
	bool IsBottomTerrainFit(const Position& position,
												  const Tile& bottom_tile) const;
	
  /**
   * Checks to see if a Tile's left side will fit in with with the surface's
   * surrounding landscape.
   */
	bool IsLeftTerrainFit(const Position& position, const Tile& left_tile) const;
  
  /**
   * Checks to see if a tile will match the existing surrounding Tiles'
   * terrains.
   */
  bool IsTerrainsMatch(const Position& position, const Tile& tile) const;

	/**
	 * Checks to see if a specified tile will fit onto the surface at a 
	 * specified Position.
	 */
	bool IsTileFit(const Position& position, const Tile& tile) const;

  /**
   * Places a tile onto the surface and updates the surface's open 
   * positions by removing the used position and adding the new open
   * positions created by the new tile.
   * 
   * Note: This method does not check to see if the tile fits at the location.
   * It will place it regardless.
   * 
   * @param position The position on the surface that the tile will
   *        			   be added onto.
   * @param tile The tile to be added onto the surface.
   * @return true if the tile was able to be placed in the specified position.
   * false otherwise.
   */
  bool PlaceTile(const Position& position, const Tile& tile);

 	/**
   * Places a tile onto the Surface's kOriginPosition
   */
  bool PlaceStartingTile(const Tile& starting_tile);

  /**
   * Gets all positions surrounding a position.
   *
   * @param position Position object whos neighbors are of interest.
   * @return A vector of the positions surrounding the passed position.
   */
  std::vector<Position> GetNeighborPositions(const Position& position) const;
  
  /**
   * Gets all new positions that would be created by adding to a position
   *
   * @param position Position object to check on all four sides
   * @return A vector of all new open positions that would be created by
   *         placing a tile at the specified position.
   */
  std::vector<Position> GetNewOpenPositions(const Position& position) const;
  
  virtual void Render() const;

  ~Surface();

 private:
 	typedef std::map<Position, const Tile*> PositionMap;

  static const Position kOriginPosition;

	std::vector<Position> open_positions_;
  std::map<Position, const Tile*, LessThanPosition> tiles_;
  
	DISALLOW_COPY_AND_ASSIGN(Surface);
};

}

#endif /*CARCASSONNE_SURFACE_H_*/
