#include <iostream>

/* Write a function to compute the sum of just the positive numbers in an array
of integers. First, solve the problem using iteration. Then, using the technique
shown in this chapter, convert your iterative function to a recursive function.*/

int sumaPositivos(int numeros[], int tamano)
{
    int suma = 0;
    for(int i = 0; i < tamano; i++)
    {
        if(numeros[i] > 0) suma += numeros[i];
    }
    return suma;
}

int recSumaPositivos(int numeros[], int tamano)
{
    if(tamano == 0) return 0;
    int positivo = (numeros[tamano - 1] > 0) ? positivo = numeros[tamano - 1] : 0;
    return positivo + recSumaPositivos(numeros, tamano - 1);
}

int main()
{
    int numeros[5] = {-2, 0, 1, 2, 3};

    std::cout << recSumaPositivos(numeros, 5) << '\n';

    return 0;
}
