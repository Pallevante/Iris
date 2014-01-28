#pragma once
#include "ResourceManager.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include "Animation.h"


class World{
public:
	/*Anv�nds f�r att veta vad man ska rendera.*/
	enum GameState{
		INMENU,
		PLAYING,
		INSHOP,
		OUTRO,
		INTRO
	};	
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
	void renderImages();
	void tick();
	bool isColliding(Entity *entity1, Entity *entity2);
	void detectCollisions();
	void killDeadEntities();

	/*Menyrelaterade funktioner*/
	void enterStore();
	void enterSettings();
	void enterMap();
	

	/*Variabler*/
	typedef std::vector<Entity*> EntityVector;
	int mGold;
	Entity::EntityVector entityVector;
};

