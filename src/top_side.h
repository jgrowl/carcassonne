#ifndef CARCASSONNE_TOP_SIDE_H_
#define CARCASSONNE_TOP_SIDE_H_

#include <string>

#include "side.h"

namespace carcassonne
{

class TopSide : public Side
{
 public:
 	TopSide();
 	TopSide(TerrainSegment& middle, SideConnections& connections);
//	TopSide(Terrain& terrain);
//  TopSide(Terrain* terrain, SideConnections* connections);

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

	virtual Side* Copy();
  virtual std::string ToString();

  virtual ~TopSide();

};

}

#endif /*CARCASSONNE_TOP_SIDE_H_*/
