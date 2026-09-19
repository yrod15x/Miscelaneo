#ifndef PERLINNOISE_H
#define PERLINNOISE_H
#include "PerlinNoise.h"
#include <array>
#include <algorithm>
#include <numeric>
#include <random>
#include <cmath>


class PerlinNoise
{
    public:
        explicit PerlinNoise(unsigned int seed);
        double noise(double x, double y) const;

    private:
        // Permutation table used to generate pseudo-random gradients.
        // It contains 512 values because the first 256 values are repeated.
        std::array<int, 512> permutation;
        static double fade(double t);
        static double lerp(double a, double b, double t);
        static double gradient(int hash, double x, double y);

};

#endif // PERLINNOISE_H
