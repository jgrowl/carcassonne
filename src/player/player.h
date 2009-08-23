#ifndef CARCASSONNE_PLAYER_H_
#define CARCASSONNE_PLAYER_H_

#include <string>

namespace carcassonne
{

class Player
{
 public:
	Player();
	
	virtual std::string ToString() = 0;
	
	virtual ~Player();
	
 private:
 	int followers_;
 	int score_;
};

}

#endif /*CARCASSONNE_PLAYER_H_*/
