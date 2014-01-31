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
	void moveBackground();
	//float enemySpawnTimeMin(float spawnMini);
	//float enemySpawnTimeMax(float spawnMax);
	float percentRequirement(float requirement);
	//float specialEnemySpawnTimeMin(float specialMin);
	//float specialEnemySpawnTimeMax(float specialMax);
	/*obst är en förkortning för obstacle*/
	float obstacleSpawnTimeMin(float obstSpawn);
	float obstacleSpawnTimeMax(float obstMax);

	int getRandomNumber();

	void setBackground(sf::Texture &texture);
	//sf::Sprite getBackground();
	
private:
	sf::Texture mTexture;
	sf::Sprite mSprite;
	float mSpawnMini;
	float mSpawnMax;
	float mRequirment;
	float mSpecialMin;
	float mSpecialMax;
	float mObstSpawnMin;
	float mObstMax;
//	float mSpawn;
	float mRandomSpawn;
	/*maxx antal enemies som spawnas*/
	int mMaxSpawnEnemies;
	int mMaxSpecialSpawn;

	Animation* enemyAnimation;
	Entity::EntityVector mEntityVector;
	sf::Clock mDefaultCl;
	sf::Clock mSpecialCl;

};