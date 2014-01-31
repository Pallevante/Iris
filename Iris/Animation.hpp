#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <string>
#include "ResourceManager.hpp"

class Animation{
public:
	/* Konstrukturn tar ett filnamn, antal millisekunder varje frame ska visas och antal frames. */
	Animation(const std::string& filename, int timePerFrame, int numFrames);
	~Animation();

	/* Måste köras varje frame av programmet för att animationen ska utföras. */
	void Update();

	/* Setters */

	/* Stödfunktion för att sätta positionen på medlemsspriten i en Animation. */
	void setPosition(const sf::Vector2f& position);

	/* Getters */
	const sf::Sprite getSprite();
private:
	/* Medlemsvariablar */
	sf::Clock mFrameTimer;
	sf::Sprite mSprite;
	int mTimePerFrame = 0;
	int mNumFrames = 0;
	int mCurrentFrame = 0;
};