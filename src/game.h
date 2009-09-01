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
#ifndef CARCASSONNE_GAME_H_
#define CARCASSONNE_GAME_H_

#include <boost/scoped_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#include "surface.h"
#include "bag.h"
#include "player/player.h"

namespace carcassonne
{

class Game
{
 public:
	Game();
	
	/**
	 * Starts the game.
	 */
	virtual void Play();
		
	virtual ~Game();
	
 private:
 	/**
 	 * Sets a vector of players with size depending on user input.  Players
 	 * will be assigned a random color.
	 */ 
	virtual void SetupPlayers_();
	
	/**
	 * Draws a single tile from bag_ and places it in current_tile_.
	 */
	virtual void Draw_();
	
	/**
	 * Places current_tile_ onto the surface.
	 */
	virtual void PlaceTile_();
	
	boost::scoped_ptr<Surface> surface_;
	boost::scoped_ptr<Bag> bag_;
	boost::ptr_vector<Player> players_;
	
	/**
	 * current_tile_ holds one tile that is drawn from the bag.  It should only
	 * be reset when Draw() is called and the current_tile_ is already placed.
	 */
	boost::ptr_vector<Tile> current_tile_;
	
};

}

#endif /*CARCASSONNE_GAME_H_*/
