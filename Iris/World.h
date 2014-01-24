#pragma once
class World
{
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
	int mGold;
};

