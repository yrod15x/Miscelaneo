#ifndef BOLITA_H
#define BOLITA_H
#include <SFML/Graphics.hpp>
#include <string>

class Bolita
{
    public:
        Bolita();
        Bolita(float radio, sf::Vector2f posicion, sf::Color color);
        void mostrar(sf::RenderWindow &ventana);
        virtual ~Bolita();
        bool seChoca(Bolita &circulo);
        sf::CircleShape getBolita();
        void setCirculo(float radio, sf::Vector2f posicion, sf::Color color);
        void chocarPantalla(int limWidth, int );
        void mover(int limWidth, int limHeight);
        bool colision(Bolita &otra);
        void setTexto(std::string texto);
        void setTamtexto(int tamano);
        std::string getTexto();
        void setOffSetTexto(int offSetAlt, int offSetAnc);
    private:
        float _radio;
        sf::Vector2f _posicion;
        sf::Color _color;
        sf::CircleShape _circulo;
        sf::Vector2f _velocidad;
        std::string _texto;
        sf::Text _numero;
        int _tamTexto = 80;
        int _offSetTextAlt = 2;
        int _offSetTextAnc = 4;
};

#endif // BOLITA_H
