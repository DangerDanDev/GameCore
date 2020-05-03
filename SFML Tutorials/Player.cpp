#include "Player.h"
#include <vector>

using std::string;
using std::vector;

Player::Player()
{
	sf::RectangleShape booty;
	const string FAMAS_0 = "Content\\FAMAS\\FAMAS_0";
	vector<std::string> famasFiles;
	famasFiles.push_back(FAMAS_0 + "0.png");
	famasFiles.push_back(FAMAS_0 + "1.png");
	famasFiles.push_back(FAMAS_0 + "2.png");
	famasFiles.push_back(FAMAS_0 + "3.png");
	famasFiles.push_back(FAMAS_0 + "4.png");
	famasFiles.push_back(FAMAS_0 + "5.png");
	famasFiles.push_back(FAMAS_0 + "6.png");
	famasFiles.push_back(FAMAS_0 + "7.png");
	famasFiles.push_back(FAMAS_0 + "8.png");
	famasFiles.push_back(FAMAS_0 + "9.png");
	this->animationSet = new AnimationList(this->body, 32.f, famasFiles);

	body.setSize(sf::Vector2f(65, 32));
}

void Player::update(float deltaTime)
{
	sf::Vector2f velocity;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += SPEED * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= SPEED * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		velocity.y -= SPEED * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		velocity.y += SPEED * deltaTime;

	body.setPosition(body.getPosition() + velocity);

	animationSet->update(deltaTime);
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(body);
}

Player::~Player()
{
	delete this->animationSet;
}

Collider Player::getCollider()
{
	return Collider(body);
}
