/* Crea un objeto que se desplaza aleatoriamente en pantalla. Usando
una clase Walker */

#include <SFML/Graphics.hpp>
#include "Walker.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML works!");
    Walker walker(400, 300);
    window.setFramerateLimit(30);
    window.clear();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        walker.show(window);
        walker.walk();
        window.display();
    }
}
