#ifndef CARCASSONNE_PTR_CONTAINER_UTILITY_H_
#define CARCASSONNE_PTR_CONTAINER_UTILITY_H_

#include <algorithm> // For random_shuffle()
#include <ctime>		 // To seed system clock for use in random_shuffle()
#include <vector>

#include <boost/ptr_container/ptr_vector.hpp>

#include "tile.h"

namespace carcassonne
{
namespace utility
{
	
template <typename T>
void shuffle(boost::ptr_vector<T>* vector_to_shuffle)
{
	// Seed the system clock to give a random shuffle
	std::srand(std::time(NULL));
	
	// Shuffle them to randomize the colors.
	std::random_shuffle(vector_to_shuffle->begin().base(),
											vector_to_shuffle->end().base());

}

// Convert boost::ptr_container to std::vector
template <typename T>
std::vector<T*> ptr_vector_to_std_vector(boost::ptr_vector<T>& 
																		    										vector_to_convert)
{
	std::vector<T*> converted_vector;
	
	for(typename boost::ptr_vector<T>::iterator i = vector_to_convert.begin(), 
																		          e = vector_to_convert.end(); 
			i != e; ++i) {
		converted_vector.push_back(&(*i));
		
	}
	
	return converted_vector;
	
}

} // namespace 'utility'
} // namespace 'carcassonne'

#endif /*CARCASSONNE_PTR_CONTAINER_UTILITY_H_*/
