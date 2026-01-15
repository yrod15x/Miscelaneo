#ifndef BOTON_H
#define BOTON_H
#include <SFML/Graphics.hpp>


class Boton
{
    public:
        Boton();
        Boton(sf::Vector2f tamano, float x, float y, sf::Color colorFondo);
        ~Boton();
        void mostrar(sf::RenderWindow &ventana);

    private:
        sf::RectangleShape _boton;
        sf::Text _texto;
        void _ponerTexto();
};

#endif // BOTON_H
