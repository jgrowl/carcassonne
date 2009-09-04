#include "game.h"

#include <iostream>
#include <algorithm> // For random_shuffle()
#include <ctime>		 // To seed system clock for use in random_shuffle()
#include <limits>

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
	
	// Create the standard Surface.
	surface_.reset(new Surface);
	
	// Create a standard Bag
	bag_.reset(new Bag);
	
	// Get a copy of the starting Tile from the TileSet.
	starting_tile_begin_.reset(tile_set_->starting_tile_begin_copy());
	
	// Get a copy of the bagable Tiles from the TileSet.
	bagable_tiles_ = tile_set_->bagable_tiles_copy();
	
	// Fill the bag with the TileSet's bagable tiles.
	bag_->Fill(utility::ptr_vector_to_std_vector(bagable_tiles_));
	
	// Shuffle the bag.
	bag_->Shuffle();
	
	// Initially set the current_tile_ to NULL so it is clear that a tile
	// has not already been drawn.
	current_tile_ = NULL;
	
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
	
	// Shuffle them to randomize the colors.
	utility::shuffle(&open_players);
		
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
		
			surface_->Render();
		
			// Draw a tile from the bag
			Draw_();
			
			// Let player choose a position to place the tile
			PlaceTile_();
			
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
	current_tile_ = bag_->Draw();
	std::cout << "Player has drawn a " 
						<< current_tile_->ToString() 
						<< std::endl;
	
}

void Game::PlaceTile_()
{
	// Get open positions and display to player.
	std::cout << "Choose where to place the tile: \n";
	std::cout << surface_->open_positions().ToString() << std::endl;
	
	// If hint mode is turned on display only open positions where 
	// current tile will fit.
	
	// accept input from user as to where the tile will be placed.
	std::cout << ": ";

	int i;
	std::cin >> i;
	
	// Clear the buffer
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	Position choice = surface_->open_positions().at(i);
	std::cout << "Getting ready to place...\n";
	surface_->PlaceTile(choice, *current_tile_);

}

Game::~Game()
{

}

}
