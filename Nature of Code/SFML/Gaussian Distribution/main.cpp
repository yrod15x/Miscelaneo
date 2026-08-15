/*Muestra la distribución gausiana (randomGaussian()) poniendo varios círculos
 en pantalla. */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>

int randomColor()
{
    return (rand() % + 255) + 1;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1200, 800 }),
                             "Gaussian Distribution");
    window.setFramerateLimit(30);
    //Obtener la semilla del hardware del pc
    std::random_device rd;
    //Inicializar el motor Mersenne con la semilla
    std::mt19937 gen(rd());
    //Definir la distribución gaussiana
    std::normal_distribution<double> dist(600, 200);

    sf::CircleShape circulo(30.0f);

    window.clear();
    srand(time(NULL));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        circulo.setFillColor(sf::Color{randomColor(), randomColor(),
                             randomColor(), 20});
        float posX = dist(gen);
        sf::Vector2f pos(posX, 400.0f);
        circulo.setPosition(pos);

        window.draw(circulo);
        window.display();

    }
}
