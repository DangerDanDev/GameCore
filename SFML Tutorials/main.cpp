#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "AnimationList.h"

using std::vector;
using std::string;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");


    sf::RectangleShape gun;
    float fps = 30.f; int frames = 13; int rows = 7; int cols = 2;
    Animation animation(gun, "Content\\417 13frames 10fps.png", fps, frames, sf::Vector2i(rows,cols));
    gun.setSize(sf::Vector2f(76, 32));
    gun.setTexture(animation.getTexture());
    gun.setTextureRect(animation.getUVRect());

    sf::RectangleShape famas;
    Animation famasAnim(famas, "Content\\FAMAS 10frames 16fps.png", 16.f, 10, sf::Vector2i(5, 2));
    famas.setPosition(300, 300);
    famas.setSize(sf::Vector2f(famasAnim.getFrameSize().x,famasAnim.getFrameSize().y));
    famas.setTexture(famasAnim.getTexture());
    famas.setTextureRect(famasAnim.getUVRect());

    sf::RectangleShape famasList(sf::Vector2f(65, 32));
    famasList.setPosition(400, 00);
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
    AnimationList famasListAnim(famasList, 32.f, famasFiles);

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

        animation.update(deltaTime);
        window.draw(gun);

        famasAnim.update(deltaTime);
        window.draw(famas);

        famasListAnim.update(deltaTime);
        window.draw(famasList);

        window.display();
    }

    return 0;
}