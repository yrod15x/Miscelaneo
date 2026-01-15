#include <iostream>
#include "Registros.h"

using namespace std;

int main()
{
    Registros estudiante;

    estudiante.agregar(3, 50);
    estudiante.agregar(7, 80);
    estudiante.agregar(1, 85);
    estudiante.agregar(8, 90);
    estudiante.agregar(2, 88);
    estudiante.mostrar();
    //std::cout << estudiante.promediar() << '\n';
    estudiante.eliminar(7);
    //estudiante.mostrar();
    std::cout << "-----------\n";
    Registros estudiante2 = estudiante.registroEnRango(70, 90);
    std::cout << "-----------\n";
    estudiante2.mostrar();

    return 0;
}
