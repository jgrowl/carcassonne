#ifndef CARCASSONNE_PTR_CONTAINER_UTILITY_H_
#define CARCASSONNE_PTR_CONTAINER_UTILITY_H_

#include <boost/ptr_container/ptr_vector.hpp>

#include "tile.h"

namespace carcassonne
{
// Make this more generic & use templates
void random_shuffle(boost::ptr_vector<Tile>*);



}

#endif /*CARCASSONNE_PTR_CONTAINER_UTILITY_H_*/
