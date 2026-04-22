/* Write a function that is passed an array of integers and a “target” number
and that returns the number of occurrences of the target in the array. Solve
the problem first using iteration, then recursion.*/

#include <iostream>

int ocurrencias(int lista[], int tamano, int objetivo)
{
    int numOcurrencias = 0;
    for(int i = 0; i < tamano; i++)
    {
        if(lista[i] == objetivo) numOcurrencias++;
    }
    return numOcurrencias;
}

int ocurrenciasRec(int lista[], int tamano, int objetivo)
{
    if(tamano == 0) return 0;
    int suma = (lista[tamano - 1] == objetivo) ? 1 : 0;
    return suma + ocurrenciasRec(lista, tamano - 1, objetivo);
}

int main()
{
    int tamano = 5;
    int numeros[] = {1, 2, 2, 4, 2};

    std::cout << ocurrenciasRec(numeros, tamano, 5) << '\n';

    return 0;
}
