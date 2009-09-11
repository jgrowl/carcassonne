/**
 * 
 * http://www.parashift.com/c++-faq-lite/misc-technical-issues.html#faq-39.1
 */
#ifndef CARCASSONNE_CONVERT_H_
#define CARCASSONNE_CONVERT_H_

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
 
class BadConversion : public std::runtime_error 
{
 public:
  BadConversion(const std::string& s) : std::runtime_error(s) { }

};
 
inline std::string stringify(int x)
{
	std::ostringstream o;
  if (!(o << x))
		throw BadConversion("stringify(int)");

   return o.str();
} 
 
#endif /*CARCASSONNE_CONVERT_H_*/
