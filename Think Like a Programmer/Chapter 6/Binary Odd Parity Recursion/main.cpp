#include <iostream>

/*Si el número de elementos de una lista de string binario es par o impar.*/

bool tieneParidad(char lista[], int tamano)
{
    bool paridad;
    for(int i = 0; i < tamano; i++)
    {
        paridad = (i % 2 == 0) ? true : false;
    }
    return paridad;
}

bool tieneParidadRec(char lista[], int tamano)
{
    if(tamano == 0) return false;
    bool paridad = (tamano - 1 % 2 == 0);
    return (paridad == tieneParidadRec(lista, tamano - 1));
}

int main()
{
    int tamano = 5;
    char binario[tamano] = {'0', '1', '0', '0', '1'};

    std::cout << tieneParidadRec(binario, tamano);

    return 0;
}
