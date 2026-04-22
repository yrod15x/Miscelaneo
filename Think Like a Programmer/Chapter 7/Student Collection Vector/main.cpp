#include <iostream>
#include "studentCollection.h"

/* Rewrite our studentCollection functions from Chapter 4 (addRecord and
averageRecord) so that instead of directly implementing a linked list, you
use a class from the C++ library.*/

int main()
{
    studentCollection estudiantes;

    estudiantes.addRecord(3, "Leon", 78);
    estudiantes.addRecord(4, "Ana", 67);
    estudiantes.addRecord(1, "Luis", 45);
    estudiantes.addRecord(2, "Xena", 85);

    estudiantes.removeRecord(2);

    //estudiantes.showAllRecords();
    estudiantes.showRecord(4);

    studentCollection otros(estudiantes);
    otros.showAllRecords();

    return 0;
}
