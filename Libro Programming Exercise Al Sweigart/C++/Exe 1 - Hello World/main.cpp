/** Programa que pide el nombre al usuario. Lo busca en archivo para saber si el
nombre ya esta registrado y lo saluda de acuerdo a esta operación. Si el nombre
no existe lo actualiza en el archivo.**/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

void mayusInicial(std::string &nombre)
{
    for(int i = 0; i < nombre.size(); i++)
    {
        if(i == 0)
        {
             nombre[i] = char(toupper(nombre[i]));
        }
    }
}

std::vector<std::string> leer_datos(char nom[])
{
    //Devuelve una lista (vector) de nombres contenidos en un archivo (parámetro)
    std::ifstream archivo;
    std::string linea;
    std::vector<std::string> nombres;

    archivo.open(nom);
    if(!archivo.is_open())
    {
        std::cout << "El archivo no pudo ser abierto\n";
        return nombres;
    }
    while(std::getline(archivo, linea))
    {
        nombres.push_back(linea);
    }
    archivo.close();
    return nombres;
}

void escribir_nombre(char nom[], std::string nombre)
{
    //Agrega un nombre al archivo de texto que es el parámetro
    std::ofstream archivo;

    archivo.open(nom, std::ios_base::app);
    archivo << nombre << '\n';

    archivo.close();
}

void pedir_nombre(std::string &nom)
{
    //Devuelve un nombre pedido al usuario
    std::cout << "Hola, quiero se tu amigo!\n";
    nom = "";
    while(nom == "")
    {
        std::cout << "Como te llamas? >> ";
        std::getline(std::cin, nom);
        if(nom != "")
        {
            break;
        }
        else
        {
            std::cout << "Creo que no escribiste tu nombre.\n";
        }
    }
}

bool teConozco(std::vector<std::string> nombres, std::string &nombre)
{
    //Función que saluda al usario y registra su nombre sino esta en el archivo
    bool esConocido = false;
    mayusInicial(nombre);

    for(auto nom : nombres)
    {
        if(nombre == nom)
        {
            esConocido = true;
            break;
        }
    }
    if(esConocido)
    {
        std::cout << "Hola " << nombre << ". Es un gusto volver a hablarte.\n";
    }
    else
    {
        std::cout << "Mucho gusto " << nombre << "! No te conocia.\n";
        escribir_nombre("personas.txt", nombre);
    }

    return esConocido;
}

int main()
{
    std::vector<std::string> nombres;
    std::string nombre;

    nombres = leer_datos("personas.txt");
    pedir_nombre(nombre);
    teConozco(nombres, nombre);

    return 0;
}
