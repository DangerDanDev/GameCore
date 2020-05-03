#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "AnimationList.h"
#include "Player.h"
#include "Platform.h"

using std::vector;
using std::string;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    Player player;

    sf::Texture platformTexture;
    platformTexture.loadFromFile("Content\\platform_grey.jpg");
    Platform platform(&platformTexture, sf::Vector2f(200, 50), sf::Vector2f(300, 200));

    sf::Clock clock;

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Cyan);



        player.update(deltaTime);

        Collider playerCollider = player.getCollider();
        platform.getCollider().checkCollision(playerCollider, 0.0f);

        platform.Draw(window);
        player.draw(window);

        window.display();
    }

    return 0;
}