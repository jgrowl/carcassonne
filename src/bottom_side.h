#ifndef CARCASSONNE_BOTTOM_SIDE_H_
#define CARCASSONNE_BOTTOM_SIDE_H_

#include <string>

#include "side.h"

namespace carcassonne
{

class BottomSide : public Side
{
 public:
 	BottomSide();
 	BottomSide(TerrainSegment& middle, SideConnections& connections);
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
	
	virtual Side* Copy() const;
	
  virtual std::string ToString() const;
  
	virtual ~BottomSide();
};

}

#endif /*CARCASSONNE_BOTTOM_SIDE_H_*/
