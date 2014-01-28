#include "World.hpp"

sf::RenderWindow window(sf::VideoMode(1024, 768), "Iris");

World::World(): 
entityVector(),
mPlayer(new Player(100, 100)){
	window.setFramerateLimit(65);
	entityVector.push_back(mPlayer);


}

World::~World(){}


void World::run(){
	//Skapa en textur, ladda in en fil i den, lägg till den (egentligen med enumen i entity som första parametern) i resourceManager. 
	sf::Texture textureTest;
	textureTest.loadFromFile("resource/test.png");
	resourceManager.addTexture(0, textureTest);
	//Skapa en sprite som gettar texturen med det ID som du vill ha. 
	sf::Sprite sprite = sf::Sprite(resourceManager.getTexture(0));

	LoadLevel *mLoadLevel = new LoadLevel;
	mLoadLevel->setLevel(entityVector);
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		tick();
		renderImages();
		
		//Ritar ut exempelspriten
		window.draw(sprite);
		window.display();
	}
}


void World::renderImages(){
	for (EntityVector::size_type i = 0; i < entityVector.size(); i++){
		window.draw(*entityVector[i]);
	}
}

void World::tick(){
	for (EntityVector::size_type i = 0; i < entityVector.size(); i++){
		entityVector[i]->tick(entityVector);
	}
}


/* Tar emot två Entitypekare och returnerar om de kolliderar eller inte. Används som stödfunktion till detectCollisions. */
bool World::isColliding(Entity *entity1, Entity *entity2){
	const float X0 = entity1->getPosition().x;
	const float Y0 = entity1->getPosition().y;
	const float R0 = entity1->getRad();

	const float X1 = entity2->getPosition().x;
	const float Y1 = entity2->getPosition().y;
	const float R1 = entity2->getRad();
	const float DX = X0 - X1;
	const float DY = Y0 - Y1;

	return DX * DX + DY * DY < (R0 + R1) * (R0 + R1);
}

/* Går igenom entityVector och kör isColliding på alla par av entiteter. 
Den utkommenterade biten kollar om sakerna som kolliderar har samma typ 
(hostile eller friendly t ex) och struntar isåfall i att de kolliderar. 

Typ-kollen bör ske innan kollisions-kollen för att spara på arbetskraft.*/
void World::detectCollisions(){
	for (unsigned int i = 0; i < entityVector.size(); i++){
		Entity *entity0 = entityVector[i];

		for (unsigned int j = 0; j < entityVector.size(); j++){
			Entity *entity1 = entityVector[j];

			if (isColliding(entity0, entity1)/* && entity0->getType() != entity1->getType()*/){

				entity0->collide(entity1, entityVector);
				entity1->collide(entity0, entityVector);
			}
		}
	}
}