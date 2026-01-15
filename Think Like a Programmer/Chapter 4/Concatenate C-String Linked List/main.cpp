#include <iostream>

/*Following up on the previous exercise, implement the concatenate function.
Note that if we make a call concatenate(s1, s2), where both parameters are
pointers to the first nodes of their respective linked lists, the function should
create a copy of each of the nodes in s2 and append them to the end of s1.
That is, the function should not simply point the next field of the last node in
s1’s list to the first node of s2’s list.*/

struct Cadena
{
    char caracter;
    Cadena *next;
};

typedef Cadena *Palabra;

void concadenar(Palabra &texto1, Palabra texto2)
{
    Cadena *actual = new Cadena;
    actual = texto1;

    while(actual->next != nullptr)
    {
        //std::cout << actual->caracter;
        actual = actual->next;
    }

    actual->next = texto2;
}

void mostrar(Palabra texto)
{
    Cadena *actual;
    actual = texto;

    while(actual != nullptr)
    {
        std::cout << actual->caracter;
        actual = actual->next;
    }
    std::cout << '\n';
}

int main()
{
    Palabra texto1, texto2;
    Cadena *nodot1 = new Cadena;
    Cadena *nodot2 = new Cadena;
    Cadena *nodot3 = new Cadena;
    Cadena *nodot4 = new Cadena;

    nodot1->caracter = 'a';
    nodot2->caracter = 'b';

    nodot3->caracter = 'c';
    nodot4->caracter = 'd';

    texto1 = nodot1;
    texto2 = nodot3;

    nodot1->next = nodot2;
    nodot2->next = nullptr;
    nodot3->next = nodot4;
    nodot4->next = nullptr;

    concadenar(texto1, texto2);

    mostrar(texto1);

    return 0;
}
