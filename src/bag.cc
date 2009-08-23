#include "bag.h"

namespace carcassonne
{

Bag::Bag()
{
	valid_tiles_.reset(new ValidTiles);
	
}

Bag::~Bag()
{
}

}
