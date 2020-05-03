#pragma once
#include "AnimationList.h"
#include <SFML/Graphics.hpp>
#include "Collider.h"

class Player
{
public:
	Player();

	void update(float deltaTime);
	void draw(sf::RenderWindow& window);

	sf::Vector2f getPosition() { return body.getPosition(); }

	~Player();

	Collider getCollider();

private:
	sf::RectangleShape body;
	AnimationList *animationSet;

	

	const float SPEED = 100;

};

