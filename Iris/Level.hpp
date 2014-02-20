#pragma once
#include <SFML\Graphics.hpp>
#include "World.hpp"
#include "Enemy.hpp"
#include "Gold.hpp"
#include "ResourceManager.hpp"

class Level {
public:

	// Level(float spawnMini, float spawnMax, float requirement, float specialMin,
	// float specialMax, float obstMin, float obstMax, sf::Texture &texture);
	Level();
	~Level();
	/*Spawn:ar default enemies*/
	void spawnBasicEnemies(Entity::EntityVector &entityVector);
	/*Spawn:ar Skjutare*/
	void spawnSpecialEnemies(Entity::EntityVector &entityVector);
	
	/*Spawn:ar Guld*/
	void spawnGold(Entity::EntityVector &entityVector);
	void set(float spawnMini, float spawnMax, float requirment, 
		float obstSpawnMin,	float obstMax, float specialMin, 
		float specialMax, int maxSpecialSpawn, int maxSpawnEnemies, 
		int level, int levelTime);

	void spawn(Entity::EntityVector &entityVector);
	int getRandomNumber();
	float percentRequirement(float requirement);
	void drawBackground(sf::RenderWindow &window);
	std::string getTheme(int level);
	sf::Sprite getBackground();
private:
	float mSpawnMin;
	float mSpawnMax;
	float mSpecialMin;
	float mSpecialMax;
	float mObstSpawnMin;
	float mObstMax;
	float mRequirment;
	// float mSpawn;
	float mRandomSpawn;
	/*maxx antal enemies som spawnas*/
	int mMaxSpawnEnemies;
	int mMaxSpecialSpawn;
	int mLevelTime;
	void drawLevel(sf::RenderWindow& window, ResourceManager::SpriteVector& bgVector, float speed, sf::Color& color);
	void moveLevel(sf::RenderWindow& window, ResourceManager::SpriteVector& bgVector, float speed, sf::Color& color);


	std::string chooseWhiteTexture;
	std::string chooseColoredTexture;

	sf::Clock mDefaultCl;
	sf::Clock mSpecialCl;

	sf::Sprite mSpriteWhite;
	sf::Sprite mSpriteColor;
	//sf::Texture mTexture;
	sf::FloatRect mBackgroundRect;
};