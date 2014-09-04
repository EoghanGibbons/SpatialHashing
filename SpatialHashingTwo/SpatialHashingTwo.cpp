#include "stdafx.h"
//#include <SFML/System.hpp>
//#include <SFML/Graphics.hpp>

#include "MapManager.h"
#include "SpriteManager.h"
#include <iostream>
using namespace std;

// Sample program to demonstrate basic usage of SFML library. Can also be used as a starting
//  point for the spatial hashing assignment.
int main() {
	sf::RenderWindow window(sf::VideoMode(DemoConstants::SCREEN_WIDTH, DemoConstants::SCREEN_HEIGHT), "SFML Window");

	// Define set of lines to draw grid
	sf::VertexArray lines(sf::Lines, 16); {
		//Horizontal lines
		lines[0].position = sf::Vector2f(0, 0);
        lines[1].position = sf::Vector2f(800, 0);

        lines[2].position = sf::Vector2f(0, 200);
        lines[3].position = sf::Vector2f(800, 200);

		lines[4].position = sf::Vector2f(0, 400);
        lines[5].position = sf::Vector2f(800, 400);

        lines[6].position = sf::Vector2f(0, 600);
        lines[7].position = sf::Vector2f(800, 600);


		//Vertical lines
		lines[8].position = sf::Vector2f(0, 0);
        lines[9].position = sf::Vector2f(0, 800);

        lines[10].position = sf::Vector2f(200, 0);
        lines[11].position = sf::Vector2f(200, 800);

		lines[12].position = sf::Vector2f(400, 0);
        lines[13].position = sf::Vector2f(400, 800);

        lines[14].position = sf::Vector2f(600, 0);
        lines[15].position = sf::Vector2f(600, 800);
	};
	
	
	// How to load an image
	sf::Image image;
    

	// How to create a sprite from that image.
	CustomSprite::init("chromatic_circle.png");

	// Make an instance of our sprite manager.
	SpriteManager spriteManager;

	vector<CustomSprite> & allSprites = spriteManager.getAllSprites();

    // Start game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
	
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

		
        // Clear the screen (fill it with black color)
		window.clear(sf::Color::Black);
		
		
		// How to draw a line.		
	    window.draw(lines);	
			
		// How to draw a container of sprites.
		for ( int i = 0; i < allSprites.size(); ++i ) {							
			window.draw( allSprites.at(i) );						
		}
		spriteManager.keepInBounds();
		
        // Display window contents on screen
        window.display();
    }
	

    return EXIT_SUCCESS;
}