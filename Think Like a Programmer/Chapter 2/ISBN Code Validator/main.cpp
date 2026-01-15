/*Intente escribir un programa para un sistema de dígitos de control, como
el sistema ISBN de 13 dígitos. El programa toma un número de identificación y
lo verifica.*/

#include <iostream>

bool validarISBN()
{
    int suma = 0;
    int numero;
    int cont = 1;
    char digito;

    digito = std::cin.get();

    while(cont <= 13)
    {
        numero = digito - '0';
        if(numero >= 0 && numero <= 9)
        {
           (cont % 2 != 0) ? suma += numero : suma += numero * 3;
           digito = std::cin.get();
           cont++;
        }
        else
        {
            digito = std::cin.get();
        }

    }
    std::cout << "\nEste codigo ";
    return suma % 10 == 0;
}


int main()
{
    std::cout << "Escriba un numero de indentificacion ISBN de 13 digitos >> ";
    (validarISBN()) ? std::cout << " es valido\n" : std::cout << "no es valido\n"; ;
    return 0;
}
