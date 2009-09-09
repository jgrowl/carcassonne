#ifndef CARCASSONNE_TERRAIN_SEGMENT_H_
#define CARCASSONNE_TERRAIN_SEGMENT_H_

namespace carcassonne
{

class TerrainSegment
{
public:
	TerrainSegment();
	TerrainSegment(const TerrainSegment&);
	TerrainSegment& operator=(const TerrainSegment&);
	
	void CopyFrom(const TerrainSegment&);
	virtual TerrainSegment* Clone();
	
	virtual ~TerrainSegment();
};

}

#endif /*CARCASSONNE_TERRAIN_SEGMENT_H_*/
