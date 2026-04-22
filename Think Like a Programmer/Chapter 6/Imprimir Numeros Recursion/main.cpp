#include <iostream>

/* Write a program in C++ to print the first 50 natural numbers using recursion*/

void imprimirRec(int numero)
{
    if(numero == 0) return;
    imprimirRec(numero - 1);
    std::cout << numero << " ";
}

int main()
{
    imprimirRec(50);
    std::cout << '\n';

    return 0;
}
