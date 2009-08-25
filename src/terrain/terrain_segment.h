#ifndef CARCASSONNE_TERRAIN_SEGMENT_H_
#define CARCASSONNE_TERRAIN_SEGMENT_H_

namespace carcassonne
{

class TerrainSegment
{
public:
	TerrainSegment();
	
	virtual TerrainSegment* Copy() = 0;
	
	virtual ~TerrainSegment();
};

}

#endif /*CARCASSONNE_TERRAIN_SEGMENT_H_*/
