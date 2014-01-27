#include "Animation.h"

/* Konstrukturn tar ett filnamn, antal millisekunder varje frame ska visas och antal frames. */
Animation::Animation(const std::string& filename, int timePerFrame, int numFrames) :
mTimePerFrame(timePerFrame),
mNumFrames(numFrames),
mCurrentFrame(0){
	/* Laddar in filen som en textur */
	mTexture.loadFromFile(filename);
	/* Anv�nder texturen som en sprite */
	mSprite.setTexture(mTexture);
	
	/* Visar den f�rsta framen av spritesheetet */
	sf::IntRect textureRect(0, 0, mTexture.getSize().x / mNumFrames, mTexture.getSize().y);
	mSprite.setTextureRect(textureRect);
};

Animation::~Animation(){

};

/* M�ste k�ras varje frame av programmet f�r att animationen ska utf�ras. */
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

/* F�r att s�tta positionen p� medlemsspriten i en Animation. */
void Animation::setPosition(const sf::Vector2f& position){
	mSprite.setPosition(position);
}

/* Getters */
const sf::Sprite& Animation::getSprite(){
	return mSprite;
}