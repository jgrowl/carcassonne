/**
 * @file bottom_side_connections.h
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
#ifndef CARCASSONNE_BOTTOM_SIDE_CONNECTIONS_H_
#define CARCASSONNE_BOTTOM_SIDE_CONNECTIONS_H_

#include <string>
#include <vector>

#include "side_connections.h"

namespace carcassonne
{

/**
 * @section DESCRIPTION
 * 
 * The BottomSideConnections class represents a BottomSide's connections to
 * other sides in a Tile object.
 */
class BottomSideConnections : public SideConnections
{
 public:
	/** 
	 * Default constructor that sets all connections to false.
	 */
	BottomSideConnections();
	
	/**
	 * Constructor that sets the BottomSideConnections' values to a given value.
	 * 
	 * @param clockwise True if there is a connection.
	 * @param across True if there is a connection.
	 * @param counterclockwise True if there is a connection.
	 * @param middle True if there is a connection.
	 */
	BottomSideConnections(bool clockwise,
											  bool across,
											  bool counterclockwise,
											  bool middle);
											  
	/**
	 * Copy constructor
	 * Tiles need to be deep copyable so BottomSideConnections must be
	 * copyable.
	 */
	BottomSideConnections(const BottomSideConnections&);
	
	virtual SideConnections* Copy() const;
	
	virtual std::vector<std::string> ToStringVector() const;
	
	virtual ~BottomSideConnections();
};

}

#endif /*CARCASSONNE_BOTTOM_SIDE_CONNECTIONS_H_*/
