#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Boton.h"
#include <map>
#include <vector>
#include <string>
#include <iostream>

/*Programa que genera un tablero para reproducir efectos de sonido
EL tablero esta compuesto de botones (RectShapes) que al ser presionados
generan el sonido. */

void crearBotones(std::map<std::string, Boton> &botones,
                  std::vector<std::string> nombreBotones)
{
    int yoffset = 0;
    int xoffset = 0;
    int cont = 0;
    for(auto &nombres:nombreBotones)
    {
        botones[nombres] = Boton(sf::Vector2f(360.0f, 120.0f),
            sf::Vector2f(220.0f + xoffset, 800.0f + yoffset),
            sf::Color::Cyan, nombres);
        cont++;
        if(cont % 4 != 0)
        {
            xoffset += 540;
        }
        else
        {
            yoffset += 240;
            xoffset = 0;
        }
    }
}


int main()
{
    int width = 2400;
    int height = 1600;
    int numParlantes = 3;
    sf::Texture parlantes[numParlantes];
    sf::RectangleShape parlantesRect[numParlantes];
    int parlOffset = 0;

    for(int i = 0; i < numParlantes; i++)
    {
        parlantes[i].loadFromFile("speaker.png");
        parlantesRect[i].setSize(sf::Vector2f(640.0f, 640.0f));
        parlantesRect[i].setPosition(sf::Vector2f(160.0f + parlOffset, 60.0f));
        parlantesRect[i].setTexture(&parlantes[i]);
        parlOffset += 720;
    }

    // Create the main window
    sf::RenderWindow ventana(sf::VideoMode(width, height), "Sound Effects Board");

    std::map<std::string, Boton> botones;
    std::vector<std::string> nombreBotones = {"Thunder", "Crowd", "Horror", "Cricket",
    "Gunshot", "Applause", "Explosion", "Scratch", "Scream", "Siren", "Punch",
    "Alarm"};

    crearBotones(botones, nombreBotones);

    sf::SoundBuffer buffer;
    sf::Sound sound;
    std::string extension = ".wav";

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
                //Mouse click
                case sf::Event::MouseButtonPressed:
                    if(event.mouseButton.button == sf::Mouse::Left)
                    {
                        std::string efecto;
                        sf::Vector2i mousePos = sf::Mouse::getPosition(ventana);
                        bool huboClick = false;
                        for(auto[key, value]: botones)
                        {
                            if(value.hayClick(mousePos))
                            {
                                efecto = value.getNombre();
                                efecto.append(extension);
                                if(!buffer.loadFromFile(efecto))
                                {
                                    std::cerr << "No se pudo cargar el archivo\n";
                                    std::exit(-1);
                                }
                                huboClick = true;
                            }
                        }

                        sound.setBuffer(buffer);
                        if(huboClick) sound.play();
                    }
                break;
            }
        }

        // Clear screen
        ventana.clear(sf::Color::Magenta);

        // Draw object
        for(auto[key, value]: botones)
        {
            value.mostrar(ventana);
        }
        for(int i = 0; i < numParlantes; i++)
        {
            ventana.draw(parlantesRect[i]);
        }


        // Update the window
        ventana.display();
    }

    return EXIT_SUCCESS;
}

