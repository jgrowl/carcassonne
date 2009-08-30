#include "ptr_container_utility.h"

#include <algorithm> // For random_shuffle()
#include <ctime>		 // To seed system clock for use in random_shuffle()

namespace carcassonne
{

void random_shuffle(boost::ptr_vector<Tile>* shufflee)
{
	// Seed the system clock to give a random shuffle
	std::srand(std::time(NULL));
	
	// Shuffle them to randomize the colors.
	std::random_shuffle(shufflee->begin().base(), shufflee->end().base());

}

}