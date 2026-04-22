#include <SFML/Graphics.hpp>
#include "Tecla.h"
#include <iostream>

//Programa que

Tecla *iniciarTeclas(int tam, sf::Vector2f tamTeclas)
{
    Tecla *teclas = new Tecla[tam];

    for(int i = 0; i < tam; i++)
    {
        teclas[i].setTecla(tamTeclas,sf::Vector2f(0, 0),
                 sf::Color::White, "-1", sf::Color::Red);
    }
    return teclas;
}

void ponerPosiciones(Tecla *teclas, int tam, sf::Vector2f posicion,
                     float gapLateral, float gapVertical, int tecXLinea)
{
    float offset = 0;
    float xPosInicio = posicion.x;
    int contOffset = 0;
    int contLineas = 0;
    for(int i = 0; i < tam; i++)
    {
        teclas[i].setPosicion(posicion);
        if(contLineas == tecXLinea)
        {
            posicion.y += gapVertical;
            posicion.x = xPosInicio - (gapLateral / 2) +
                        (gapLateral / 2 * contOffset);
            contOffset++;
            tecXLinea--;
            contLineas = 0;
        }
        posicion.x += offset;
        offset = gapLateral;
        contLineas++;
    }
}

void asignarCaracter(Tecla *teclas, int tam, int carInicio)
{
    for(int i = 0; i < tam; i++)
    {
        teclas[i].setCaracter(char(carInicio));
        carInicio++;
    }
}

int main()
{
    int width = 2400;
    int height = 1600;
    float alturaTecla = 105.0f;
    float anchoTecla = 105.0f;
    int numTeclas = 95;
    int carIncio = 32;
    int carInt;

    // Create the main window
    sf::RenderWindow ventana(sf::VideoMode(width, height), "Tabla Ascii");

    Tecla *teclas;
    teclas = iniciarTeclas(numTeclas, sf::Vector2f(alturaTecla,anchoTecla));
    ponerPosiciones(teclas, numTeclas, sf::Vector2f(110.0, 750.0f), 115,
                    alturaTecla * 1.2, 19);
    asignarCaracter(teclas, numTeclas, carIncio);

    Tecla borrar;
    borrar.setTecla(sf::Vector2f(500.0f, alturaTecla),
                    sf::Vector2f(1450, 1380), sf::Color::Red,
                    "Borrar", sf::Color::White);
    sf::Font fuente;
    if(!fuente.loadFromFile("fuente.ttf"))
    {
        std::cerr << "Fuente no cargada\n";
        std::exit(-1);
    }
    sf::Text codAscii;
    codAscii.setFont(fuente);
    codAscii.setCharacterSize(350);
    codAscii.setColor(sf::Color::White);
    codAscii.setPosition(sf::Vector2f(width / 2 - 200, 100.0f));

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
                case sf::Event::MouseButtonPressed:
                    if(event.mouseButton.button == sf::Mouse::Left)
                    {
                        for(int i = 0; i < numTeclas; i++)
                        {
                            if(teclas[i].hayClick(ventana))
                            {
                                carInt = int(teclas[i].getCaracter()[0]);
                                codAscii.setString(std::to_string(carInt));
                            }
                        }
                        if(borrar.hayClick(ventana))
                        {
                            codAscii.setString("");
                        }
                    }
            }
        }
        // Clear screen
        ventana.clear();

        // Draw objects
        for(int i = 0; i < numTeclas; i++)
        {
            teclas[i].mostrar(ventana);
        }
        borrar.mostrar(ventana);

        ventana.draw(codAscii);

        // Update the window
        ventana.display();
    }

    return EXIT_SUCCESS;
}

