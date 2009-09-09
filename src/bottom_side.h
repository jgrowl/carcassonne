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
 	BottomSide(const BottomSide&);
 	BottomSide& operator=(const BottomSide&);
 	
 	virtual void CopyFrom(const BottomSide&);
 	virtual Side* Clone() const;
 	
 	BottomSide(TerrainSegment& middle, SideConnections& connections);

	virtual void ConnectedToTop();
	virtual void ConnectedToRight();
	virtual void ConnectedToBottom();
	virtual void ConnectedToLeft();

  virtual bool IsConnectedToTop();
  virtual bool IsConnectedToRight();
  virtual bool IsConnectedToBottom();
  virtual bool IsConnectedToLeft();
	
  virtual std::string ToString() const;
  
	virtual ~BottomSide();
};

}

#endif /*CARCASSONNE_BOTTOM_SIDE_H_*/
