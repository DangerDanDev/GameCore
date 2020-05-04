#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
	:collider(Collider(body))
{
	body.setSize(size);
	body.setPosition(position);
	body.setTexture(texture);
	body.setOrigin(size / 2.f);
}

void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

Collider& Platform::getCollider()
{
	return this->collider;
}
