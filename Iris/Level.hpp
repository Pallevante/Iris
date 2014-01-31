#pragma once
#include <SFML\Graphics.hpp>
#include "World.hpp"
#include "Enemies.hpp"

class Level {
public:
	// Level(float spawnMini, float spawnMax, float requirement, float specialMin,
	// float specialMax, float obstMin, float obstMax, sf::Texture &texture);
	Level();
	~Level();
	/*Spawn:ar enemies*/
	void spawnBasicEnemies(Entity::EntityVector &mEntities);
	void set(float spawnMini, float spawnMax, float requirment, float obstSpawnMin,
	float obstMax, int MaxSpawnEnemies);
	float percentRequirement(float requirement);

	/*obst är en förkortning för obstacle*/
	float obstacleSpawnTimeMin(float obstSpawn);
	float obstacleSpawnTimeMax(float obstMax);

	int getRandomNumber();

	void setBackground(sf::Texture &texture);
	sf::Sprite getBackground();
private:
	sf::Texture mTexture;
	sf::Sprite mSprite;
	float mSpawnMini;
	float mSpawnMax;
	float mRequirment;
	// float mSpecialMin;
	// float mSpecialMax;
	float mObstSpawnMin;
	float mObstMax;
	float mSpawn;
	float mRandomSpawn;
	/*maxx antal enemies som spawnas*/
	int mMaxSpawnEnemies;
	//Animation *animation;
	sf::Clock mDefaultCl;

};