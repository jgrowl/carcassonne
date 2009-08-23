#ifndef CARCASSONNE_SIDE_CONNECTION_INTERFACE_H_
#define CARCASSONNE_SIDE_CONNECTION_INTERFACE_H_

namespace carcassonne
{

class SideConnectionInterface 
{
 public:
	virtual void ConnectedToTop() = 0;
	virtual void ConnectedToRight() = 0;
	virtual void ConnectedToBottom() = 0;
	virtual void ConnectedToLeft() = 0;
	virtual void ConnectedToMiddle() = 0;

  virtual bool IsConnectedToTop() = 0;
  virtual bool IsConnectedToRight() = 0;
  virtual bool IsConnectedToBottom() = 0;
  virtual bool IsConnectedToLeft() = 0;
  virtual bool IsConnectedToMiddle() = 0;
  
};

}

#endif /*CARCASSONNE_SIDE_CONNECTION_INTERFACE_H_*/
