#include <SFML/Graphics.hpp>
#include "Mover.h"

int main()
{
    constexpr unsigned int width = 1200;
    constexpr unsigned int height = 800;

    sf::RenderWindow window(sf::VideoMode({width, height}), "Mover");
    window.setFramerateLimit(60);
    Mover *movers;
    movers = new Mover[5];
    for(int i = 0; i < 5; i++)
    {
        movers[i] = Mover(width, height);
    }

    while(window.isOpen())
    {
        while(const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>()) window.close();
        }
        window.clear(sf::Color{51, 51, 51});
        for(int i = 0; i < 5; ++i)
        {
            movers[i].update(window);
            movers[i].checkEdeges(width, height);
            movers[i].show(window);
        }


        window.display();
    }
}
