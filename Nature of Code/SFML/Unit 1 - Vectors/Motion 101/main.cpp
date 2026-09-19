#include <SFML/Graphics.hpp>
#include "Mover.h"

int main()
{
    constexpr unsigned int width = 1200;
    constexpr unsigned int height = 800;

    sf::RenderWindow window(sf::VideoMode({width, height}), "Mover");
    window.setFramerateLimit(60);
    Mover mover(width, height);

    while(window.isOpen())
    {
        while(const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>()) window.close();
        }
        window.clear(sf::Color{51, 51, 51});
        mover.update();
        mover.checkEdeges(width, height);
        mover.show(window);

        window.display();
    }
}
