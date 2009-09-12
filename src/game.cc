#include "game.h"

#include <iostream>
#include <algorithm> // For random_shuffle()
#include <ctime>		 // To seed system clock for use in random_shuffle()
#include <limits>		 // For numeric_limits
#include <cstdio>		 // For printf()

#include "vector_utility.h"
#include "ptr_container_utility.h" // For ptr_vector_to_std_vector() and
																	 // shuffle()
#include "tile_set.h"

#include "player/black_player.h"
#include "player/red_player.h"
#include "player/green_player.h"

namespace carcassonne
{

Game::Game()
{
	// Create the standard TileSet.
	tile_set_.reset(new TileSet);
	
	// Place the starting tile.
	surface_.PlaceStartingTile(tile_set_->starting_tile_begin());
	
	// Fill the bag with the TileSet's bagable tiles.
	bag_.Fill(tile_set_->bagable_tiles());
	
	// Shuffle the bag.
	bag_.Shuffle();
	
	// Initially set the current_tile_ to NULL so it is clear that a tile
	// has not already been drawn.
	current_tile_ = NULL;
	
  SetupPlayers_();
}

void Game::SetupPlayers_()
{
	std::cout << "How many players? ";
	
	int player_count;
	std::cin >> player_count;
	
	CreatePlayers_(player_count);
}

void Game::CreatePlayers_(int number_of_players)
{
	// Make sure players is empty to start out with
	players_.clear();
	
	// Store all possible players in a temporary vector.
	std::vector<Player> open_players;
	open_players.push_back(BlackPlayer());
	open_players.push_back(RedPlayer());
	open_players.push_back(GreenPlayer());
	
	// Shuffle them to randomize the colors.
	utility::shuffle(open_players);
	
	// Save the desired number of players into the actual players vector
	for(int i = 0; i < number_of_players; i++) {
		players_.push_back(open_players.back());
		open_players.pop_back();
	}
}

void Game::Play()
{
	std::cout << "Playing Game..." << std::endl;
	
	while(!(bag_.IsEmpty()) /* While the bag is not empty... */) {
		// Cycle through players continuously until there are no more tiles
		for (std::vector<Player>::iterator it = players_.begin(); 
				it != players_.end() && !(bag_.IsEmpty()); ++it) {
			std::cout << "It is the " << (*it).ToString() << "'s turn.\n";
		
			// Draw a tile from the bag
			Draw_();
			
			// Render any tiles that are already placed as well as displaying
			// any open positions.
			surface_.Render();
			
			// Let player choose a position to place the tile
			PlaceTile_();
			
			// Lets the player place a follower if they desire.
			PlaceFollower_();
		}
	}
	
	std::cout << "The bag is empty...\n";
}

void Game::Draw_()
{
	// Check to make sure the tile has been played before a new one is drawn.
	if(current_tile_ != NULL) {
		std::cerr << "A tile has already been drawn but not placed." << std::endl;
		return;
	}
	
	// Draw a tile from the bag and place it in current_tile_
	current_tile_ = bag_.Draw();
	std::cout << "Player has drawn a " 
						<< current_tile_->ToString() 
						<< std::endl;
}

void Game::PlaceTile_()
{
	Position choice;
	do {
		// Get open positions and display to player.
		std::cout << "Choose where to place the tile: \n";
		//std::cout << surface_.open_positions().ToString() << std::endl;
		
		// If hint mode is turned on display only open positions where 
		// current tile will fit.
		
		// accept input from user as to where the tile will be placed.
		std::cout << "(-1 to rotate): ";
	
		int i;
		std::cin >> i;
		
		// Clear the buffer
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		if(i == -1) {
			current_tile_->Rotate();
			continue;
		}
		
		choice = surface_.open_positions().at(i);
		if(surface_.IsTileFit(choice, *current_tile_)) {
			surface_.PlaceTile(choice, *current_tile_);
			break;
		}
		
	} while(true);
	
	current_tile_ = NULL;
}

void Game::PlaceFollower_()
{
	std::cout << "Do you wish to place a follower?(y/n): ";
	
	// Clear the buffer
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	std::string wants_to_place;
	std::cin >> wants_to_place;
	
	if(wants_to_place == "y") {
		return;
	}
	
	std::cout << "Which side?(t,r,b,l): ";
	
	// Clear the buffer
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string side_to_place;
	if(side_to_place == "t") {
		
	}
	
	else if(side_to_place == "r") {
		
	}
	
	else if(side_to_place == "b") {
		
	}
	
	else if(side_to_place == "l") {
		
	}
	
	else {
		
	}
}

Game::~Game()
{

}

}
