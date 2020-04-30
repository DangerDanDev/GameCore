#include <SFML/Graphics.hpp>
#include "Animation.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");


    float fps = 30.f; int frames = 13; int rows = 7; int cols = 2;
    Animation animation("Content\\417 13frames 10fps.png", fps, frames, sf::Vector2i(rows,cols));
    sf::RectangleShape gun;
    gun.setSize(sf::Vector2f(76, 32));
    gun.setTexture(animation.getTexture());
    gun.setTextureRect(animation.getUVRect());

    Animation famasAnim("Content\\FAMAS 10frames 16fps.png", 16.f, 10, sf::Vector2i(5, 2));
    sf::RectangleShape famas;
    famas.setPosition(300, 300);
    famas.setSize(sf::Vector2f(famasAnim.getFrameSize().x,famasAnim.getFrameSize().y));
    famas.setTexture(famasAnim.getTexture());
    famas.setTextureRect(famasAnim.getUVRect());

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

        famasAnim.update(deltaTime);
        famas.setTextureRect(famasAnim.getUVRect());
        window.draw(famas);

        window.display();
    }

    return 0;
}