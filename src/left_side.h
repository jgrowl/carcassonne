#ifndef CARCASSONNE_LEFT_SIDE_H_
#define CARCASSONNE_LEFT_SIDE_H_

#include "side.h"

namespace carcassonne
{

class LeftSide : public Side
{
 public:
 	LeftSide();
 	LeftSide(const LeftSide&);
 	LeftSide& operator=(const LeftSide&);
 	
 	virtual void CopyFrom(const LeftSide&);
 	virtual Side* Clone() const;

	virtual void ConnectedToTop();
	virtual void ConnectedToRight();
	virtual void ConnectedToBottom();
	virtual void ConnectedToLeft();

  virtual bool IsConnectedToTop();
  virtual bool IsConnectedToRight();
  virtual bool IsConnectedToBottom();
  virtual bool IsConnectedToLeft();

  virtual std::string ToString() const;
  
	virtual ~LeftSide();
};

}

#endif /*CARCASSONNE_LEFT_SIDE_H_*/
