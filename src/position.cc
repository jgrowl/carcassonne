/**
 * @file game.h
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
#include "position.h"

namespace carcassonne {

Position::Position()
{
	dimension1_ = 0;
	dimension2_ =	0;
	
}

Position::Position(int dimension1, int dimension2)
{
  dimension1_ = dimension1;
  dimension2_ = dimension2;
  
}

bool Position::Equals(const Position& position) const
{
  if(dimension1_ == position.dimension1() 
     && dimension2_ == position.dimension2()) {
    return true;
  }

  return false;
  
}

int Position::dimension1() const
{
  return dimension1_;
}

int Position::dimension2() const
{
  return dimension2_;
}

Position* Position::GetTopNeighbor() const
{
  return new Position(dimension1_, dimension2_ + 1);
}

Position* Position::GetRightNeighbor() const
{
  return new Position(dimension1_ + 1, dimension2_);
}

Position* Position::GetBottomNeighbor() const
{
  return new Position(dimension1_, dimension2_ - 1);
}

Position* Position::GetLeftNeighbor() const
{
  return new Position(dimension1_ - 1, dimension2_);
}


Position::~Position()
{
}

}