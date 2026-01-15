/*With qsort, write code that uses the function to sort an array of our student
struct. First have it sort by grade, and then try it again using the student ID.

qsort(lista, cantidaElementos, tamanoDato - use sizeof() - funcionComparativa)
int funcComaparativa(const void * voidA, const void * voidB)
{
    int * intA = (int *)(voidA);
    int * intB = (int *)(voidB);
    return *intA - *intB;
}

*/

#include <iostream>
#include <string>
#include <cstdlib>

struct student
{
    const char *name;
    int id;
    float finalGrade;
};

int comparar(const void *a, const void *b)
{
    //Función necesaria para que qsort compare y ordene los elementos del arreglo
    int *item1 = (int *)(a);
    int *item2 = (int *)(b);
    return *item1 - *item2;
}

int compareById(const void *a, const void *b)
{
    //Función que comapara dos elementos de una estructura para ser usada
    //dentro la función qsort()
    return ((student*)a)->id - ((student*)b)->id;
}

int compareByGrade(const void *a, const void *b)
{
    return ((student *)b)->finalGrade - ((student *)a)->finalGrade;
}

void mostrarInfo(student students[], int tam)
{
    for(int i = 0; i < 3; i++)
    {
        std::cout << students[i].name << " - " << students[i].id << " - "
        << students[i].finalGrade << '\n';
    }
}

int main()
{
    int numeros[] = {3, 8, 9, 0, 2, 34, 12, 5};
    student students[] = {{"uno", 1, 23}, {"tres", 3, 53}, {"dos", 2, 93}};

    std::cout << "Ordenado por ID "<< '\n';
    qsort(students, 3, sizeof(student), compareById);
    mostrarInfo(students, 3);

    std::cout << '\n' << "Ordenado por Nota Final "<< '\n';
    qsort(students, 3, sizeof(student), compareByGrade);
    mostrarInfo(students, 3);

    return 0;
}
