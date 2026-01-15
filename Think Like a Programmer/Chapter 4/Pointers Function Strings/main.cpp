/*P R O BL E M : V A R I A BL E - L E N G T H S T R I N G M A N I PU LA T I O N
Write heap-based implementations for three required string functions:
This function takes a string and a character and appends the character
to the end of the string.
concatenate This function takes two strings and appends the characters of the
second string onto the first.
characterAt This function takes a string and a number and returns the character
at that position in the string (with the first character in the string numbered zero).
append
Write the code with the assumption that characterAt will be called frequently,
while the other two functions will be called relatively seldom. The relative efficiency of
the operations should reflect the calling frequency.*/

#include <iostream>

//Crear un tipo propio basado en un tipo char (mirado como un array. De ahi el puntero)
//El arreglo debe terminar en NULL (0) para poder limitar su tamaño
typedef char *arrayTexto;

int tamano_texto(arrayTexto texto)
{
    //Devuelve el tamaño de una cadena de texto
    int cont = 0;
    while(texto[cont] != 0)
    {
        cont++;
    }
    return cont;
}

char charAt(arrayTexto texto, int indice)
{
    //Devuelve el caracter en la posición determinada por el parámetro indice
    return texto[indice];
}

void agregar(arrayTexto &texto, char caracter)
{
    //Agregar un caracter a un puntero tipo char (visto como array)
    int tamano = tamano_texto(texto);
    arrayTexto textocambiado = new char[tamano + 2];

    for(int i = 0; i < tamano; i++)
    {
        textocambiado[i] = texto[i];
    }
    textocambiado[tamano] = caracter;
    textocambiado[tamano + 1] = 0;
    delete[] texto;
    texto = textocambiado;
}

void concadenar(arrayTexto &texto1, arrayTexto texto2)
{
    int tam_texto1 = tamano_texto(texto1);
    int tam_texto2 = tamano_texto(texto2);
    int tam_texto_final = tam_texto1 + tam_texto2;
    arrayTexto temporal = new char[tam_texto_final + 1];

    for(int i = 0; i < tam_texto1; i++)
    {
        temporal[i] = texto1[i];
    }
    for(int i = 0; i < tam_texto2; i++)
    {
        temporal[tam_texto1 + i] = texto2[i];
    }
    temporal[tam_texto_final] = 0;
    delete[] texto1;
    texto1 = temporal;
}

int main()
{
    char *texto = new char[4];
    char *texto2 = new char[3];

    texto[0] = 'h'; texto[1] = 'o'; texto[2] = 'l'; texto[3] = 'a';
    texto2[0] = 'b'; texto2[1] = 'e'; texto2[2] = 't';

    std::cout << charAt(texto, 1) << '\n';
    agregar(texto, '!');
    std::cout << texto << '\n';
    concadenar(texto, texto2);
    std::cout << texto << '\n';
    return 0;
}
