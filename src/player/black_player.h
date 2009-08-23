#ifndef CARCASSONNE_BLACK_PLAYER_H_
#define CARCASSONNE_BLACK_PLAYER_H_

#include "player.h"

namespace carcassonne
{

class BlackPlayer : public Player
{
public:
	BlackPlayer();
	
	virtual std::string ToString();
	
	virtual ~BlackPlayer();
};

}

#endif /*CARCASSONNE_BLACK_PLAYER_H_*/
