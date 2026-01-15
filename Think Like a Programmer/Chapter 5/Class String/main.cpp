#include <iostream>
#include "Cadena.h"
#include <string>

int main()
{
    Cadena palabra("Hola");
    Cadena palabra2(" mundo");
    Cadena palabra3;

    palabra2.agregar('!');
    std::cout << palabra.caracterEn(1) << '\n';
    //palabra.concadenar(palabra2);
    palabra.mostrar();
    //palabra2.mostrar();
    palabra3 = palabra2;
    std::cout << '\n';
    palabra3.mostrar();
    std::cout << '\n' << palabra3[1] << '\n';
    palabra.borrar(1, 3);
    palabra.mostrar();

    return 0;
}
