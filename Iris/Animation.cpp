#include "Animation.h"

/* Konstrukturn tar ett filnamn, antal millisekunder varje frame ska visas och antal frames. */
Animation::Animation(const std::string& filename, int timePerFrame, int numFrames) :
mTimePerFrame(timePerFrame),
mNumFrames(numFrames),
mCurrentFrame(0){
	/* Laddar in filen som en textur */
	mTexture.loadFromFile(filename);
	/* Använder texturen som en sprite */
	mSprite.setTexture(mTexture);
	
	/* Visar den första framen av spritesheetet */
	sf::IntRect textureRect(0, 0, mTexture.getSize().x / mNumFrames, mTexture.getSize().y);
	mSprite.setTextureRect(textureRect);
};

Animation::~Animation(){

};

/* Måste köras varje frame av programmet för att animationen ska utföras. */
void Animation::Update(){
	/* Kollar om timern för framen har gått ut */
	if (mFrameTimer.getElapsedTime().asMilliseconds() > mTimePerFrame){
		/* Startar om timern inför nästa frame */
		mFrameTimer.restart();

		++mCurrentFrame; 
		if (mCurrentFrame >= mNumFrames){
			mCurrentFrame = 0;
		}
		/* Själva magin: ändrar texturrektangeln till den nya positionen på spritesheetet */
		sf::IntRect currentRect = mSprite.getTextureRect();
		currentRect.left = currentRect.width * mCurrentFrame;

		mSprite.setTextureRect(currentRect);
	}
}

/* För att sätta positionen på medlemsspriten i en Animation. */
void Animation::setPosition(const sf::Vector2f& position){
	mSprite.setPosition(position);
}

/* Getters */
const sf::Sprite& Animation::getSprite(){
	return mSprite;
}