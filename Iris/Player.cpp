#include "Player.hpp"
sf::Clock reloadTimer;


Player::Player(float xPosition, float yPosition, float speedMultiplier) :
mHealth(0),
mDamage(10),
mSpeed(360 * speedMultiplier),
mAcceleration(30.0f * speedMultiplier),
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

	/* Om den nuvarande hastigheten mVelocity �r mindre �n maxhastigheten, mSpeed, s� �kas den nuvarande hastigheten med accelerationen, mAcceleration */
	
	/*Ser till att man inte kan komma 'f�r' l�ngt utanf�r sk�rmen. 
	Allt relativt till nuvarande velocity och acceleration.*/



	/*
	H�ger:		H�mtar positionen, accelerationen och spelarens bredd f�r att kolla om spelaren �r p� kanten.
	V�nster:	H�mtar  positionen, accelerationen f�r att kolla om spelaren �r p� kanten.
	Ner:		H�mtar positionen, accelerationen och h�jden f�r att kolla om spelaren �r p� kanten
	Up:			H�mtar positionen, accelerationen f�r att kolla om spelaren �r p� kanten.

	Upp + v�nster fungerar s�h�r: Position - acceleration > Sk�rmh�jd/ < sk�rmbredd
	H�ger + ner fungerar s�h�r: Position + storlek - acceleration > sk�rmbredd/ < sk�rmh�jd
	*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		if (mVelocity.x < mSpeed){
			if (getPosition().x + mAcceleration + mAnimation->getSprite().getGlobalBounds().width < 1280)
				mVelocity.x += mAcceleration;				
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		if (mVelocity.x > -mSpeed){			
			if (getPosition().x - mAcceleration > 0)
				mVelocity.x -= mAcceleration;
		}
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		if (mVelocity.y < mSpeed){
			if (getPosition().y + mAnimation->getSprite().getGlobalBounds().height + mAcceleration < 720)
				mVelocity.y += mAcceleration;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		if (mVelocity.y > -mSpeed){
			if (getPosition().y -  mAcceleration > 0)
				mVelocity.y -= mAcceleration;
		}
	}



	/* F�r att sakta ner spelaren g�ngras den nuvarande hastigheten med ett v�rde som �r mindre �n 1. */
	mVelocity.x = mVelocity.x*0.935f;
	currentX = currentX + (oldVelocity.x + mVelocity.x) * 0.5 * dt;

	mVelocity.y = mVelocity.y*0.935f;
	currentY = currentY + (oldVelocity.y + mVelocity.y) * 0.5 * dt;
	/* Den nuvarande positionen uppdateras med det nya v�rdet */
	mAnimation->setPosition(sf::Vector2f(currentX, currentY));
	mAura->setPosition(mAnimation->getSprite().getPosition());

}


void Player::fire(EntityVector &entities){

	sf::Time isReloaded = reloadTimer.getElapsedTime();
	if (isReloaded.asMilliseconds() > 500){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
			/*S� att vi Ray slipper h�lla koll p� vilken entitet som skjuter och placera ut den p� spriten.*/
			entities.push_back(new Ray(sf::Vector2f(getPosition().x + getWidth(), getPosition().y + (getHeight() / 2)), false));
			/* Spelar upp skjutljud - no shit? */
			ResourceManager::getSound("resource/sounds/shoot.wav").play();
			reloadTimer.restart();

		}
	}
}

