/* Programa que expresa si un número es par o impar. Incluye funciones para
establecer si un texto tiene igualmente un número es par o impar de carácteres. */

#include <iostream>
#include <ctime>
#include <cstdlib>

bool isEvenOdd(int number)
{
    /*Programa que expresa si un número es par o impar. Args: number (int): número entero
    Returns: bool: verdadero si par*/
    return number % 2 == 0;
}

void printInfo()
{
    //imprime si un si un número es par o impar"""
    int num = (rand() % 100000) + 1;
    if (isEvenOdd(num))
    {
        std::cout << num << " is and an even number.\n";
    }
    else
    {
        std::cout << num << " is and an odd number.\n";
    }
}

int main()
{
    srand(time(0));
    for(int i = 0; i < 5; i++)
    {
        printInfo();
    }
    return 0;
}
