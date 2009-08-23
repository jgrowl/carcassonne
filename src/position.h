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
#ifndef CARCASSONNE_POSITION_H_
#define CARCASSONNE_POSITION_H_

namespace carcassonne {

class Position {
 public:
  Position(int dimension1, int dimension2);
  bool Equals(const Position& position) const;

  int dimension1() const;
  int dimension2() const;

  Position* GetTopNeighbor() const;
  Position* GetRightNeighbor() const;
  Position* GetBottomNeighbor() const;
  Position* GetLeftNeighbor() const;

  ~Position();

 private:
  int dimension1_;
  int dimension2_;

};

}

#endif /*CARCASSONNE_POSITION_H_*/