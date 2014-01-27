#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <string>

class Animation{
public:
	Animation(const std::string& filename, int timePerFrame, int numFrames);
	~Animation();

	void Update();

	/* Setters */
	void setPosition(const sf::Vector2f& position);

	/* Getters */
	const sf::Sprite getSprite();
private:
	/* Medlemsvariablar */
	sf::Clock mFrameTimer;
	sf::Texture mTexture;
	sf::Sprite mSprite;
	int mTimePerFrame = 0;
	int mNumFrames = 0;
	int mCurrentFrame = 0;
};