/* Programa en SFML 3.0que crea un gráfico de barras leyendo un
archivo de texto*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdio.h>
#include <vector>

std::map<std::string, int> leer_datos(char nomArchivo[])
{
    std::ifstream archivo;
    std::string linea;
    std::string nombre;
    std::string cantidad;
    std::map<std::string, int> datos;

    archivo.open(nomArchivo);
    if(!archivo.is_open())
    {
        std::cout << "Archivo no pudo ser abierto\n";
        exit(0);
    }
    bool suiche = false;
    while(std::getline(archivo, linea))
    {
        nombre = "";
        cantidad = "";
        suiche = false;
        for(auto &car:linea)
        {
            if(car == ' ')
            {
                suiche = true;
                continue;
            }
            (!suiche) ? nombre += car : cantidad += car;
        }
        datos[nombre] = std::stoi(cantidad);

    }
    archivo.close();
    return datos;
}

sf::RectangleShape *agregarBarras(std::map<std::string, int> datos, int ancho)
{
    int numBarras = datos.size();
    sf::RectangleShape *tempbarras = new sf::RectangleShape[numBarras];
    int i = 0;
    int anchoBarra = ancho / datos.size();
    anchoBarra -= anchoBarra / 4;
    int offSet = anchoBarra / 2;
    for(auto &[key, val]:datos)
    {
        tempbarras[i].setSize(sf::Vector2f(anchoBarra, (val * 20)* -1));
        tempbarras[i].setPosition(sf::Vector2f(offSet, 1100));
        tempbarras[i].setFillColor(sf::Color::Cyan);
        offSet += anchoBarra + anchoBarra * 0.25;
        i++;
    }
    return tempbarras;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1600, 1200 }), "Bar Chart");
    sf::RectangleShape *barras;
    std::map<std::string, int> datos;
    datos = leer_datos("coordenadas.txt");
    int numBarras = datos.size();
    barras = agregarBarras(datos, 1600);

    std::vector<sf::Text> textos;
    sf::Font fuente;
    if(!fuente.openFromFile("fuente.ttf"))
    {
        std::cerr << "Fuente no cargada\n";
        std::exit(1);
    }
    int anchoBarra = 1600 / datos.size();
    anchoBarra -= anchoBarra / 4;
    int tamLetra = 40;
    int offSet = 2 *(anchoBarra / 2) - (tamLetra / 4);

    for(auto &[key, val]:datos)
    {
        sf::Text texto(fuente);
        texto.setCharacterSize(tamLetra);
        texto.setFillColor(sf::Color::Magenta);
        texto.setStyle(sf::Text::Bold);
        texto.setString(key);
        texto.setPosition(sf::Vector2f(offSet, 1120));
        textos.emplace_back(texto);
        offSet += anchoBarra + anchoBarra * 0.25;
    }

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        //window.draw(shape);
        for(int i = 0; i < numBarras; i++)
        {
            window.draw(barras[i]);
            window.draw(textos[i]);
        }
        window.display();
    }
    delete[] barras;
}
