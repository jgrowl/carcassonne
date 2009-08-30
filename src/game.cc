#include "game.h"

#include <iostream>
#include <algorithm> // For random_shuffle()
#include <ctime>		 // To seed system clock for use in random_shuffle()

//#include <boost/foreach.hpp>

#include "player/black_player.h"
#include "player/red_player.h"
#include "player/green_player.h"

namespace carcassonne
{

Game::Game()
{
	is_tile_placed_ = true;
  surface_.reset(new Surface);
  bag_.reset(new Bag);
  SetupPlayers_();
}

void Game::SetupPlayers_()
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

void Game::Play()
{
	std::cout << "Playing Game..." << std::endl;
	while(!(bag_->IsEmpty()) /* While the bag is not empty... */) {
		// Cycle through players continuously until there are no more tiles
		for (boost::ptr_vector<Player>::iterator it = players_.begin(); 
				it != players_.end() && !(bag_->IsEmpty()); ++it) {
			std::cout << "It is the " << (*it).ToString() << "'s turn.\n";
		
			// Draw a tile from the bag
			Draw_();
			
			// Let player choose a position to place the tile
			PlaceTile_();
			
		}
	}
}

void Game::Draw_()
{
	// Check to make sure the tile has been played before a new one is drawn.
	if(!is_tile_placed_) {
		std::cerr << "A tile has already been drawn but not placed." << std::endl;
		return;
	}
	
	// Draw a tile from the bag and place it in current_tile_
	bag_->Draw(&current_tile_);
	std::cout << "Current Tile is: " << current_tile_->ToString() << std::endl;
	
	// Update the game's state to reflect the tile has been
	is_tile_placed_ = true;
	
}

void Game::PlaceTile_()
{
	// Check it is an open position
	// Check that it fits
//	int i;
//	std::cin >> i;
}

Game::~Game()
{

}

}
