#pragma once
#include "ResourceManager.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "DefaultEnemy.hpp"
#include "LoadLevel.hpp"

class Level;

class World{
public:
	/*Anv�nds f�r att veta vad man ska rendera.*/	
	enum GameState{
		INMENU,
		PLAYING,
		PAUSED,
		INSHOP,
		OUTRO,
		INTRO
	};

	GameState currentState;
	//sf::Event event;

	World();
	~World();
	void run();
	void menu();
	void loadAllTheShit();
	/*M�ste ladda in banan innan*/
	void startGame();
	/*Sl�nga in r�tt parametrar f�r att loadMap ska ladda in
	music, bilder och fiender*/
	void loadMap();
private:	
	/*Spelrelaterade funktioner*/
	void spawnEnemies();
	void renderImages();
	void tick();
	bool isColliding(Entity *entity1, Entity *entity2);
	void detectCollisions();
	void killDeadEntities();

	/*Menyrelaterade funktioner*/
	void pause();
	void enterStore();
	void enterSettings();
	void enterMap();
	
	

	/*Variabler*/
	typedef std::vector<Entity*> EntityVector;
	int mGold;
	Entity::EntityVector entityVector;

	Level* mLevel;
};

