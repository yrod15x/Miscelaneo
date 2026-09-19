#include "PerlinNoise.h"
#include <array>
#include <algorithm>
#include <numeric>
#include <random>
#include <cmath>

// Smooths a value between 0 and 1.
// This reduces visible grid artifacts.
double PerlinNoise::fade(double t)
{
    return t * t * t * (t * (t * 6 - 15) + 10);
}
// Linear interpolation between two values.
double PerlinNoise::lerp(double a, double b, double t)
{
    return a + t * (b - a);
}
// Calculates the dot product between a gradient direction
// and the distance from a grid corner.
double PerlinNoise::gradient(int hash, double x, double y)
{
    switch (hash & 3)
    {
        case 0:
            return  x + y;
        case 1:
            return -x + y;
        case 2:
            return  x - y;
        default:
            return -x - y;
    }
}
// Creates a Perlin noise generator.
// A fixed seed produces the same noise pattern every time.
// A random seed produces a different pattern each time.
PerlinNoise::PerlinNoise(unsigned int seed = std::random_device{}())
{
    // Create an array containing the numbers 0 through 255.
    std::array<int, 256> values;
    std::iota(values.begin(), values.end(), 0);

    // Shuffle the values to create a random permutation table.
    std::mt19937 generator(seed);
    std::shuffle(values.begin(), values.end(), generator);

    // Copy the shuffled values into a table of size 512.
    // The second half repeats the first half.
    for (int i = 0; i < 256; ++i)
    {
        permutation[i] = values[i];
        permutation[i + 256] = values[i];
    }
}
// Generates 2D Perlin noise.
//
// The returned value is clamped to the range [0.0, 1.0].
double PerlinNoise::noise(double x, double y) const
{
    // Find the integer grid cell containing the point.
    //
    // The bitwise AND with 255 keeps the index inside
    // the permutation table.
    int x0 = static_cast<int>(std::floor(x)) & 255;
    int y0 = static_cast<int>(std::floor(y)) & 255;

    // Find the point's local position inside the grid cell.
    double localX = x - std::floor(x);
    double localY = y - std::floor(y);

    // Calculate smooth interpolation weights.
    double u = fade(localX);
    double v = fade(localY);

    // Get a pseudo-random gradient hash for each
    // of the four corners of the grid cell.
    int bottomLeft  = permutation[permutation[x0]     + y0];
    int topLeft     = permutation[permutation[x0]     + y0 + 1];
    int bottomRight = permutation[permutation[x0 + 1] + y0];
    int topRight    = permutation[permutation[x0 + 1] + y0 + 1];

    // Interpolate between the bottom-left and bottom-right corners.
    double bottom = lerp(
            gradient(bottomLeft, localX, localY),
            gradient(bottomRight, localX - 1, localY),
            u);

        // Interpolate between the top-left and top-right corners.
    double top = lerp(
            gradient(topLeft, localX, localY - 1),
            gradient(topRight, localX - 1, localY - 1),
            u);

    // Interpolate vertically between the bottom and top values.
    double result = lerp(bottom, top, v);

    // Perlin noise is approximately in the range [-1, 1].
    // Convert that range to [0, 1]:
    //
    //     -1 -> 0
    //      0 -> 0.5
    //      1 -> 1
    //
    // clamp() guarantees the final result stays in [0, 1].
        return std::clamp(result * 0.5 + 0.5, 0.0, 1.0);
    }



