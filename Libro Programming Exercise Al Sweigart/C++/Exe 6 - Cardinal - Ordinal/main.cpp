/*Programa que pone en pantalla 10 círculos en dos series de 5. Cada
serie de tiene color y un número de 1 a 5. Y se mueven por pantalla. Al
interponerse los círculos con el mismo número camabia de cardinal a
ordinal */

#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Bolita.h"

std::string OrdToCardinal(int num)
{
    int ultDigito = 0;

    while(num > 0)
    {
        ultDigito = num % 10;
        num /= 10;
    }
    switch(ultDigito)
    {
        case 1:
            return "1st";
        case 2:
            return "2nd";
        case 3:
            return "3rd";
        default:
            return std::to_string(ultDigito) + "th";
    }
}

int main()
{
    int width = 2400;
    int height = 1600;
    srand(time(NULL));
    Bolita circulos[10];
    sf::Vector2f velocidad;
    std::string texto;
    int tamTexto = 80;

    //sf::CircleShape circulos[10];

    sf::RenderWindow ventana(sf::VideoMode(width, height), "Cardinal To Ordinal");

    int radio = 100;
    int posX, posY;
    posX = (std::rand() % (width - (radio * 4) + 1)) + radio * 2;
    posY = (std::rand() % (height - (radio * 4) + 1)) + radio * 2;
    sf::Vector2f posicion(static_cast<float>(posX), static_cast<float>(posY));
    int i = 1;

    circulos[0].setCirculo(static_cast<float>(radio), posicion, sf::Color::Cyan);
    bool choca = false;

    //Crear las dos series de objetos
    Bolita equipoA[5];
    Bolita equipoB[5];

    equipoA[0] = circulos[0];
    equipoA[0].setTexto("1");

    // Crear los circulos que no salgan en la misma posición
    Bolita temp;

    while(i < 10)
    {
        posX = (std::rand() % (width - (radio * 4) + 1)) + radio * 2;
        posY = (std::rand() % (height - (radio * 4) + 1)) + radio * 2;
        posicion.x = static_cast<float>(posX);
        posicion.y = static_cast<float>(posY);
        if(i < 5)
        {
            if(i > 0) temp.setTexto(std::to_string(i + 1));

            temp.setCirculo(static_cast<float>(radio), posicion, sf::Color::Cyan);
        }
        else
        {
            temp.setTexto(std::to_string(i - 5 + 1));
            temp.setCirculo(static_cast<float>(radio), posicion, sf::Color::Green);
        }

        choca = false;
        //Verificar la intersección de los circulos
        for(int j = 0; j < i; j++)
        {
            if(temp.seChoca(circulos[j]))
            {
                choca = true;
                break;
            }
        }

        if(!choca)
        {
            circulos[i] = temp;
            if (i < 5)
            {
                equipoA[i] = circulos[i];
            }
            else
            {
                equipoB[i - 5] = circulos[i];
            }
            i++;
        }
    }


	// Start the game loop
    while (ventana.isOpen())
    {
        // Process events
        sf::Event event;
        while (ventana.pollEvent(event))
        {
            // Close window : exit
            switch(event.type)
            {
                // Close window : exit
                case sf::Event::Closed:
                ventana.close();
                break;
                case sf::Event::KeyReleased:
                if(event.key.code == sf::Keyboard::Escape)
                    ventana.close();
                break;
            }
        }

        for(int i = 0; i < 5; i++)
        {
            equipoA[i].mover(width, height);
            equipoB[i].mover(width, height);
        }

        // Clear screen
        ventana.clear();



        // Draw objects
        for(int i = 0; i < 5; i++)
        {
            //Hacer que el texto quede cambiado a cardina
            if(equipoA[i].colision(equipoB[i]))
            {
                equipoA[i].setOffSetTexto(4, 8);
                equipoA[i].setTexto(OrdToCardinal(i + 1));
                equipoA[i].setTamtexto(tamTexto / 2);
            }

            equipoA[i].mostrar(ventana);
            equipoB[i].mostrar(ventana);
        }

        // Update the window
        ventana.display();
    }

    return EXIT_SUCCESS;
}

