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

//bool Surface::IsOpen(Position* position) const
//{
//  BOOST_FOREACH(Position* open_position, open_positions_) {
//    if(position->Equals(open_position)) {
//      return true;
//    }
//  }
//  return false;
//}
//
//bool Surface::PlaceTile(Position* position, Tile& tile)
//{
//  // The tile cannot be added to a position that is not open.
//  if(!IsOpen(position)) {
//    return false;
//  }
//
//  // The position is open so add a reference to the tile on the array of
//  // tiles_.
//  tiles_[position.dimension1()][position.dimension2()] = &tile;
//
//  // Add the positions opened up by the placed tile to open_positions_.
//  BOOST_FOREACH(Position* open_position, GetNewOpenPositions(position)) {
//    open_positions_.insert(open_position);
//  }
//
//  // The position is no longer open since the new tile is there so remove it
//  // from the open_positions_.
//  open_positions_.erase(position);
//
//  return true;
//}
//
//std::vector<Position> Surface::GetNeighborPositions(Position& position)
//{
//  std::vector<Position> neighbors(4);
//  neighbors.push_back(position.GetTopNeighbor());
//  neighbors.push_back(position.GetRightNeighbor());
//  neighbors.push_back(position.GetBottomNeighbor());
//  neighbors.push_back(position.GetLeftNeighbor());
//  return neighbors;
//}
//
//std::vector<Position> Surface::GetNewOpenPositions(Position& position)
//{
//  std::vector<Position> open_positions(4);
//  BOOST_FOREACH(Position neighbor, GetNeighborPositions(position)) {
//    if(IsOpen(neighbor)) {
//      open_positions.push_back(neighbor);
//    }
//  }
//
//  return open_positions;
//}

Surface::~Surface()
{
}

}