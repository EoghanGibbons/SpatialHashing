#include "stdafx.h"
#include "MapManager.h"

// Constructor method for the MapManager (see step 2 in the assignment)
MapManager::MapManager() {
	for (int i = 0; i < 16; i++)
	{
		m_buckets[i] = std::list<CustomSprite *>();
	}
}

// Clear each entry in the map (step 3 in the assignment)
void MapManager::clearBucketLists() {	
	for (int i = 0; i < 16; i++)
	{
		m_buckets[i].clear();
	}
}

// Register the given sprite in the map (step 5 in the assignment)
void MapManager::registerSprite( CustomSprite & sprite ) {
	list<int> cellIds = getBucketId( sprite );
	list<int>::iterator iter = cellIds.begin();
	
	while(iter != cellIds.end()) 
	{
		m_buckets[*iter].push_back(&sprite);
		++iter;
	}
}
	
// For each sprite corner, call the AddSpriteToBucket member function below. 
// See step 4 in the assignment for further details.
list<int> MapManager::getBucketId(CustomSprite const & sprite) {
	// A list of bucket id's that the given sprite is in.
	list<int> bucketsSpriteIsIn;

	addSpriteToBucket(sprite.centre + sprite.pointOne, bucketsSpriteIsIn);
	addSpriteToBucket(sprite.centre + sprite.pointTwo, bucketsSpriteIsIn);
	addSpriteToBucket(sprite.centre + sprite.pointThree, bucketsSpriteIsIn);
	addSpriteToBucket(sprite.centre + sprite.pointFour, bucketsSpriteIsIn);

	bucketsSpriteIsIn.sort(); // Puts bucket ID's in order
	bucketsSpriteIsIn.unique(); //removes duplicates

	return bucketsSpriteIsIn;
}

// For the given sprite corner, work out which bucket the sprite should be added to, then
//  add it's bucketid to the list.
void MapManager::addSpriteToBucket( sf::Vector2f spriteCorner, list<int> & bucketsSpriteIsIn ) {
	int cellPosition = floor( spriteCorner.x / DemoConstants::CELLSIZE ) + ( (floor(  spriteCorner.y / DemoConstants::CELLSIZE )) * DemoConstants::COLUMNS );
	bucketsSpriteIsIn.push_back(cellPosition);
}

// Returns a list of nearby sprites for the given sprite (step 6 in the assignment).
list<CustomSprite *> MapManager::getNearbySprites( CustomSprite & sprite ) {
	// The list of nearby sprites to return.
	list<CustomSprite *> nearbySprites;

	list<int> cellIds = getBucketId(sprite);
	list<int>::iterator iter = cellIds.begin();
 
	while(iter != cellIds.end()) 
	{
		nearbySprites.merge(m_buckets[*iter]);
		++iter;
	}
	
	return nearbySprites;
}
