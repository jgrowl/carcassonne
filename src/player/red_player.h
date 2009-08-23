#ifndef CARCASSONNE_RED_PLAYER_H_
#define CARCASSONNE_RED_PLAYER_H_

#include "player.h"

namespace carcassonne
{

class RedPlayer : public Player
{
public:
	RedPlayer();
	
	virtual std::string ToString();
	
	virtual ~RedPlayer();
};

}

#endif /*CARCASSONNE_RED_PLAYER_H_*/
