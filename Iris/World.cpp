#include "World.hpp"

sf::RenderWindow window(sf::VideoMode(1280, 720), "Iris");
sf::Clock spawnTimer;
int spawnTimeLimit =  500;

World::World(): 

entityVector()
{
	currentState = PLAYING;
	Animation* playerAnimation = new Animation("resource/test.png", 200, 4);
	Player *mPlayer;
	window.setFramerateLimit(65);
	mPlayer = new Player(playerAnimation, 100, 100);
	entityVector.push_back(mPlayer);
}

World::~World(){}

void World::run(){

		while (window.isOpen())	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		/*Använder en instans av GameState för att veta vad den skall göra.
		  Göra så att när man klickar play så går den in i ett state som laddar sedan ändrar load till PLAYING?*/
		if (currentState == PLAYING){
			startGame();
		}
		window.display();
	}
}
void World::startGame(){
	tick();
	detectCollisions();
	killDeadEntities();
	spawnEnemies();
	renderImages();
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

		for (unsigned int j = i + 1; j < entityVector.size(); j++){
			Entity *entity1 = entityVector[j];

			if (isColliding(entity0, entity1) && entity0->getType() != entity1->getType()){
				entity0->collide(entity1, entityVector);
				entity1->collide(entity0, entityVector);
			}
		}
	}
}
/*Skapar en ny vektor som sedan lägger in alla levande entiteter.
Den nya vektorn uppdaterar våran "main" vektor sedan.*/
void World::killDeadEntities(){
	EntityVector reserveEnteties;
	for (EntityVector::iterator i = entityVector.begin(); i != entityVector.end(); i++){
		Entity* enteties = *i;
		if (enteties->isAlive()){
			reserveEnteties.push_back(enteties);
		}
	}
	entityVector = reserveEnteties;
}

/*Denna tiomern får vi hämta ifrån levelload sedan då det kommmer olika många fiender på olika banor.*/
void World::spawnEnemies(){
	sf::Time time = spawnTimer.getElapsedTime();
	if(time.asMilliseconds() > 600){
		Animation* enemyAnimation = new Animation("resource/test.png", 50, 4);
		entityVector.push_back(new DefaultEnemy(enemyAnimation, 1));
		spawnTimer.restart();
	}
}



/*
				__	- FML.
			   / _)
	  _/\/\/\_/ /
	 /			|
	/ (	 |	 (	|
   /   |_|--- |_|

 */
