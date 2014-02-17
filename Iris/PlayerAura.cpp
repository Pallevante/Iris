/*

//Public funktioner

PlayerAura::PlayerAura(float xPosition, float yPosition, float speedMultiplier) :
mHealth(1),
mSpeed(6 * speedMultiplier),
mAcceleration(0.5f * speedMultiplier),
mIsAlive(true),


//M�ste �ndras relativt till bilden.
mRad(20.f)
{
	
	//mAnimation = new Animation("resource/textures/entities/playerAura.png", 100, 1);
	
	
}

PlayerAura::~PlayerAura(){}

void PlayerAura::tick(EntityVector &entities, float dt){
	move(dt);
	aura();
	mAnimation->Update();
	
}


//Collidefunktionen minskar alphav�rdet p� auran ifall kollision sker med en ENEMY

	int PlayerAura::collide(Entity *entity, EntityVector &entities){
	

	//h�mtar f�rgernas nuvarande v�rde f�r att kunna returnera r�tt f�rg och alphav�rde
	sf::Uint8 currentRed = mAnimation->getSprite().getColor().r;
	sf::Uint8 currentGreen = mAnimation->getSprite().getColor().g;
	sf::Uint8 currentBlue = mAnimation->getSprite().getColor().b;
	sf::Uint8 currentAlpha = mAnimation->getSprite().getColor().a;
	
	
	if (currentAlpha !=0){
		if (entity->getDamage() > 0 && entity->getType() == Entity::Type::ENEMY){
			currentAlpha -= entity->getDamage() / 2;
			if (currentAlpha < 6){
				currentAlpha = 0;
			}
			
			mAnimation->setColor(sf::Color(currentRed, currentGreen, currentBlue, currentAlpha));
			return 0;
		}
		else if (entity->getDamage() > 0 && entity->getType() != Entity::Type::ENEMY){
			return 0;
		}
		return 0;
	}
	return 0;
}


int PlayerAura::collide1(Entity *entity, Entity *entity1, EntityVector &entities){

	sf::Uint8 currentRed = mAnimation->getSprite().getColor().r;
	sf::Uint8 currentGreen = mAnimation->getSprite().getColor().g;
	sf::Uint8 currentBlue = mAnimation->getSprite().getColor().b;
	sf::Uint8 currentAlpha = mAnimation->getSprite().getColor().a;


	while (currentAlpha != 255){
		if (entity1->getType() == Entity::Type::ENEMY, entity->getDamage() > 0 && entity->getType() == Entity::Type::RAY){
			currentAlpha += entity1->getDamage();
			mAnimation->setColor(sf::Color(currentRed, currentGreen, currentBlue, currentAlpha));
			return 0;
		}
		else if (entity->getDamage() > 0 && entity->getType() != Entity::Type::RAY){
			mAnimation->setColor(sf::Color(currentRed, currentGreen, currentBlue, currentAlpha));
			return 0;
		}
		else if (entity1->getDamage() > 0 && entity1->getType() != Entity::Type::RAY){
			return 0;
		}
	}
	return 0;
}



//Get funktioner
bool PlayerAura::isAlive(){
	return mIsAlive;
}

int PlayerAura::getDamage() const{
	return mDamage;
}

sf::Vector2f PlayerAura::getPosition(){
	return mAnimation->getSprite().getPosition();
}

float PlayerAura::getRad() const{
	return mRad;
}

PlayerAura::Type PlayerAura::getType() const{
	return PLAYER;
}

sf::Color PlayerAura::getColor(){
	return mAnimation->getColor();
}


//Set funktioner
void PlayerAura::setDamage(int newDamage){
	mDamage = newDamage;
}

int PlayerAura::getHeight() const {
	return mAnimation->getSprite().getTextureRect().height;
}

int PlayerAura::getWidth() const {
	return mAnimation->getSprite().getTextureRect().width;
}


//Private medlemsfunktioner
void PlayerAura::move(float dt){
	float currentX = mAnimation->getSprite().getPosition().x;
	float currentY = mAnimation->getSprite().getPosition().y;

	sf::Vector2f oldVelocity = mVelocity;

	// Om den nuvarande hastigheten mVelocity �r mindre �n maxhastigheten, mSpeed, s� �kas den nuvarande hastigheten med accelerationen, mAcceleration 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		if (mVelocity.x < mSpeed){
			mVelocity.x += mAcceleration;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		if (mVelocity.x > -mSpeed){
			mVelocity.x -= mAcceleration;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		if (mVelocity.y < mSpeed){
			mVelocity.y += mAcceleration;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		if (mVelocity.y > -mSpeed){
			mVelocity.y -= mAcceleration;
		}
	}
	// F�r att sakta ner spelaren g�ngras den nuvarande hastigheten med ett v�rde som �r mindre �n 1. 
	mVelocity.x = mVelocity.x*0.935f;
	currentX = currentX + (oldVelocity.x + mVelocity.x) * 0.5 * dt;

	mVelocity.y = mVelocity.y*0.935f;
	currentY = currentY + (oldVelocity.y + mVelocity.y) * 0.5 * dt;
	// Den nuvarande positionen uppdateras med det nya v�rdet 
	mAnimation->setPosition(sf::Vector2f(currentX, currentY));

}


//testar auran genom att trycka p� "P"
void PlayerAura::aura(){
	
	sf::Uint8 currentRed = mAnimation->getSprite().getColor().r;
	sf::Uint8 currentGreen = mAnimation->getSprite().getColor().g;
	sf::Uint8 currentBlue = mAnimation->getSprite().getColor().b;
	sf::Uint8 currentAlpha = mAnimation->getSprite().getColor().a;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
		currentAlpha += mHealth;
		
	}
	
	mAnimation->setColor(sf::Color(currentRed, currentGreen, currentBlue, currentAlpha));
	
	
}



*/