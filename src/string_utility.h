#ifndef CARCASSONNE_STRING_UTILITY_H_
#define CARCASSONNE_STRING_UTILITY_H_

#include <string>
#include <vector>

namespace carcassonne
{
	
/**
  * Takes a vector of strings and returns a string with each element of the
  * vector seperated by a comma.
  *
  * @param vector_to_process A vector of strings
  * @return Returns a string
 */
std::string commaize(std::vector<std::string> vector_to_process);

}
#endif /*CARCASSONNE_STRING_UTILITY_H_*/
