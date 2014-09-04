#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include "DemoConstants.h"
#include "CustomSprite.h"

#include <map>
#include <list>
#include <algorithm> // for STL find()

using std::list;
using std::map;

// See MapManager.cpp for instructions on each member function below.

class MapManager {
public:

	MapManager();

	void clearBucketLists();

	void registerSprite( CustomSprite & sprite );


	list<CustomSprite *> getNearbySprites( CustomSprite & sprite );

private:
	map< int, list< CustomSprite *> > m_buckets;

	list<int> getBucketId( CustomSprite const & sprite );	

	void addSpriteToBucket( sf::Vector2f spriteCorner, list<int> & bucketsSpriteIsIn );

};

#endif