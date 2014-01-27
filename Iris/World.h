#pragma once
#include "Entity.hpp"
#include "Player.hpp"
#include <SFML/Graphics.hpp>


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
	/*M�ste ladda in banan innan*/
	void startGame();
	/*Sl�nga in r�tt parametrar f�r att loadMap ska ladda in
	music, bilder och fiender*/
	void loadMap();
private:	
	/*Spelrelaterade funktioner*/
	void renderImages();
	void tick();
	void detectCollisions();
	void killDeadEnteties();

	/*Menyrelaterade funktioner*/
	void enterStore();
	void enterSettings();
	void enterMap();
	
	/*Variabler*/
	int mGold;
	Entity::EntityVector entityVector;
	Player *mPlayer;
};

