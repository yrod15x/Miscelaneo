/*Programa que simula el juego Fizz Buzz en SFML. En pantalla habrá un número en pantalla
que irá cambiando cada segundo hasta llegar a un limite elegido al azar entre dos limites.*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

void setTexto (sf::RenderWindow &screen, std::string texto, int posX,
               int posY, int tamano, int alpha = 100)
{
    //Font set up and a text and it shows it in the screen
    sf::Color color = {0, 0, 0, alpha};
    sf::Font font;
    if(!font.loadFromFile("digital.otf"))
    {
        std::cerr << "Error\n";
        std::exit(-1);
    }
    sf::Text textText;
    textText.setFont(font);
    textText.setString(texto);
    textText.setCharacterSize(tamano);
    textText.setColor(color);
    textText.setPosition(posX, posY);
    screen.draw(textText);
}

void setCircle(sf::RenderWindow &screen, int radio, int posX, int posY,
               sf::Color color, int &alpha)
{
    sf::CircleShape circle(radio);
    circle.setOutlineThickness(5.0f);
    circle.setOutlineColor({0, 0, 0, alpha});
    circle.setOrigin(sf::Vector2f(radio / 2.0, radio / 2.0));
    circle.setFillColor(color);
    circle.setPosition(sf::Vector2f(posX / 1.0, posY / 1.0));
    screen.draw(circle);
}

void changeState(bool suiche, int &alpha)
{
    (suiche == true) ? alpha = 255 : alpha = 100;
}

int main()
{
    int width = 1600;
    int height = 1000;
    int redAlpha = 100;
    int greenAlpha = 100;
    int yellowAlpha = 100;

    // Create the main window
    sf::RenderWindow ventana(sf::VideoMode(width, height), "Fizz Buzz");
    ventana.setFramerateLimit(30);

    sf::Time delay = sf::seconds(1.0f);
    int numero = 1;

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
                if(numero == 60) numero = 0;
                    break;
            }
        }

        // Clear screen
        if(numero == 60) numero = 0;
        ventana.clear(sf::Color::White);

        sf::Color green = {0, 255, 0, greenAlpha};
        sf::Color yellow = {255, 255, 0, yellowAlpha};
        sf::Color red = {255, 0, 0, redAlpha};

        // Draw objects
        setTexto(ventana, std::to_string(numero), width / 2 - 180,  0, 460, 255);
        setCircle(ventana, 140, 200, height / 2 + 120, green, greenAlpha);
        setTexto(ventana, "Fizz", width / 2 - 600, height / 2 + 140, 80, greenAlpha);
        setCircle(ventana, 140, width / 2 - 100, height / 2 + 120, yellow, yellowAlpha);
        setTexto(ventana, "Buzz", width / 2 - 105, height / 2 + 140, 80, yellowAlpha);
        setCircle(ventana, 140, width / 2 + 400, height / 2 + 120, red, redAlpha);
        setTexto(ventana, "No", width / 2 + 430, height / 2 + 140, 80, redAlpha);

        numero++;
        if(numero == 60) numero = 0;

        // Update the window
        ventana.display();
        sf::sleep(delay);

        //FizzBuzz
        changeState((numero % 15 == 0), greenAlpha);
        changeState((numero % 15 == 0), greenAlpha);
        //Fizz
        changeState((numero % 3 == 0), greenAlpha);
        //Buzz
        changeState((numero % 5 == 0), yellowAlpha);
        //Not
        changeState((numero % 3 != 0) && (numero % 5 != 0), redAlpha);

    }

    return EXIT_SUCCESS;
}
