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
	
	/*
	 * Sets a vector of players with size depending on user input.  Players
	 * will be assigned a random color.
	 */ 
	void SetupPlayers();
	
	/**
	 * Starts the game.
	 */
	void Play();
	
	virtual ~Game();
	
 private:
	boost::scoped_ptr<Surface> surface_;
	boost::scoped_ptr<Bag> bag_;
	boost::ptr_vector<Player> players_;
	
};

}

#endif /*CARCASSONNE_GAME_H_*/
