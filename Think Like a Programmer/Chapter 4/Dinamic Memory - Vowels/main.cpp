/*Design your own: Take a problem that you already know how to solve using
an array but that is limited by the size of the array. Rewrite the code to remove
that limitation using a dynamically allocated array.*/

#include <iostream>

typedef char *cadena;

int numCaracteres(cadena texto)
{
    int cont = 0;
    while(texto[cont] != 0)
    {
        cont++;
    }
    return cont;
}

void remplazarCaracter(cadena &texto, char viejo, char nuevo)
{
    //Remplaza un caracter en un texto por otro.
    int numVocales = 0;
    int cont = numCaracteres(texto);
    cadena textoCambiado = new char[cont + 1];

    for(int i = 0; i < cont; i++)
    {
        (texto[i] == viejo) ? textoCambiado[i] = nuevo : textoCambiado[i] = texto[i];
    }
    textoCambiado[cont] = 0;
    texto = textoCambiado;
}

int main()
{
    cadena texto = "Hola estas";
    remplazarCaracter(texto, 'a', 'y');
    int cont = numCaracteres(texto);

    for(int i = 0; i < cont + 1; i++)
    {
        std::cout << texto[i];
    }

    return 0;
}
