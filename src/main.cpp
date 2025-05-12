#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

int main()
{
    //TO DO: change to relative path
    std::ifstream fin("/Users/eryk/Desktop/workspace/maze_game/src/main.txt");
    if(!fin) {
        std::cerr << "unable to open file " << std::endl;
        std::cerr << "error: " << strerror(errno);
        return 1;
    }
    int num;
    int index = 0;
    int columns;
    int rows;

    fin >> columns >> rows;

    int* grid = new int[columns * rows];
    while(fin >> num) {
        grid[index] = num;
        index++;
    }
    fin.close();

    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            const int value = grid[j + i*columns];
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    sf::RectangleShape rectangle({50.f, 50.f});
    rectangle.setPosition({500, 500});

    float x_grid = 0.0f;
    float y_grid = 0.0f;
    float tile_size = 50.0f;
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
        for(int i=0; i<rows; i++) {
            for(int j=0; j<columns; j++) {
                const int value = grid[j + i*columns];
                sf::Color color = sf::Color(128, 128, 128);

                if(value == 0) {
                    color = sf::Color(128, 128, 128);
                }
                else if(value == 1) {
                    color = sf::Color(255, 255, 255);
                }
                else if(value == 2) {
                    color = sf::Color(0, 255, 0);
                }
                else if(value == 3) {
                    color = sf::Color(255, 0, 0);
                }
                sf::RectangleShape rectangle({tile_size, tile_size});

                rectangle.setPosition({x_grid + j * tile_size, y_grid + tile_size + i * tile_size});
                rectangle.setFillColor(color);
                rectangle.setOutlineThickness(-1.f);
                rectangle.setOutlineColor(sf::Color(250, 150, 100));

                window.draw(rectangle);
            }
        }
        //window.draw(rectangle);
        

        window.display();
    }
}
