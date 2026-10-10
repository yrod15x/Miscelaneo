/* Mueve un objeto tipo globo de helio que sube y rebota con el tope
 de una ventana. Si se oprime el mouse se simula la fuerza del
 viento aplicada al globo.*/

#include <SFML/Graphics.hpp>
#include "Balloon.h"
#include <random>

int randNumber(int low, int high)
{
    static thread_local std::mt19937 randEngine(std::random_device{}());
    std::uniform_int_distribution<int> dist(low, high);
    return dist(randEngine);
}

int main()
{
    constexpr unsigned int width = 1200;
    constexpr unsigned int height = 800;

    sf::RenderWindow window(sf::VideoMode({width, height}), "Balloon");
    window.setFramerateLimit(60);
    sf::Color bgGround(50, 153, 204);

    Balloon ballon(width, height, 40);
    sf::Vector2f wind = {1.0f, 0.0f};
    int dirWind = 0;

    while(window.isOpen())
    {
        window.clear(bgGround);
        while(const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
            {
                window.close();
            }
            if(event->is<sf::Event::MouseButtonPressed>())
            {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {
                    //Cambiar la dirección del viento
                    dirWind = randNumber(0, 1);
                    if(dirWind == 1) wind *= -1.0f;
                    ballon.applyForce(wind);
                }
            }
        }
        ballon.update();
        ballon.checkBorders(width);
        ballon.show(window);
        window.display();
    }
}
