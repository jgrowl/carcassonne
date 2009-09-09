#include "green_player.h"

namespace carcassonne
{

GreenPlayer::GreenPlayer()
{
}

std::string GreenPlayer::ToString()
{
	return "green " + Player::ToString();
}

GreenPlayer::~GreenPlayer()
{
}

}
