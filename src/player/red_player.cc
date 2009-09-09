#include "red_player.h"

namespace carcassonne
{

RedPlayer::RedPlayer()
{
}

std::string RedPlayer::ToString()
{
	return "red " + Player::ToString();
}

RedPlayer::~RedPlayer()
{
}

}
