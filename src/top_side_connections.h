#ifndef CARCASSONNE_TOP_SIDE_CONNECTIONS_H_
#define CARCASSONNE_TOP_SIDE_CONNECTIONS_H_

#include <string>
#include <vector>

#include "side_connections.h"

namespace carcassonne
{

class TopSideConnections : public SideConnections
{
 public:
 	TopSideConnections();
 	
  TopSideConnections(bool clockwise,
                     bool across,
                     bool counter_clockwise,
                     bool middle);

	virtual SideConnections* Copy() const;   

  virtual std::vector<std::string> ToStringVector() const;

  virtual ~TopSideConnections();

};

}

#endif /*CARCASSONNE_TOP_SIDE_CONNECTIONS_H_*/
