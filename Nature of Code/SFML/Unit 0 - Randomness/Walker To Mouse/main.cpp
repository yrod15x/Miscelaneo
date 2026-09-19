/*  Crea un objeto que se desplaza hacia al mouse en pantalla,
 usando una clase Walker.*/

#include <SFML/Graphics.hpp>
#include "Walker.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1200, 800 }), "Ve al Mouse");
    Walker walker(600, 400);
    window.setFramerateLimit(60);
    window.clear();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        walker.show(window);
        walker.walk(window);
        window.display();
    }
}
