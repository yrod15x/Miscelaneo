/* Rellenar todos los pixeles de una ventana (perlin noise 2d es un grilla)
usando el ruido de perlin*/

#include <SFML/Graphics.hpp>
#include "PerlinNoise.hpp"
#include <cstdint>
#include <vector>
#include <ctime>

int stepRandom()
{
    return (rand() % + 255) + 1;
}

int main()
{
    constexpr unsigned int width = 1200;
    constexpr unsigned int height = 800;
    siv::PerlinNoise noise;
    srand(time(NULL));
    noise.reseed(123456u * stepRandom()/2) ;

    sf::RenderWindow window(sf::VideoMode({width, height}),
        "Perlin Noise 2D");

    window.setFramerateLimit(60);

    /* Array de píxeles en formato RGBA. Cada píxel ocupa
     cuatro posiciones:rojo, verde, azul y alfa.*/
    std::vector<std::uint8_t> pixels(width * height * 4);

    // Crear la textura donde se copiarán los píxeles
    sf::Texture texture({width, height});

    // Crear un sprite para dibujar la textura
    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
        // Procesar eventos
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        float xoff = 0.0;
        // Modificar los píxeles directamente
        for (unsigned int x = 0; x < width; ++x)
        {
            float yoff = 0.0;
            for (unsigned int y = 0; y < height; ++y)
            {
                float bright = noise.noise2D(xoff, yoff) * 255;

                // Posición del píxel dentro del array RGBA
                const std::size_t index = (x + y * width) * 4;
                pixels[index + 0] = stepRandom(); // Rojo
                pixels[index + 1] = bright; // Verde
                pixels[index + 2] = stepRandom();  // Azul
                pixels[index + 3] = 255; // Alfa
                yoff += 0.01;
            }
            xoff += 0.01;
        }

        // Copiar directamente el array a la textura
        texture.update(pixels.data());

        // Dibujar el resultado
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
