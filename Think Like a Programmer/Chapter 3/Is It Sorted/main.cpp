/* Write a bool function that is passed an array and the number of elements in
that array and determines whether the data in the array is sorted. This should
require only one pass!*/

#include <iostream>

bool isItSorted(int numbers[], int listSize)
{
    for(int i = 0; i < listSize - 1; i++)
    {
        if(numbers[i] > numbers[i+1]) return false;
    }
    return true;
}

void showInfo(int numbers[], int listSize)
{
    (isItSorted(numbers, listSize)) ? std::cout
    << "Sorted\n" : std::cout << "Not Sorted\n";
}

int main()
{
    int tam = 4;
    int numList[tam] = {7, 8, 9, 10};

    showInfo(numList, tam);

    return 0;
}
