/* Calcula la magnitud de un vector entre el ratón y el centro del canvas,
visualizándola como una barra en la parte superior de la pantalla. */

#include <SFML/Graphics.hpp>

int main()
{
    constexpr unsigned int width = 1200;
    constexpr unsigned int height = 800;

    sf::RenderWindow window(sf::VideoMode({width, height}),
                            "Magnitude");
    window.setFramerateLimit(60);

    sf::RectangleShape bar;

    while(window.isOpen())
    {
        while(const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear(sf::Color{0, 0, 0});

        //Crear linea primitiva
        sf::Vertex inicio{sf::Vector2f(width / 2, height / 2),
        sf::Color::Blue};
        sf::Vector2i raton = sf::Mouse::getPosition(window);
        sf::Vector2i centro{width / 2, height / 2};
        //Para que pueda hacer la magnitud una vez restado
        sf::Vector2f vectorM{
            static_cast<float>(raton.x) - centro.x,
            static_cast<float>(raton.y) - centro.y
        };

        //Magnitud
        float magnitud = vectorM.length();
        sf::Vertex posFinal{sf::Vector2f(raton + centro),
        sf::Color::Blue};
        std::array lineaRaton = {
            sf::Vertex{inicio},
            sf::Vertex{posFinal}
        };
        bar.setPosition(sf::Vector2f{0.0f, 0.0f});
        bar.setSize(sf::Vector2f{magnitud, 20.0f});
        bar.setFillColor(sf::Color::Red);
        window.draw(lineaRaton.data(), lineaRaton.size(),
                    sf::PrimitiveType::Lines);
        window.draw(bar);
        window.display();
    }
}
