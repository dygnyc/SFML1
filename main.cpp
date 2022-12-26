#include <SFML/Graphics.hpp>
#include <iostream>
#include "Hero.h"

sf::Vector2f viewSize(1280, 720);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello SFML Game!!!",
                        sf::Style::Default);

sf::Vector2f playerPosition(0, 0);
bool playerMoving = false;

Hero hero;
float initialVelocity =750.0f;


void init()
{
    hero.init("Sprite.png",
              sf::Vector2f(viewSize.x * 0.25f, viewSize.y * 0.5f),
              200.0f);
}

void updateInput()
{
    sf::Event event;
    while (window.pollEvent(event))
    {

        if (event.type==sf::Event::KeyPressed){
            if(event.key.code==sf::Keyboard::Up){
                hero.jump(initialVelocity);
            }
        }

        if (event.key.code == sf::Keyboard::Escape ||
            event.type == sf::Event::Closed)
            window.close();
    }
}

void update(float dt)
{
    hero.update(dt);
}

void draw()
{
    window.draw(hero.getSprite());
}

int main()
{

    sf::Clock clock;
    window.setFramerateLimit(60);

    init();

    while (window.isOpen())
    {
        updateInput();

        sf::Time dt = clock.restart();
        update(dt.asSeconds());

        window.clear(sf::Color::Blue);

        draw();

        window.display();
    }

    return 0;
}