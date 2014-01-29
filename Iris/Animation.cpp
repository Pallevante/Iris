#include "Animation.h"


Animation::Animation(const std::string& filename, int timePerFrame, int numFrames) :
mTimePerFrame(timePerFrame),
mNumFrames(numFrames),
mCurrentFrame(0){
	/* Laddar in filen som en textur */
	//mTexture.loadFromFile(filename);

	
	/* Använder texturen som en sprite */
	mSprite.setTexture(ResourceManager::getTexture(filename));
	
	/* Visar den första framen av spritesheetet */
	sf::IntRect textureRect(0, 0, ResourceManager::getTexture(filename).getSize().x / mNumFrames, ResourceManager::getTexture(filename).getSize().y);
	mSprite.setTextureRect(textureRect);
};

Animation::~Animation(){

};


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

/*
void Animation::updateTexture(){
	mSprite.setTexture(mTexture);
}*/
/* Setters */
void Animation::setPosition(const sf::Vector2f& position){
	mSprite.setPosition(position);
}

/* Getters */
const sf::Sprite Animation::getSprite(){
	return mSprite;
}