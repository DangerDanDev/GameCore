#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape& body);

	void move(float dx, float dy) { body.move(dx, dy); }

	/////////////////////////////////////////////
	// Computes if I have collided with another collider,
	// and if so, separates the two entities as applicable.
	// Automatically returns false if both colliders are immovable (two immovable objects will phase thru each other)
	// or if either entity has collision disabled (this->disabled == false)
	/////////////////////////////////////////////
	bool checkCollision(Collider& other);
	
	sf::Vector2f getPosition() { return body.getPosition(); };
	sf::Vector2f getHalfSize() { return body.getSize() / 2.f; };

	///////////////////////
	// Whether the collider can be moved by another collider.
	// If an immovable collider hits another immovable collider,
	// their collision will not be computed, they will simply phase through each other.
	///////////////////////
	bool immovable = false;

	///////////////////////
	// Represents whether collisions are computed for this entity
	///////////////////////
	bool enabled = true;

	//////////////////////
	// Represents whether an object can act upon other objects
	//////////////////////
	enum class Priority
	{
		Inanimate = 0,
		InanimatePlus = 1,
		Animate = 2,
	};


	////////////////////////
	// Represents whether or not this object is
	// inanimate
	/////////////////////////
	Priority priority = Priority::Inanimate;

	float getPushback() { return this->pushBack; }
	void setPushback(float pushback);

private:
	//This method is kept around solely for reference 
	//to compare its functionality with newer versions
	bool oldCheckCollision(Collider& other, float push);

	///////////////////////
	// The collision rectangle
	// of my owning entity
	///////////////////////
	sf::RectangleShape& body;

	/////////////////////////
	// How much this object resists being pushed
	// Higher number (maximum of one) indicates 
	// higher difficulty of pushing.
	// DEFAULTS to 1.F, indicating that by default, an 
	// entity is immovable.
	/////////////////////////
	float pushBack = 1.f;
};

