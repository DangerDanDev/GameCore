#include "Collider.h"

Collider::Collider(sf::RectangleShape& body)
	:body(body)
{

}

bool Collider::checkCollision(Collider& other, float push)
{
	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfSize = other.getHalfSize();

	sf::Vector2f thisPosition = this->getPosition();
	sf::Vector2f thisHalfSize = this->getHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	//if the intersect number is negative on the X and Y axis, a collision has occurred
	if (intersectX < 0.0f && intersectY < 0.f)
	{
		//clamp the push value between 0.f and 1.f
		push = std::min(std::max(push, 0.0f), 1.0f);

		//figure out whether the intersection is bigger on the X axis or the Y axis
		//if the X collision is larger, we act on that.
		if (abs(intersectX) < abs(intersectY))
		{
			move(intersectX * (1.f - push), 0.f);
			other.move(-intersectX * push, 0.f);
		}

		//push it out on the y axis
		else
		{
			move(0.f, -intersectY * (1.f - push));
			other.move(0.f, intersectY * push);
		}

		return true;
	}

	return false;
}
