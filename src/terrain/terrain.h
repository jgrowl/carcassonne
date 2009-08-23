#ifndef CARCASSONNE_TERRAIN_H_
#define CARCASSONNE_TERRAIN_H_

namespace carcassonne
{
	
class Terrain
{
 public:
	Terrain();
	
	virtual Terrain* GetNewTerrain() = 0;
	//virtual TerrainSideDecorator Decorate() = 0
	
	virtual ~Terrain();
};

}

#endif /*CARCASSONNE_TERRAIN_H_*/
