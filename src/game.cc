#include "game.h"

#include <algorithm> // For random_shuffle()
#include <ctime>		 // To seed system clock for use in random_shuffle()

#include <boost/foreach.hpp>

#include "player/black_player.h"
#include "player/red_player.h"
#include "player/green_player.h"

namespace carcassonne
{

Game::Game()
{
  surface_.reset(new Surface);
  bag_.reset(new Bag);
  SetupPlayers();
}

void Game::SetupPlayers()
{
	// Make sure players is empty to start out with
	players_.clear();
	
	// Store all possible players in a temporary vector.
	boost::ptr_vector<Player> open_players;
	open_players.push_back(new BlackPlayer);
	open_players.push_back(new RedPlayer);
	open_players.push_back(new GreenPlayer);

	// Seed the system clock to give a random shuffle
	std::srand(std::time(NULL));
	
	// Shuffle them to randomize the colors.
	std::random_shuffle(open_players.begin().base(), open_players.end().base());
	
	std::cout << "How many players? ";
	
	int player_count;
	std::cin >> player_count;
	
	// Save the desired number of players into the actual players vector
	for(int i = 0; i < player_count; i++) {
		players_.transfer(players_.end(), open_players.begin(), open_players);
	}
	
}

void Game::play()
{
	std::cout << "Playing Game..." << std::endl;
	while(false /* Check number of tiles in bag */) {
		for (boost::ptr_vector<Player>::iterator it = players_.begin(); 
				it != players_.end() && false /* Check number of tiles in bag */; ++it) {
			std::cout << "It is the " << (*it).ToString() << "'s turn.\n";
			// Draw a tile from the bag
			// Let player choose a position to place the tile
			// Check it is an open position
			// Check that it fits
		}
	}
}

Game::~Game()
{

}

}
