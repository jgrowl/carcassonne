#ifndef CARCASSONNE_LEFT_SIDE_H_
#define CARCASSONNE_LEFT_SIDE_H_

#include "side.h"

namespace carcassonne
{

class LeftSide : public Side
{
 public:
 	LeftSide();
 	LeftSide(TerrainSegment& middle, SideConnections& connections);
// 	LeftSide(Terrain& terrain);
//  LeftSide(Terrain* terrain, SideConnections* connections);
	
	virtual void ConnectedToTop();
	virtual void ConnectedToRight();
	virtual void ConnectedToBottom();
	virtual void ConnectedToLeft();

  virtual bool IsConnectedToTop();
  virtual bool IsConnectedToRight();
  virtual bool IsConnectedToBottom();
  virtual bool IsConnectedToLeft();

	virtual Side* Copy();

  virtual std::string ToString();
  
	virtual ~LeftSide();
};

}

#endif /*CARCASSONNE_LEFT_SIDE_H_*/
