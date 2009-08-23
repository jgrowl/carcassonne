/***************************************************************************
 *   Copyright (C) 2009 by Jonathan Rowlands                               *
 *   jonrowlands83@gmail.com                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef CARCASSONNE_SURFACE_H_
#define CARCASSONNE_SURFACE_H_

#include <boost/scoped_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include "tile.h"
#include "position.h"

namespace carcassonne {

class Surface {
 public:
  Surface();

//  /**
//   * Checks to see if a position is an open position
//   * 
//   * @param position Position object that is to be checked in the open 
//   *        positions.
//   */
//  bool IsOpen(Position& position) const;
//
//  /**
//   * Places a tile onto the surface and updates the surface's open 
//   * positions by removing the used position and adding the new open
//   * positions created by the new tile.
//   * 
//   * @param position The position on the surface that the tile will
//   *        be added onto.
//   * @param tile The tile to be added onto the surface.
//   * @return true if the tile was correctly placed, false if there
//   *         there was a problem.
//   */
//  bool PlaceTile(Position& position, Tile& tile);
//
//  /**
//   * Gets all positions surrounding a position.
//   *
//   * @param position Position object whos neighbors are of interest.
//   * @return A vector of the positions surrounding the passed position.
//   */
//  std::vector<Position> GetNeighborPositions(Position& position);
//
//  /**
//   * Gets all new positions that would be created by adding to a position
//   *
//   * @param position Position object to check on all four sides
//   * @return A vector of all new open positions that would be created by
//   *         placing a tile at the specified position.
//   */
//  std::vector<Position> GetNewOpenPositions(Position& position);

  ~Surface();

 private:
  static const int kMaxRows_;
  static const int kMaxColumns_;

  static const boost::scoped_ptr<Position> kOriginPosition_;

  boost::ptr_vector<Position> open_positions_;

//  boost::array<boost::array<Tile*, 144>, 144> tiles_;
};

}

#endif /*CARCASSONNE_SURFACE_H_*/
