#include "stdafx.h"
#include "SpriteManager.h"

// Adds DemoConstants::NUM_SPRITES to a container, each sprite has a random screen position
//  and direction vector.
SpriteManager::SpriteManager() {

	for (int i = 0 ; i < DemoConstants::NUM_SPRITES; ++i) {
		CustomSprite sprite;

		sprite.setScale( sf::Vector2f(0.5f, 0.5f) );
		sprite.setPosition( rand() % static_cast<int> ( ( DemoConstants::SCREEN_WIDTH - sprite.getGlobalBounds().width ) ), 
			rand() % static_cast<int> ( ( DemoConstants::SCREEN_HEIGHT - sprite.getGlobalBounds().height ) ) );	   	
		// Give each sprite a random direction vector.
		float randXDir = ( rand() % 10 ) / 10.0f;
		float randYDir = ( rand() % 10 ) / 10.0f;
		sprite.setDirection( sf::Vector2f( randXDir, randYDir ) );
		m_sprites.push_back( sprite );
	}	
}

vector<CustomSprite> & SpriteManager::getAllSprites() {
	return m_sprites;
}

// Iterate through the sprite container, and make sure each sprite stays within the
//  dimensions of the display (i.e. from 0,0 to DemoConstants::SCREEN_WIDTH, DemoConstants::SCREEN_HEIGHT)
void SpriteManager::keepInBounds() {	
		
}