#pragma once
#include <SFML\Graphics.hpp>
#include "World.hpp"
#include "Enemies.hpp"

class Level {
public:

//	Level(float spawnMini, float spawnMax, float requirement, float specialMin,
//		float specialMax, float obstMin, float obstMax, sf::Texture &texture);
	Level();
	~Level();
	/*Spawn:ar default enemies*/
	void spawnBasicEnemies(Entity::EntityVector &entityVector);
	/*Spawn:ar Skjutare*/
	void spawnSpecialEnemies(Entity::EntityVector &entityVector);
	void set(float spawnMini, float spawnMax, float requirment, float obstSpawnMin, 
		float obstMax, int maxSpawnEnemies, float specialMin, 
		float specialMax, int maxSpecialSpawn);
	void drawBackground(sf::RenderWindow *window);
	int getRandomNumber();
	float percentRequirement(float requirement);
	void setBackground(sf::Texture &texture);
	void moveBackground();

	sf::Sprite getBackground();
	private:
	float mSpawnMin;
	float mSpawnMax;
	float mSpecialMin;
	float mSpecialMax;
	float mObstSpawnMin;
	float mObstMax;
	float mRequirment;
//	float mSpawn;
	float mRandomSpawn;
	/*maxx antal enemies som spawnas*/
	int mMaxSpawnEnemies;
	int mMaxSpecialSpawn;

	Animation* enemyAnimation;
	Entity::EntityVector mEntityVector;

	sf::Clock mDefaultCl;
	sf::Clock mSpecialCl;

	sf::Sprite mSprite;
	sf::Texture mTexture;
};