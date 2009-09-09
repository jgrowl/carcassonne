#include "black_player.h"

namespace carcassonne
{

BlackPlayer::BlackPlayer()
{
}

std::string BlackPlayer::ToString()
{
	return "black " + Player::ToString() ;
}

BlackPlayer::~BlackPlayer()
{
}

}
