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
		float obstMax, float specialMin, 
		float specialMax, int maxSpecialSpawn, int maxSpawnEnemies, int level);
	void spawn(Entity::EntityVector &entityVector);
	int getRandomNumber();
	float percentRequirement();
	void moveBackground(sf::RenderWindow *window);
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
	int opacity;
	std::string chooseWhiteTexture;
	std::string chooseColoredTexture;

	sf::Clock mDefaultCl;
	sf::Clock mSpecialCl;

	sf::Sprite mSpriteWhite;
	sf::Sprite mSpriteColor;
	//sf::Texture mTexture;
	sf::FloatRect mBackgroundRect;
	Enemy *enemy;

};