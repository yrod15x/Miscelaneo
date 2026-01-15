/* Change the implementation of our strings such that location[0] in the array
stores the size of the array (and therefore location[1] stores the first actual
character in the string), rather than using a null-character terminator.
Implement each of the three functions, append, concatenate, and charactertAt,
taking advantage of the stored size information whenever possible. Because
we’ll no longer be using the null-termination convention expected by the
standard output stream, you’ll need to write your own output function that
loops through its string parameter, displaying the characters.*/

#include <iostream>

typedef char *cadenaTexto;

void mostrar(cadenaTexto cadena)
{
    for(int i = 1; i <= cadena[0]; i++)
    {
        std::cout << cadena[i];
    }
    std::cout << '\n';
}


char caracterEn(const cadenaTexto cadena, int indice)
{
    return cadena[indice + 1];
}

void agregar(cadenaTexto &cadena, char c)
{
    int tamano = cadena[0] + 1;
    cadenaTexto temp = new char[tamano];
    temp[0] = tamano;

    for(int i = 1; i < cadena[0]; i++)
    {
        temp[i] = cadena[i];
    }

    temp[tamano] = c;
    delete[] cadena;
    cadena = temp;
}


void concadenar(cadenaTexto &original, cadenaTexto cadena)
{
    int nuevoTam = original[0] + cadena[0];
    cadenaTexto temporal = new char[nuevoTam];

    temporal[0] = nuevoTam;

    for(int i = 1; i <= original[0]; i++)
    {
        temporal[i] = original[i];
    }
    for(int i = 1; i <= cadena[0]; i++)
    {
        temporal[i + original[0]] = cadena[i];
    }

    delete[] original;
    original = temporal;
}


int main()
{
    int tamano = 6;
    cadenaTexto prueba = new char[tamano];
    prueba[0] = tamano; prueba[1] = 'a'; prueba[2] = 'd';
    prueba[3] = 'i'; prueba[4] = 'o'; prueba[5] = 's';

    cadenaTexto anexo = new char[3];
    anexo[0] = 3; anexo[1] = 'd'; anexo[2] = 'o';

    std::cout << caracterEn(prueba, 2) << '\n';

    agregar(prueba, '!');
    mostrar(prueba);

    concadenar(prueba, anexo);
    mostrar(prueba);

    delete[] prueba;
    return 0;
}
