//Recrea un objeto rebotando contra las paredes utilizando Vectores

#include <SFML/Graphics.hpp>

int main()
{
    constexpr unsigned int width = 1200;
    constexpr unsigned int height = 800;

    sf::RenderWindow window(sf::VideoMode({width, height}),
                             "Bouncing Ball");
    window.setFramerateLimit(60);

    int ballSize = 40;
    sf::CircleShape ball(ballSize);
    sf::Vector2f posicion{600.0f, 400.0f};
    sf::Vector2f velocity{2.0f, 2.5f};
    ball.setFillColor(sf::Color::Green);


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        ball.setPosition(posicion);
        if(posicion.x > width - ballSize * 2 || posicion.x < 0)
        {
            velocity.x *= -1;
        }
        if(posicion.y > height - ballSize * 2 || posicion.y < 0)
        {
            velocity.y *= -1;
        }
        posicion.x += velocity.x;
        posicion.y += velocity.y;
        window.draw(ball);
        window.display();
    }
}
