#ifndef WALKER_H
#define WALKER_H
#include <SFML/Graphics.hpp>
#include "PerlinNoise.hpp"

class Walker
{
    public:
        Walker();
        Walker(float x, float y);
        void show(sf::RenderWindow &window);
        void walk(float windowWidth, float windowHeight);
        virtual ~Walker();

    private:
        float _x, _y;
        float _dx, _dy;
        siv::PerlinNoise noise;
};

#endif // WALKER_H
