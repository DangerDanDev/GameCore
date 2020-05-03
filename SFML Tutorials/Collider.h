#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
public:
	sf::RectangleShape& body;

	Collider(sf::RectangleShape& body);

	void move(float dx, float dy) { body.move(dx, dy); }

	bool checkCollision(Collider& other, float push);
	
	sf::Vector2f getPosition() { return body.getPosition(); };
	sf::Vector2f getHalfSize() { return body.getSize() / 2.f; };

private:
	//This method is kept around solely for reference 
	//to compare its functionality with newer versions
	bool oldCheckCollision(Collider& other, float push);

};

