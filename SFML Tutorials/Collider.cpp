#include "Collider.h"

Collider::Collider(sf::RectangleShape& body)
	:body(body)
{
	body.setOrigin(body.getSize() / 2.f);
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
		//if the X collision is smaller, we act on that.
		if (intersectX > intersectY)
		{
			if (deltaX > 0.f)
			{
				move(intersectX * (1.f - push), 0.f);
				other.move(-intersectX * push, 0.f);
			}
			else
			{
				move(-intersectX * (1.f - push), 0.f);
				other.move(intersectX * push, 0.f);
			}
		}
		else
		{
			if (deltaY > 0.f)
			{
				move(0.f,intersectY * (1.f - push));
				other.move(0.f,-intersectY * push);
			}
			else
			{
				move(0.f,-intersectY * (1.f - push));
				other.move(0.f,intersectY * push);
			}
		}

		return true;
	}

	return false;
}
