#include <iostream>
#include "studentRecord.h"
#include <vector>
#include <algorithm>

/* Consider a collection of studentRecord objects. We want to be able to quickly
find a particular record based on student number. Store the student records
in an array, sort the array by student number, and investigate and implement
the interpolation search algorithm.*/

int interpolationSearch(studentRecord arr[], int lo, int hi, int x)
{
    int pos;
    // Since array is sorted, an element present
    // in array must be in range defined by corner
    if (lo <= hi && x >= arr[lo].getStudentID() && x <= arr[hi].getStudentID()) {
        // Probing the position with keeping
        // uniform distribution in mind.
        pos = lo + (((double)(hi - lo) / (arr[hi].getStudentID()
                 - arr[lo].getStudentID()))
                 * (x - arr[lo].getStudentID()));
        // Condition of target found
        if (arr[pos].getStudentID() == x)
            return pos;
        // If x is larger, x is in right sub array
        if (arr[pos].getStudentID() < x)
            return interpolationSearch(arr, pos + 1, hi, x);
        // If x is smaller, x is in left sub array
        if (arr[pos].getStudentID() > x)
            return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1;
}


int main()
{
    studentRecord alumno1(56, 1, "Luis");
    studentRecord alumno2(76, 2, "Ana");
    studentRecord alumno3(96, 4, "Luna");

    std::vector<studentRecord> estudiantes;
    estudiantes.push_back(alumno1);
    estudiantes.push_back(alumno2);
    estudiantes.push_back(alumno3);

    std::sort(estudiantes.begin(), estudiantes.end());

    for(studentRecord &rec:estudiantes)
    {
        std::cout << rec.getName() << '\n';
    }

    studentRecord estudiantes2[3];
    estudiantes2[0] = alumno1;
    estudiantes2[1] = alumno2;
    estudiantes2[2] = alumno3;

    int pos = interpolationSearch(estudiantes2,0, 3, 2);
    std::cout << estudiantes2[pos].getName() << '\n';

    return 0;
}
