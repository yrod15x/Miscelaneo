/* implement a solution to search a Student Record by implementing an
abstract data type that allows an arbitrary number of items to be stored
and individual records to be retrieved based on a key value.
A generic term for a structure that can efficiently store and retrieve
items based on a key value is a symbol table, and common
 implementations of the symbol table idea are hash tables*/

#include <iostream>
#include "studentRecord.h"
#include <cstdlib>
#include <ctime>
#include <string>

int nota()
{
    return (rand() % 100) + 0;
}

//Inicializar la tabla como un arreglo 2d para evitar las colisiones
studentRecord **iniciarlizar(int tamano)
{
    studentRecord **estudiantes = new studentRecord*[tamano];
    for(int i = 0; i < tamano; i++)
    {
        estudiantes[i] = new studentRecord[tamano];
        for(int j = 0; j < tamano; j++)
        {
            estudiantes[i][j].setGrade(0);
            estudiantes[i][j].setName("");
            estudiantes[i][j].setStudentID(-1);
        }
    }
    return estudiantes;
}
//Función de encriptacin simple
int hashear(std::string nombre, int tamLista)
{
    int contCar = 0;
    for(auto &s:nombre)
    {
        contCar++;
    }
    return contCar % tamLista;
}

void agregar(studentRecord **estudiantes, int tamano,
             std::string nombre, int nota, int id)
{
    //Evitar la colisión de indices. Avanzar uno si ya existen previos
    int index = 0;
    for(int i = 0; i < tamano; i++)
    {
        for(int j = 0; j < tamano; j++)
        {
           if(estudiantes[i][j].getName() != "") index++;
        }
    }

    int indexInterno = hashear(nombre, tamano);
    estudiantes[indexInterno][index].setGrade(nota);
    estudiantes[indexInterno][index].setStudentID(id);
    estudiantes[indexInterno][index].setName(nombre);
}

void encontrar(studentRecord **estudiantes, int tamano,
               std::string nombre)
{
    int index = hashear(nombre, tamano);

    for(int i = 0; i < tamano; i++)
    {
        if(estudiantes[index][i].getName() == nombre)
        {
            std::cout << estudiantes[index][i].getStudentID() << " "
            << estudiantes[index][i].getName()  << " "
            << estudiantes[index][i].getGrade() << "\n";
        }
    }
}

int main()
{
    srand(time(NULL));
    studentRecord **estudiantes = iniciarlizar(4);

    std::string nombres[] = {"Luis", "Prilar", "Kaope", "Xena"};
    int i = 0;

    while(i < 4)
    {
        agregar(estudiantes, 4, nombres[i], nota(), i + 1);
        i++;
    }

//    for(int i = 0; i < 4; i++)
//    {
//        for(int j = 0; j < 4; j++)
//        {
//            if(estudiantes[i][j].getName() != "")
//            {
//                std::cout << estudiantes[i][j].getName() << " >> "<<
//                estudiantes[i][j].getGrade() << '\n';
//            }
//        }
//    }
    encontrar(estudiantes, 4, "Xena");


    return 0;
}
