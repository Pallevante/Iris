#include "Animation.h"

/* Konstrukturn tar ett filnamn, antal millisekunder varje frame ska visas och antal frames. */
Animation::Animation(const std::string& filename, int timePerFrame, int numFrames) :
mTimePerFrame(timePerFrame),
mNumFrames(numFrames),
mCurrentFrame(0){
	mTexture.loadFromFile(filename);
	mSprite.setTexture(mTexture);
	
	sf::IntRect textureRect(0, 0, mTexture.getSize().x / mNumFrames, mTexture.getSize().y);
	mSprite.setTextureRect(textureRect);
};

Animation::~Animation(){

};

/* Måste köras varje frame av programmet för att animationen ska utföras. */
void Animation::Update(){
	if (mFrameTimer.getElapsedTime().asMilliseconds() > mTimePerFrame){
		mFrameTimer.restart();

		++mCurrentFrame; 
		if (mCurrentFrame >= mNumFrames){
			mCurrentFrame = 0;
		}
		sf::IntRect currentRect = mSprite.getTextureRect();
		currentRect.left = currentRect.width * mCurrentFrame;

		mSprite.setTextureRect(currentRect);
	}
}

/* För att sätta positionen på en Animation. */
void Animation::setPosition(const sf::Vector2f& position){
	mSprite.setPosition(position);
}

/* Getters */
const sf::Sprite& Animation::getSprite(){
	return mSprite;
}