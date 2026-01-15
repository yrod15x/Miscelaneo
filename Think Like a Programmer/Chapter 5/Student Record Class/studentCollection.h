#ifndef STUDENTCOLLECTION_H
#define STUDENTCOLLECTION_H
#include "studentRecord.h"

/* Clase que será una lista anidada que contendra registros estudiantiles.
Ejecuta tres acciones: agregar un estudiante, eliminarlo por medio de su id y
encontrar un registro también por su id*/

class studentCollection
{
    private:
        /*Unida estructural de la lista anidada. Debe ir primero como private
        porque varias funciones públicas harán referencia a ella. Contiene
        un objeto de otra clase studentRecord que tiene nombre, id y notas
        del estudiante*/
        struct studentNode
        {
            studentRecord studentData;
            studentNode *next;
        };
    public:
        studentCollection();
        studentCollection(const studentCollection &original);
        void addRecord(studentRecord newStudent);
        studentRecord recordWithNumber(int idNum);
        void removeRecord(int idNum);
        ~studentCollection();
        studentCollection& operator=(const studentCollection &rhs);

    private:
        //Crear la cabeza de la lista como un tipo de la estructura nodular
        typedef studentNode *studentList;
        studentList _listHead;
        void deleteList(studentList &listPtr);
        studentList copiedList(const studentList original);
};

#endif // STUDENTCOLLECTION_H
