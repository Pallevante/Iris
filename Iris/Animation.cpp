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

/* M�ste k�ras varje frame av programmet f�r att animationen ska utf�ras. */
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

/* F�r att s�tta positionen p� en Animation. */
void Animation::setPosition(const sf::Vector2f& position){
	mSprite.setPosition(position);
}

/* Getters */
const sf::Sprite& Animation::getSprite(){
	return mSprite;
}