#ifndef CARCASSONNE_SIDE_DECORATOR_H_
#define CARCASSONNE_SIDE_DECORATOR_H_

#include <string>

#include "side.h"

namespace carcassonne
{
	
class SideDecorator : public Side
{
 public:
 	SideDecorator();
	SideDecorator(Side*);
	
	/**
   * Sets the connection to true
   */
	virtual void ConnectedToTop();
	virtual void ConnectedToRight();
	virtual void ConnectedToBottom();
	virtual void ConnectedToLeft();

  /**
   * returns true if the side is connected
   */
  virtual bool IsConnectedToTop();
  virtual bool IsConnectedToRight();
  virtual bool IsConnectedToBottom();
  virtual bool IsConnectedToLeft();
  
  virtual std::string ToString() const;
	
	virtual ~SideDecorator();
 
 protected:
 	Side* side_;

};

}

#endif /*CARCASSONNE_SIDE_DECORATOR_H_*/
