/* Utiliza una distribución de probabilidad personalizada para variar el
tamaño de un paso dado por el aleatorio Walker. El tamaño del paso puede
 determinarse influyendo en el rango de valores elegidos.*/

#include <SFML/Graphics.hpp>
#include "Walker.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1200, 800 }), "Big Steps Walker");
    window.setFramerateLimit(30);

    Walker walker(600, 400, 5.f);
    window.clear();
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        walker.walk();
        walker.show(window);
        window.display();
    }
}
