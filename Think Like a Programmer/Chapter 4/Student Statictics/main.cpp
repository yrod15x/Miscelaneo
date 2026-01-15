#include <iostream>
#include <cstdlib>

/* Write a program that processes an array of student objects and determines
the grade quartiles—that is, the grade one would need to score as well as or
better than 25% of the students, 50% of the students, and 75% of the students.*/

struct student
{
    char *name;
    double grade;
};

int compararPorNota(const void *a, const void *b)
{
    //Función que comapara dos elementos de una estructura para ser usada
    //dentro la función qsort()
    return ((student *)a)->grade - ((student *)b)->grade;
}

int numPorCiento(int numCuartil)
{
    if(numCuartil < 1 or numCuartil > 4) std::exit(1);

    int porciento = 25;

    switch(numCuartil)
    {
        case 2:
        porciento = 50;
        break;
        case 3:
        porciento = 75;
        break;
    }
    return porciento;
}

void mostrarNotaCuartil(student data[], int tam, int cuartil, int numCuartil)
{
    //Muestra las notas que necesirtan para estar en cada cuartil
    int porciento = numPorCiento(numCuartil);

    std::cout  << "Se necesita una nota de " << data[cuartil].grade
    << " para estar en el cuartil del " << porciento << "%\n";
}

void estadisticas(student data[], int tam, int notaCuartil, int numCuartil)
{
    int porciento = numPorCiento(numCuartil);
    for(int i = 0; i < tam; i++)
    {
        if(data[i].grade < notaCuartil)
            std::cout << data[i].name << " esta por debajo del quartil " << porciento << "%\n";
    }
}

int main()
{
    int tamano = 9;
    int cuartiles[] = {tamano / 4, tamano / 2, (tamano * 3) / 4};

    student estudiantes[] =
    {
        {"Luis", 78.4},
        {"Fred", 87},
        {"Tom", 28},
        {"Alistair", 100},
        {"Sasha", 78},
        {"Erin", 84},
        {"Belinda", 60},
        {"Leslie", 45},
        {"Candy", 70},
    };

    qsort(estudiantes, tamano, sizeof(student), compararPorNota);

    for(int i = 0; i < 3; i++)
    {
        mostrarNotaCuartil(estudiantes, tamano, cuartiles[i], i + 1);
        estadisticas(estudiantes, tamano, estudiantes[cuartiles[i]].grade, i + 1);
        std::cout << "\n";
    }


    return 0;
}
