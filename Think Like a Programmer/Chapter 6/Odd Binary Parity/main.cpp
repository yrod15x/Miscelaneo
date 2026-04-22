#include <iostream>

/*Consider an array representing a binary string, where every element’s data
value is 0 or 1. Write a bool function to determine whether the binary string
has odd parity (an odd number of 1 bits). Hint: Remember that the recursive
function is going to return true (odd) or false (even), not the count of 1 bits.
Solve the problem first using iteration, then recursion */.

bool tieneParidad(char numeros[], int tamano)
{
    int suma = 0;
    for(int i = 0; i < tamano; i++)
    {
        if(numeros[i] == '1') suma += numeros[i];
    }
    return (suma % 2 == 0);
}


bool tieneParidadRec(char numeros[], int tamano)
{
    if(tamano == 0) return false;
    int unos = 0;
    unos += (numeros[tamano - 1] == '1') ? 1 : 0;
    bool esPar = (unos - 1 == 0);
    bool resto = tieneParidadRec(numeros, tamano - 1);
    return (esPar == resto);
}

int main()
{
    char numeros[5] = {'1', '0', '1', '0', '0'};

    std::cout << tieneParidadRec(numeros, 5) << '\n';

    return 0;
}
