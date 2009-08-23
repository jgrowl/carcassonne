#include <string>
#include <vector>

#include <boost/foreach.hpp>

namespace carcassonne
{
	
std::string commaize(std::vector<std::string> vector_to_process)
{
  if(vector_to_process.empty()) {
    return "";
  }

  else if(vector_to_process.size() == 1) {
    return vector_to_process[0];
  }

  std::string commaized_string("");

  BOOST_FOREACH(std::string str, vector_to_process) {
    commaized_string += str + ", ";
  }

  // Remove the trailing comma and space
  commaized_string.erase(commaized_string.length() - 2, 2);

  return commaized_string;
}

}