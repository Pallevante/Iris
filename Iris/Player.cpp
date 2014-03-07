#include "Player.hpp"
sf::Clock reloadTimer;

/*Public funktioner*/
bool isFlipped = false;


Player::Player(float xPosition, float yPosition, float speedMultiplier) :
mHealth(0),
mDamage(10),
mSpeed(6 * speedMultiplier),
mAcceleration(0.5f * speedMultiplier),
mIsAlive(true),
entities(entities),

mRad(20.f)
{
	mAura = new Animation("resource/textures/entities/playerAura.png", 100, 1);
	mAnimation = new Animation("resource/textures/entities/player.png", 100, 8);

	mAnimation->setPosition(sf::Vector2f(xPosition, yPosition));
	mAura->setPosition(mAnimation->getSprite().getPosition());

}

Player::~Player(){
	delete mAnimation;
}


void Player::tick(EntityVector &entities, float dt){
	move(dt);
	fire(entities);
	mAnimation->Update();
	mAura->setPosition(mAnimation->getSprite().getPosition());
	mAura->setColor(sf::Color(255,255,255,opacity));
	mAura->Update();
}

void Player::updateAura(float score){

	opacity = 255 * score;
	if (score >= 1.0f) {
		opacity = 210;
	}
	if (score <= 0){
		opacity = 0;
	}
}

int Player::collide(Entity *entity, EntityVector &entities){

	if (entity->getDamage() > 0 && entity->getType() == Entity::Type::ENEMY){
		mHealth -= entity->getDamage() / 2;
	}
	return 0;
}




/*Get funktioner*/
bool Player::isAlive(){
        return mIsAlive;
}

int Player::getDamage() const{
        return mDamage;
}

sf::Vector2f Player::getPosition(){
        return mAnimation->getSprite().getPosition();
}

float Player::getRad() const{
        return mRad;
}

Player::Type Player::getType() const{
        return PLAYER;
}


/*Set funktioner*/
void Player::setDamage(int newDamage){
        mDamage = newDamage;
}

int Player::getHeight() const {
        return mAnimation->getSprite().getTextureRect().height;
}

int Player::getWidth() const {
        return mAnimation->getSprite().getTextureRect().width;
}



/*Private medlemsfunktioner*/

void Player::move(float dt){
	float currentX = mAnimation->getSprite().getPosition().x;
	float currentY = mAnimation->getSprite().getPosition().y;


	sf::Vector2f oldVelocity = mVelocity;

	/* Om den nuvarande hastigheten mVelocity är mindre än maxhastigheten, mSpeed, så ökas den nuvarande hastigheten med accelerationen, mAcceleration */
	
	/*Ser till att man inte kan komma 'för' långt utanför skärmen. 
	Allt relativt till nuvarande velocity och acceleration.*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		if (mVelocity.x < mSpeed){
			if (getPosition().x + (mVelocity.x + mAcceleration) < 1280 - mAnimation->getSprite().getGlobalBounds().width)
				mVelocity.x += mAcceleration;				
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		if (mVelocity.x > -mSpeed){			
			if (getPosition().x - (mVelocity.x + mAcceleration) > 0)
				mVelocity.x -= mAcceleration;
		}
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		if (mVelocity.y < mSpeed){
			if (-mAnimation->getSprite().getGlobalBounds().height + 720 - (mAcceleration + mVelocity.y) > getPosition().y)
				mVelocity.y += mAcceleration;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		if (mVelocity.y > -mSpeed){
			if (getPosition().y - (mAcceleration + mAcceleration) > 0)
				mVelocity.y -= mAcceleration;
		}
	}



	/* För att sakta ner spelaren gångras den nuvarande hastigheten med ett värde som är mindre än 1. */
	mVelocity.x = mVelocity.x*0.935f;
	currentX = currentX + (oldVelocity.x + mVelocity.x) * 0.5 * dt;

	mVelocity.y = mVelocity.y*0.935f;
	currentY = currentY + (oldVelocity.y + mVelocity.y) * 0.5 * dt;
	/* Den nuvarande positionen uppdateras med det nya värdet */
	mAnimation->setPosition(sf::Vector2f(currentX, currentY));
	mAura->setPosition(mAnimation->getSprite().getPosition());

}


void Player::fire(EntityVector &entities){

	sf::Time isReloaded = reloadTimer.getElapsedTime();
	if (isReloaded.asMilliseconds() > 500){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
			/*Så att vi Ray slipper hålla koll på vilken entitet som skjuter och placera ut den på spriten.*/
			entities.push_back(new Ray(sf::Vector2f(getPosition().x + getWidth(), getPosition().y + (getHeight() / 2)), false));
			/* Spelar upp skjutljud - no shit? */
			ResourceManager::getSound("resource/sounds/shoot.wav").play();
			reloadTimer.restart();

		}
	}
}

