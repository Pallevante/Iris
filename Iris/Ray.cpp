#include "Ray.hpp"


Ray::Ray(sf::Vector2f position) :
mDamage(10),
mRad(3)
{
	mCircleShape.setPosition(position);
	mCircleShape.setFillColor(sf::Color::Blue);
	mCircleShape.setRadius(mRad);
}

Ray::~Ray(){}

