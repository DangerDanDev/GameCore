#include "Collider.h"
#include <iostream>

using std::cout;
using std::endl;

Collider::Collider(sf::RectangleShape& body)
	:body(body)
{
	body.setOrigin(body.getSize() / 2.f);
}

float clamp(float push, float min, float max);

bool Collider::checkCollision(Collider& other)
{
	//if either entity does not have collision enabled,
	//we must return false
	if (!this->enabled || !other.enabled)
		return false;

	//if neither object is moveable, they will simply phase through each other
	if (this->immovable && other.immovable)
		return false;

	//we want to compute the collision from the point of view of whichever collider has a higher
	//animate/inanimate preference
	if (other.priority > this->priority)
		return other.checkCollision(*this);

	//find the difference between my center and the other objects center
	sf::Vector2f delta = this->getPosition() - other.getPosition();

	//adding the two half sizes together will tell us how 
	//close to each other the colliders need to be on both the X and Y axes
	sf::Vector2f combinedHalfSize(this->getHalfSize().x + other.getHalfSize().x, this->getHalfSize().y + other.getHalfSize().y);

	//if our delta is smaller than the combined half sizes of each collider, a collision has occurred
	if (abs(delta.x) - combinedHalfSize.x < 0 && abs(delta.y) - combinedHalfSize.y < 0)
	{

		//this is the value we need in order to physically separate the two entities
		//the difference in abs(centers) - the combined half sizes of the colliders
		sf::Vector2f intersect(abs(delta.x) - combinedHalfSize.x, abs(delta.y) - combinedHalfSize.y);

		//if it's shorter distance to resolve collision
		// on the x axis, we do so
		if (abs(intersect.x) <= abs(intersect.y))
		{

			//if I'm to the left of the other collider, we move left
			if (delta.x < 0)
			{
				//but my movement is impeded by a magnitude equal to the other entity's pushback
				this->move(intersect.x * (other.pushBack), 0);
				other.move(-intersect.x * (1.f - other.pushBack), 0);
			}

			//if I'm not to the left, I'm to the right, so we move right
			else
			{
				this->move(-intersect.x * (other.pushBack), 0);
				other.move(intersect.x * (1.f - other.pushBack), 0);
			}

		}

		//otherwise we resolve on the Y axis
		else
		{

			//if I'm above the other rectangle, we'll move up
			if (delta.y < 0)
			{
				this->move(0, intersect.y * (other.pushBack));
				other.move(0, -intersect.y * (1.f - other.pushBack));
			}

			//if I'm below it, we'll move down
			else
			{
				this->move(0, -intersect.y * other.pushBack);
				other.move(0, intersect.y * (1.f - other.pushBack));
			}
		}

		return true;
	}

	return false;
}

void Collider::setPushback(float pb)
{
	if (pb > 1.f || pb < 0.f)
		cout << "pushback must be between 0.f and 1.f!" << endl;
	
	this->pushBack = clamp(pb, 0.f, 1.f);
}

bool Collider::oldCheckCollision(Collider& other, float push)
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
				move(0.f, intersectY * (1.f - push));
				other.move(0.f, -intersectY * push);
			}
			else
			{
				move(0.f, -intersectY * (1.f - push));
				other.move(0.f, intersectY * push);
			}
		}

		return true;
	}

	return false;
}

float clamp(float value, float min, float max)
{
	if (value > max)
		return max;
	else if (value < min)
		return min;
	else
		return value;
}
