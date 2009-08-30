/**
 * @file top_side.h
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
#ifndef CARCASSONNE_TOP_SIDE_H_
#define CARCASSONNE_TOP_SIDE_H_

#include <string>

#include "side.h"
#include "terrain/terrain_segment.h"

namespace carcassonne
{

class TopSide : public Side
{
 public:
 	TopSide();
 	TopSide(TerrainSegment& middle, SideConnections& connections);
 	TopSide(const TopSide&);

/**
 * Sets the connection to true
 */
	virtual void ConnectedToTop();
	virtual void ConnectedToRight();
	virtual void ConnectedToBottom();
	virtual void ConnectedToLeft();

/**
 * returns true if the side is connected
 */
  virtual bool IsConnectedToTop();
  virtual bool IsConnectedToRight();
  virtual bool IsConnectedToBottom();
  virtual bool IsConnectedToLeft();

	virtual Side* Copy() const;
  virtual std::string ToString() const;

  virtual ~TopSide();

};

}

#endif /*CARCASSONNE_TOP_SIDE_H_*/
