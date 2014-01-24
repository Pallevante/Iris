#include "World.h"
#include <SFML/Graphics.hpp>

World::World(){}


World::~World(){}


void World::run(){
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Iris");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}