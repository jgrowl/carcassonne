#ifndef CARCASSONNE_GREEN_PLAYER_H_
#define CARCASSONNE_GREEN_PLAYER_H_

#include "player.h"

namespace carcassonne
{

class GreenPlayer : public Player
{
public:
	GreenPlayer();
	
	virtual std::string ToString();
	
	virtual ~GreenPlayer();
};

}

#endif /*CARCASSONNE_GREEN_PLAYER_H_*/
