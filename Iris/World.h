#pragma once
#include "Entity.hpp"
#include "Player.hpp"
#include <SFML/Graphics.hpp>


class World{
public:
	World();
	~World();
	void run();
	void menu();
	//Have to load the map first
	void startGame();
	//Have to enter the parameters for images, enemies and music. 
	void loadMap();
private:	
	//Game related functions
	void renderImages();
	void tick();
	void detectCollisions();
	void killDeadEnteties();

	//Menu related functions
	void enterStore();
	void enterSettings();
	void enterMap();
	
	//Variables.
	int mGold;
	Entity::EntityVector entityVector;
	Player *mPlayer;
};

