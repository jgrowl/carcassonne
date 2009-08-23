#ifndef CARCASSONNE_RIGHT_SIDE_H_
#define CARCASSONNE_RIGHT_SIDE_H_

#include "side.h"

namespace carcassonne
{

class RightSide : public Side
{
 public:
 	RightSide();
//  RightSide(Terrain* terrain, SideConnections* connections);
//  RightSide(Terrain& terrain);

	virtual void ConnectedToTop();
	virtual void ConnectedToRight();
	virtual void ConnectedToBottom();
	virtual void ConnectedToLeft();

  virtual bool IsConnectedToTop();
  virtual bool IsConnectedToRight();
  virtual bool IsConnectedToBottom();
  virtual bool IsConnectedToLeft();

  virtual std::string ToString();

  virtual ~RightSide();

};

}

#endif /*CARCASSONNE_RIGHT_SIDE_H_*/
