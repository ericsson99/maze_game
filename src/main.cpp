#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>


int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    sf::Texture texture("/Users/eryk/Desktop/workspace/tank_game/src/tank_sprite.png"); // Throws sf::Exception if an error occurs
    sf::Sprite rectangle(texture);
    rectangle.setPosition({200, 200});

    sf::RectangleShape backgroud = sf::RectangleShape({1920.0f, 1080.0f});
    backgroud.setFillColor({246, 220, 189});
    backgroud.setPosition({0.0f, 0.0f});
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            // left key is pressed: move our character
            rectangle.move({-1.f, 0.f});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            // left key is pressed: move our character
            rectangle.move({1.f, 0.f});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            // left key is pressed: move our character
            rectangle.move({0.f, -1.f});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            // left key is pressed: move our character
            rectangle.move({0.f, 1.f});
        }
        window.draw(backgroud);
        window.draw(rectangle);
        

        window.display();
    }
}
