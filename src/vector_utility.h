#ifndef CARCASSONNE_VECTOR_UTILITY_H_
#define CARCASSONNE_VECTOR_UTILITY_H_

#include <algorithm> // For random_shuffle()
#include <ctime>		 // To seed system clock for use in random_shuffle()

namespace carcassonne
{
namespace utility
{

template <typename T>
void shuffle(std::vector<T>& vector_to_shuffle)
{
	// Seed the system clock to give a random shuffle
	std::srand(std::time(NULL));
	
	// Shuffle them to randomize the colors.
	std::random_shuffle(vector_to_shuffle.begin(), vector_to_shuffle.end());
	
}

} // namespace 'utility'
} // namespace 'carcassonne' 

#endif /*CARCASSONNE_VECTOR_UTILITY_H_*/
