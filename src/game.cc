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
  surface_.reset(new Surface());
  bag_.reset(new Bag());
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
	
	
	/////--------------------------------------
//	// Create all possible players.
//	BlackPlayer* black = new BlackPlayer();
//	RedPlayer* red = new RedPlayer();
//	GreenPlayer* green = new GreenPlayer();
//	
//	// Store all possible players in a vector.
//	std::vector<Player*> open_players;
//	open_players.push_back(black);
//	open_players.push_back(red);
//	open_players.push_back(green);
//	
//	// Seed the system clock to give a random shuffle
//	std::srand(std::time(NULL));
//	
//	// Shuffle them to randomize the colors.
//	std::random_shuffle(open_players.begin(), open_players.end());
//	
//	std::cout << "How many players? ";
//	
//	int player_count;
//	std::cin >> player_count;
//	
//	// Create a vector that will contain the actual players
//	std::vector<Player*> players;
//
//	// Save the desired number of players into the actual players vector
//	for(int i = 0; i < player_count; i++) {
//		players.push_back(open_players.back()); // Save it.
//		open_players.pop_back(); // Remove it from the vector
//	}
//	
//	// Clean up any open_players not used
//	for(std::vector<Player*>::iterator it = open_players.begin(); 
//			it !=open_players.end(); ++it) {
//		delete *it;		 	
//	}
//		
//	players_ = players;
	
}

void Game::play()
{
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
//	for(std::vector<Player*>::iterator it = players_.begin(); 
//			 it != players_.end(); ++it) {
//		delete *it;		 	
//	} 
}

}
