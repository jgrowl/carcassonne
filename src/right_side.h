#ifndef CARCASSONNE_RIGHT_SIDE_H_
#define CARCASSONNE_RIGHT_SIDE_H_

#include "side.h"

namespace carcassonne
{

class RightSide : public Side
{
 public:
 	RightSide();
 	RightSide(const RightSide&);
 	RightSide& operator=(const RightSide&);
 	
 	virtual void CopyFrom(const RightSide&);
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

  virtual ~RightSide();

};

}

#endif /*CARCASSONNE_RIGHT_SIDE_H_*/
