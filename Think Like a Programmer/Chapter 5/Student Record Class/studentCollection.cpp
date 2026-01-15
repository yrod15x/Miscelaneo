#include "studentCollection.h"
#include "studentRecord.h"

studentCollection::studentCollection()
{
    //La lista esta vacia
    _listHead = nullptr;
}

studentCollection::~studentCollection()
{
    //Devuelve la memoria asignada por new y los punteros
    deleteList(_listHead);
}

//Constructor de copia
studentCollection::studentCollection(const studentCollection &original)
{
    _listHead = copiedList(original._listHead);
}

void studentCollection::addRecord(studentRecord newStudent)
{
    //Declarar un nodo tempora. Asignarle los datos.
    studentNode *newNode = new studentNode;
    newNode->studentData = newStudent;
    //Apuntarlo a la que era la cabeza de la lista
    newNode->next = _listHead;
    //Volver a poner la cabeza al inicio
    _listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int idNum)
{
    /*Devuelve el registro del estudiante con ese id. Si no lo encuentra
    Se devuelve un registro de valor inavalido*/
    studentNode *temp = _listHead;
    while(temp != nullptr && temp->studentData.getStudentID() != idNum)
    {
        temp = temp->next;
    }
    if(temp == nullptr)
    {
        studentRecord incorrecto(-1, -1, "");
        return incorrecto;
    }
    return temp->studentData;
}

void studentCollection::removeRecord(int idNum)
{
    /* Cuando se elimina un nodo se deben monitorear los siguientes aspectos:
        1. Si hay un sólo nodo se borra y se devuelve null  (o una lista vacia)
        2. Si se borra el primer nodo se debe conectar la cabeza de la lista
        al segundo nodo y quedar como cabeza.
        3. Si es un nodo intermedio se debe guardar el nodo previo y luego
        conectarlo al siguiente nodo que seguia al que se va a borrar*/

        //Nodo que recorrera toda la colección. Apuntarlo al inicio
        studentNode *target = _listHead;
        //Nodo que rastreara al previo. Comienza vacio
        studentNode *previous = NULL;

        //Recorrer la colección hasta encontrar o no el objetivo
        while(target != nullptr && target->studentData.getStudentID() != idNum)
        {
            //Almacenar el previo
            previous = target;
            //Pasar al siguiente nodo
            target = target->next;
        }

        //Lista Vacia
        if(target == nullptr) return;
        //Borrar el primer nodo. EL segundo queda como cabeza
        if(previous == nullptr)
        {
            _listHead = _listHead->next;
        }//Borrar nodo intermedio. Hacer las nuevas conexiones
        else
        {
            previous->next = target->next;
        }
        delete target;
}
//Ayuda al destructor
void studentCollection::deleteList(studentList& listPtr)
{
    while(listPtr != nullptr)
    {
        studentNode * temp = listPtr;
        listPtr = listPtr->next;
        delete temp;
    }
}

/*Evitar hacer una copia llana.  Devuelve una copia de otra colleccion
Ayuda a sobrecargar el operador = */
studentCollection::studentList studentCollection::copiedList(const studentList original)
{
    //Si la lista esta vacia devuelve vacio también
    if(original == nullptr) return nullptr;
    //Crear la lista nueva a devolver
    studentList newList = new studentNode;
    //Copiar la cabeza para ir anexando los siguientes nodos
    newList->studentData = original->studentData;
    //Nodo temp que recorre la lista a copiar. Inicia en el 2do nodo (1ero ya se copió)
    studentNode *orgTemporal = original->next;
    //Nodo temp que se  irá copiando apunta al primero nodo ya copiado
    studentNode *newTemporal = newList;

    //Mientras no se llegue al final de la lista original
    while(orgTemporal != nullptr)
    {
        //El nodo (2do, 3ro) ste a copiar debe iniciarse vacio y luego avanzarlo
        newTemporal->next = new studentNode;
        newTemporal = newTemporal->next;
        //Copiar los datos al nodo nuevo vacio
        newTemporal->studentData = orgTemporal->studentData;
        //Avanzo al ste del original
        orgTemporal = orgTemporal->next;
    }
    //Llegar al final y asignar la cola
    newTemporal->next = nullptr;
    return newList;
}

studentCollection& studentCollection::operator=(const studentCollection &rhs)
{
    //Si los punteros no soniguales
    if(this != &rhs)
    {
        //Evitar fuga de memoria
        deleteList(_listHead);
        //Copiar los nodos
        _listHead = copiedList(rhs._listHead);
    }
    //Devuelve la colección copiada
    return *this;
}
