#include "Animation.hpp"


Animation::Animation(const std::string& filename, int timePerFrame, int numFrames) :
mTimePerFrame(timePerFrame),
mNumFrames(numFrames),
mCurrentFrame(0){
	/* Anv�nder texturen som en sprite */
	mSprite.setTexture(ResourceManager::getTexture(filename));

	/* Visar den f�rsta framen av spritesheetet */
	sf::IntRect textureRect(0, 0, ResourceManager::getTexture(filename).getSize().x / mNumFrames, ResourceManager::getTexture(filename).getSize().y);
	mSprite.setTextureRect(textureRect);
};

Animation::~Animation(){
};


void Animation::Update(){
	/* Kollar om timern f�r framen har g�tt ut */
	if (mFrameTimer.getElapsedTime().asMilliseconds() > mTimePerFrame){
		/* Startar om timern inf�r n�sta frame */
		mFrameTimer.restart();

		++mCurrentFrame;
		if (mCurrentFrame >= mNumFrames){
			mCurrentFrame = 0;
		}
		/* Sj�lva magin: �ndrar texturrektangeln till den nya positionen p� spritesheetet */
		sf::IntRect currentRect = mSprite.getTextureRect();
		currentRect.left = currentRect.width * mCurrentFrame;

		mSprite.setTextureRect(currentRect);
	}
}
/* Setters */
void Animation::setPosition(const sf::Vector2f& position){
	mSprite.setPosition(position);
}

void Animation::setColor(sf::Color& color){
	mSprite.setColor(color);

}


/* Getters */
const sf::Sprite Animation::getSprite(){
	return mSprite;
}

const sf::Color Animation::getColor(){
	return mColor;
}