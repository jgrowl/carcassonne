#ifndef CARCASSONNE_SIDE_CONNECTIONS_H_
#define CARCASSONNE_SIDE_CONNECTIONS_H_

#include <string>
#include <vector>

namespace carcassonne
{

class SideConnections
{
 public:
 	/** 
 	 * Default constructor sets all connections to false initially.
 	 */
 	SideConnections();
  SideConnections(bool clockwise,
                  bool across,
                  bool counterclockwise,
                  bool middle);

	virtual SideConnections* Copy() = 0;               

  virtual bool clockwise();
  virtual bool across();
  virtual bool counterclockwise();
  virtual bool middle();
  
  virtual void set_clockwise(bool clockwise);
  virtual void set_across(bool across);
  virtual void set_counterclockwise(bool counterclockwise);
  virtual void set_middle(bool middle);

  virtual std::vector<std::string> ToStringVector();
  virtual std::string ToString();
  
  virtual ~SideConnections();

 protected:
  bool clockwise_;
  bool across_;
  bool counterclockwise_;

  bool middle_;
};

}

#endif /*CARCASSONNE_SIDE_CONNECTIONS_H_*/
