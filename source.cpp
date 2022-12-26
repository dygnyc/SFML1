#include <SFML/Graphics.hpp>

sf::Vector2f viewSize(1280, 720);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello SFML Game!!!",
                        sf::Style::Default);

sf::Texture heroTexture;
sf::Sprite heroSprite;
sf::Vector2f playerPosition(0,0);
bool playerMoving = false;
float moveSpeed = 200;

void init()
{
    heroTexture.loadFromFile("Sprite.png");
    heroSprite.setTexture(heroTexture);

    heroSprite.setPosition(sf::Vector2f(100, 100));
    heroSprite.setOrigin(sf::Vector2f(128, 128));
}

void draw()
{
    window.draw(heroSprite);
}

void updateInput()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if(event.type ==sf::Event::KeyPressed){
            if (event.key.code ==sf::Keyboard::Right){
                playerMoving=true;
            }
        }

        if(event.type ==sf::Event::KeyReleased){
            if (event.key.code==sf::Keyboard::Right){
                playerMoving=false;
            }
        }


        if (event.key.code == sf::Keyboard::Escape||
            event.type == sf::Event::Closed)
            window.close();
    }
}

void update(float dt){
    if(playerMoving){
        heroSprite.move(moveSpeed * dt,0);
    }
}

int main()
{

    sf::Clock clock;

    init();

    while (window.isOpen())
    {
        updateInput();

        sf::Time dt=clock.restart();
        update(dt.asSeconds());

        window.clear(sf::Color::Blue);

        draw();

        window.display();
    }

    return 0;
}