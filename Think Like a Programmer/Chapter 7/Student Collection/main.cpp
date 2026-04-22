#include <iostream>
#include "studentCollection.h"
#include "studentRecord.h"

int main()
{
    studentCollection estudiantes;
    studentRecord r1(87, 1, "Gonch");
    studentRecord r2(97, 2, "Berb");

    estudiantes.addRecord(r1);
    estudiantes.addRecord(r2);
    estudiantes.setFirstStudentPolicy(higherGrade);

    std::cout << estudiantes.firststudent().getName();

    return 0;
}
