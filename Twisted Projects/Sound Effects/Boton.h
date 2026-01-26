#ifndef BOTON_H
#define BOTON_H
#include <SFML/Graphics.hpp>
#include <string>

class Boton
{
    public:
        Boton();
        Boton(sf::Vector2f tamano, sf::Vector2f posicion, sf::Color colorFondo,
              std::string nombre);
        ~Boton();
        void mostrar(sf::RenderWindow &ventana);
        bool hayClick(sf::Vector2i mousePos);
        std::string getNombre();

    private:
        sf::RectangleShape _boton;
        sf::Text _texto;
        sf::Vector2f _posicion;
        sf::Vector2f _tamano;
        int _tamCaracter;
        std::string _nombre;
};

#endif // BOTON_H
