#include <iostream>
#include <string>
#include "Automibile.h"

int main()
{
    Automibile carro("Mazda", "CV5", 2020);

    carro.descripcion();
    std::cout << carro.getEdad() << '\n';

    return 0;
}
