/*Crea un objeto que recorre la pantalla aleatoriamente usando la clase
  Walker que usa el ruido de Perlin.*/

#include <SFML/Graphics.hpp>
#include "Walker.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1200, 800 }), "Perlin Walker");
    window.setFramerateLimit(30);
    Walker walker(600, 400);
    window.clear();
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        walker.show(window);
        walker.walk(1200, 800);
        window.display();
    }
}
