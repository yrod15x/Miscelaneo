#include <iostream>

int sumaRecursiva(int enteros[], int tamano)
{
    if(tamano == 0) return 0;
    return sumaRecursiva(enteros, tamano - 1) + enteros[tamano - 1];
}

int main()
{
    int numeros[5] = {5, 3, 6, 1, 8};

    std::cout << sumaRecursiva(numeros, 5) << '\n';

    return 0;
}
