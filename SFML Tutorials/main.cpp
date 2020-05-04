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
    player.getCollider().priority = Collider::Priority::Animate;
    sf::View view;
    view.setCenter(player.getPosition());

    sf::Texture platformTexture;
    platformTexture.loadFromFile("Content\\platform_grey.jpg");
    Platform platform(&platformTexture, sf::Vector2f(200, 50), sf::Vector2f(300, 200));
    platform.getCollider().setPushback(0.9f);
    Platform platform2(&platformTexture, sf::Vector2f(200, 50), sf::Vector2f(500, 200));
    platform2.getCollider().setPushback(0.1f);


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
        Collider platform1Collider = platform.getCollider();
        Collider platform2Collider = platform2.getCollider();

        //playerCollider.checkCollision(platform1Collider, 1.0f);
        //playerCollider.checkCollision(platform2Collider, 1.0f);

        platform.getCollider().checkCollision(player.getCollider());
        platform2.getCollider().checkCollision(player.getCollider());
        platform.getCollider().checkCollision(platform2.getCollider());

        view.setCenter(player.getPosition());
        window.setView(view);

        platform.Draw(window);
        platform2.Draw(window);
        player.draw(window);
        platform3.Draw(window);

        window.display();
    }

    return 0;
}