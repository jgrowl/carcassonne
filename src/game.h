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
	// Keeps track of whether the current tile has been placed or not.
 	bool is_tile_placed_;
 	
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
	boost::scoped_ptr<Tile> current_tile_;
	
};

}

#endif /*CARCASSONNE_GAME_H_*/
