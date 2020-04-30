#include <SFML/Graphics.hpp>
#include "Animation.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    Animation animation("Content\\417 13frames 10fps.png", 5, 7, 2);

    sf::RectangleShape gun;
    gun.setSize(sf::Vector2f(76, 32));
    gun.setTexture(animation.getTexture());
    gun.setTextureRect(animation.getUVRect());

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


        window.clear(sf::Color::Yellow);

        animation.update(deltaTime);
        gun.setTextureRect(animation.getUVRect());
        window.draw(gun);

        window.display();
    }

    return 0;
}