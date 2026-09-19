/* """Demuestra la substracción vectorial tomando la diferencia entre
 dos puntos: la posición del mouse y el centro de la ventana.""" */

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//Se debe incluir para realizar la substracción de vectores
#include <SFML/System/Vector2.hpp>

int main()
{
    constexpr unsigned int width = 1200;
    constexpr unsigned int height = 800;

    sf::RenderWindow window(sf::VideoMode({width, height}),
                            "Vector Substraction");
    window.setFramerateLimit(60);

       sf::RectangleShape centerLine;

    while(window.isOpen())
    {
        while(const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear();
        //Crear una linea sin espesor
        sf::Vertex inicio{sf::Vector2f(0.0f, 0.0f)};
        /*Para obtener la posición del mouse relativa a la venta se debs
        incluir el objeto ventana como parámetro de getPosition*/
        sf::Vector2 posRaton = sf::Mouse::getPosition(window);
        sf::Vertex ratonFinal{sf::Vector2f(posRaton)};
        std::array mouseLine =
        {
            sf::Vertex{inicio},
            sf::Vertex{ratonFinal}
        };
        sf::Vector2 posCentro = sf::Vector2(width / 2, height / 2);
        sf::Vertex centroFinal{sf::Vector2f(posCentro)};
        std::array centroLine =
        {
            sf::Vertex{inicio},
            sf::Vertex{centroFinal}
        };
        //Dibujar primeras dos lineas
        window.draw(mouseLine.data(), mouseLine.size(),
                     sf::PrimitiveType::Lines);
        window.draw(centroLine.data(), centroLine.size(),
                     sf::PrimitiveType::Lines);
        //Substraction
        /* nuevo es un vector relativo al origen (0, 0), no una posición
          absoluta de la ventana. Por eso, para trasladar el origen al
          centro, se debe sumar el vector al punto inicial*/
        sf::Vector2 nuevo = posRaton - sf::Vector2i(posCentro);
        sf::Vector2 fin = sf::Vector2i(posCentro) + nuevo;
        ratonFinal.position = sf::Vector2f(posRaton);
        mouseLine =
        {
            sf::Vertex{centroFinal},
            sf::Vertex{sf::Vector2f(fin)}
        };

        window.draw(mouseLine.data(), mouseLine.size(),
                     sf::PrimitiveType::Lines);

        window.display();
    }
}
