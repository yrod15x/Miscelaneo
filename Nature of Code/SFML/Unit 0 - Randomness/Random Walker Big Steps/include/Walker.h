#ifndef WALKER_H
#define WALKER_H
#include <SFML/Graphics.hpp>


class Walker
{
    public:
        Walker();
        Walker(float x, float y, float tam);
        ~Walker();
        void walk();
        void show(sf::RenderWindow &window);

    private:
        float _x, _y;
        float _tam;
};

#endif // WALKER_H
