#ifndef CARCASSONNE_BOTTOM_SIDE_H_
#define CARCASSONNE_BOTTOM_SIDE_H_

#include "side.h"

namespace carcassonne
{

class BottomSide : public Side
{
 public:
 	BottomSide();
// 	BottomSide(Terrain& terrain);
//  BottomSide(Terrain* terrain, SideConnections* connections);

	virtual void ConnectedToTop();
	virtual void ConnectedToRight();
	virtual void ConnectedToBottom();
	virtual void ConnectedToLeft();

  virtual bool IsConnectedToTop();
  virtual bool IsConnectedToRight();
  virtual bool IsConnectedToBottom();
  virtual bool IsConnectedToLeft();
	
  virtual std::string ToString();
  
	virtual ~BottomSide();
};

}

#endif /*CARCASSONNE_BOTTOM_SIDE_H_*/
