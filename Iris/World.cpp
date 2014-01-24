#include "World.h"
#include <SFML/Graphics.hpp>

World::World(){}

<<<<<<< HEAD
=======
World::World(){
}
>>>>>>> a6d5e89d94d9433ce489f2064f8b8ce0c9bb1d55

World::~World(){}

<<<<<<< HEAD

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
=======
World::~World(){
}
>>>>>>> a6d5e89d94d9433ce489f2064f8b8ce0c9bb1d55
