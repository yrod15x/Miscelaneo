/*  LUHN CHECKSUM VALIDATION
The Luhn formula is a widely used system for validating identification numbers. Using
the original number, double the value of every other digit. Then add the values of the
individual digits together (if a doubled value now has two digits, add the digits individually).
The identification number is valid if the sum is divisible by 10.
Write a program that takes an identification number of arbitrary length and
determines whether the number is valid under the Luhn formula. The program must
process each character before reading the next one.*/

#include <iostream>

void recibirDigito(int &digito)
{
    while(true)
    {
       std::cout << "Ingrese un digito de (0-9). (-1) para terminar >> ";
       std::cin >> digito;
       if(digito < -1 || digito > 9)
       {
        std::cout << "El digito es incorrecto\n";
       }
       else
       {
           break;
       }
    }
}

void doblarDigito(int &digito, int cont)
{
    if(cont % 2 == 0) digito = digito * 2;
}

int main()
{
    int digito;
    int contDigitos = 0;
    int suma = 0;
    while(true)
    {
      recibirDigito(digito);
      if(digito == -1) break;
      contDigitos++;
      doblarDigito(digito, contDigitos);
      suma += (digito > 9) ? 1 + (digito % 10) : digito;
    }
    if(suma % 10 == 0)
    {
        std::cout << "El numero es valido.\n";
    }
    else
    {
        std::cout << "El numero es no valido.\n";
    }
    return 0;
}
