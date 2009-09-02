/**
 * @file position.h
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
#ifndef CARCASSONNE_POSITION_H_
#define CARCASSONNE_POSITION_H_

#include <string>

namespace carcassonne {

class Position {
 public:
 	Position();
  Position(int dimension1, int dimension2);
  bool Equals(const Position& position) const;

  int dimension1() const;
  int dimension2() const;

  Position* GetTopNeighbor() const;
  Position* GetRightNeighbor() const;
  Position* GetBottomNeighbor() const;
  Position* GetLeftNeighbor() const;
  
  virtual std::string ToString();
  
  

  ~Position();

 private:
  int dimension1_;
  int dimension2_;

};

}

#endif /*CARCASSONNE_POSITION_H_*/