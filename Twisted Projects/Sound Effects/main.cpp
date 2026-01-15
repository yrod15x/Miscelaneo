#include <SFML/Graphics.hpp>
#include "Boton.h"

/*Programa que genera un tablero para reproducir efectos de sonido
EL tablero esta compuesto de botones (RectShapes) que al ser presionados
generan el sonido. */

int main()
{
    int width = 2400;
    int height = 1600;

    // Create the main window
    sf::RenderWindow ventana(sf::VideoMode(width, height), "Sound Effects Board");

    Boton btnDrums(sf::Vector2f(400.0f, 200.0f), sf::Vector2f(400.0f, 400.0f),
                   sf::Color::Cyan);

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

        // Clear screen
        ventana.clear(sf::Color::Magenta);

        // Draw object
        btnDrums.mostrar(ventana);

        // Update the window
        ventana.display();
    }

    return EXIT_SUCCESS;
}

