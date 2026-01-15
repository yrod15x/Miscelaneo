
/* Write a program that reads a line of text, counting the number of words,
identifying the length of the longest word, the greatest number of vowels
in a word, and/or any other statistics you can think of.*/

#include <iostream>

void estadisticas()
{
    int numTotalLetras = 0;
    int numletrasPal = 0;
    int numPalabras = 0;
    int mayor = 0;
    int menor = 1000;
    int numVocales = 0;
    int mayorVocales = 0;
    char car;

    do
    {
        car = std::cin.get();
        if(car != 32)
        {
            numTotalLetras++;
            numletrasPal++;
            switch (car)
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                numVocales++;
                break;
            
            default:
                break;
            }
        }
        if(car == 32 || car == 10)
        {
            if(mayor < numletrasPal) mayor = numletrasPal;
            if(menor > numletrasPal) menor = numletrasPal;
            if(mayorVocales < numVocales) mayorVocales = numVocales;
            numletrasPal = 0;
            numVocales = 0;
            if(car == 10) numTotalLetras--;
            numPalabras++;
        }        
    } while (car != 10);
    std::cout << "La cantidad de palabras totales es " << numPalabras << '\n';
    std::cout << "La cantidad de caracteres es " << numTotalLetras << '\n';
    std::cout << "La palabra con mas larga tiene " << mayor << " caracteres\n";
    std::cout << "La palabra con mas corta tiene " << menor << " caracteres\n";
    std::cout << "La palabra con mas vocales tiene " << mayorVocales << '\n';
}

int main()
{
    std::cout << "Escriba un texto >> ";
    estadisticas();
    return 0;
}