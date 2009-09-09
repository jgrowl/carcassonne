#include "player.h"

namespace carcassonne
{

Player::Player()
{
	followers_ = 5;
	score_ = 0;
}

std::string Player::ToString()
{
	return "player";
}

Player::~Player()
{
}

}
