#ifndef TECLA_H
#define TECLA_H
#include <SFML/Graphics.hpp>
#include <string>


class Tecla
{
    public:
        Tecla();
        ~Tecla();
        Tecla(const Tecla& other);
        void mostrar(sf::RenderWindow &ventana);
        void setTecla(sf::Vector2f tamano, sf::Vector2f posicion,
                      sf::Color bgcolor, std::string caracter,
                      sf::Color colCaracter);
        void setPosicion(sf::Vector2f posicion);
        void setCaracter(char caracter);
        bool hayClick(sf::RenderWindow &ventana);
        std::string getCaracter();

    private:
        sf::Vector2f _posicion;
        sf::Color _bgcolor;
        sf::Vector2f _tamano;
        sf::RectangleShape _tecla;
        std::string _caracter;
        sf::Color _colCaracter;
};

#endif // TECLA_H
