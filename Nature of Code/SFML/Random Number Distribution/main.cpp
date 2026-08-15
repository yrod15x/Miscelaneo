/* Muestra en forma de gráfico de barras la frecuencia de aparición de números
aleatorios*/

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

int randomNumber(int maxNum)
{
    //Genera un número aleatorio de 0 a un límite sin incluirlo
    return (rand() % maxNum) - 1;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1200, 800 }),
                             "Random Number Distribution");
    window.setFramerateLimit(60);

    sf::RectangleShape bar;
    int total = 20;
    int widthBar = 1200 / total;

    int *heightsBar = new int[total];
    int index = 0;
    //Iniciar todos los números a 0
    for(int i = 0; i < total; i++)
    {
        heightsBar[i] = 0;
    }

    while (window.isOpen())
    {
        srand(time(NULL));
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        index = randomNumber(total);
        heightsBar[index]++;
        for(int i = 0; i < total; i++)
        {
            //posX = multiplica tamano de la barra por i
            //posY = Altura menos lo que va creciendo la altura de la barra
            bar.setPosition(sf::Vector2f(i * widthBar, 800 - heightsBar[i]));
            bar.setSize(sf::Vector2f(widthBar - 1, heightsBar[i]));
            bar.setFillColor(sf::Color::Green);
            window.draw(bar);
        }

        window.display();
    }
    delete[] heightsBar;
}
