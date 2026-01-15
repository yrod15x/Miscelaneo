/* Programa que toma una palabra o texto y ordena las letras alfabeticamente, evitando repeticones
    hola => ahlo
*/
#include <iostream>
#include <string>
#include <bits/stdc++.h>

void a_minuscula(std::string &texto)
{
    for(auto &i : texto)
    {
        i = tolower(i);
    }
}

void alfabetizar(std::string &texto)
{
    char temp;
    for(int i = 0; i < texto.size(); i++)
    {
        for(int j = 0; j < texto.size(); j++)
        {
            if(int(texto[i]) < int(texto[j]))
            {
                temp = texto[j];
                texto[j] = texto[i];
                texto[i] = temp;
            }
        }
    }
}

std::string ordenar(std::string texto)
{
    a_minuscula(texto);
    std::string ordenada;
    bool encontrada = false;

    for(auto car : texto)
    {
        for(auto orcar : ordenada)
        {
            if(car == orcar)
            {
                encontrada = true;
                break;
            }
            else
            {
                encontrada = false;
            }
        }
        if(car != ' ' && encontrada == false) ordenada.push_back(car);
    }
    alfabetizar(ordenada);
    return ordenada;
}

int main()
{
    std::cout << ordenar("La hora de la verdad");
    return 0;
}
