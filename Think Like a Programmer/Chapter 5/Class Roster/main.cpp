#include <iostream>
#include "studentRecord.h"

int main()
{
    studentRecord estudiante(50, 1, "Luis");
    std::cout << estudiante.letterGrade() << '\n';

    return 0;
}
