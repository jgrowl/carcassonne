#ifndef CARCASSONNE_SIDE_H_
#define CARCASSONNE_SIDE_H_

#include <boost/scoped_ptr.hpp>

#include "terrain/terrain.h"
#include "terrain/terrain_segment.h"
#include "side_connections.h"
#include "side_connection_interface.h"

namespace carcassonne
{
	
class Side : public SideConnectionInterface
{
 public:
  Side();
// 	Side(Terrain& terrain);
//  Side(Terrain* terrain, SideConnections* connections);

//	virtual Terrain* terrain();

  virtual SideConnections* connections();
  
  virtual void set_connections(SideConnections& connections);

	virtual void ConnectedToMiddle();
	virtual bool IsConnectedToMiddle();
	
	virtual Side* Copy() = 0;
  virtual std::string ToString();

	virtual ~Side();

 protected:
  /**
   * terrain_ is the main terrain associated with the side. It will be the
   * terrain that the middle_ belongs to in all cases since middle_ uniquely
   * defines what kind of terrain the side will need to initialize.
   */
//  boost::scoped_ptr<Terrain> terrain_;

  boost::scoped_ptr<TerrainSegment> middle_;

  boost::scoped_ptr<SideConnections> connections_;
  
};

}

#endif /*CARCASSONNE_SIDE_H_*/
