/* Clase que genera una plantilla para que un objeto se mueva por pantalla
usando vectores con una velocidad influida por una aceleración aleatoria
con el efecto Perlin.*/

#include <SFML/Graphics.hpp>
#include "Mover.h"

int main()
{
    constexpr unsigned int width = 1600;
    constexpr unsigned int height = 1200;

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
