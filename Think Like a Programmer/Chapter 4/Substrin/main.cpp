/* For our dynamically allocated strings, create a function substring that takes
three parameters: an arrayString, a starting position integer, and an integer
length of characters. The function returns a pointer to a new dynamically
allocated string array. This string array contains the characters in the original
string, starting at the specified position for the specified length. The original
string is unaffected by the operation. So if the original string was abcdefg, the
position was 3, and the length was 4, then the new string would contain cdef.*/

#include <iostream>

typedef char *cadenaTexto;

cadenaTexto subCadena(cadenaTexto texto, int inicio, int fin)
{
    int cont = 0;
    while(texto[cont] != 0)
    {
        cont++;
    }
    if(fin > cont) fin = cont;
    cadenaTexto subTexto = new char[cont + 1];

    for(int i = inicio; i < fin; i++)
    {
        subTexto[i] = texto[i];
    }
    subTexto[cont] = 0;

    return subTexto;
}

void mostrarTexto(cadenaTexto texto, int tamano)
{
    for(int i = 0; i < tamano; i++)
    {
        std::cout << texto[i];
    }
    std::cout << '\n';
}

using namespace std;

int main()
{
    cadenaTexto texto = "Hello world!";
    int inicio = 1, fin = 6;
    cadenaTexto sub = new char[fin - inicio];

    sub = subCadena(texto, inicio, fin);
    mostrarTexto(sub, fin - inicio);

    delete[] sub;

    return 0;
}
