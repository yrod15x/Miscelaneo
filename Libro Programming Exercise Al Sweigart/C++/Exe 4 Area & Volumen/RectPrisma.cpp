#include "cube.h"
#include <iostream>

void RectPrisma::_setMembers(double height, double length, double width)
{
   _length = length;
   _height = height;
   _width = width;
}

double checkPositives(double number)
{
    while(number < 0)
    {
        std::cout << "Data cannot be a negative number.\n Enter again >> ";
        std::cin >> number;
    }
    return number;
}

RectPrisma::RectPrisma()
{
    //Default constructor
    _setMembers(1.0, 1.0, 1.0);
}

RectPrisma::~RectPrisma()
{
    //Default destructor
}

RectPrisma::RectPrisma(const RectPrisma& other)
{
    //Copy constructor
    _setMembers(other._height, other._length, other._width);
}

RectPrisma::RectPrisma(double height, double length, double width)
{

    _setMembers(checkPositives(height), checkPositives(length), checkPositives(width));
}

double RectPrisma::findArea()
{
    return 2 * (_height * _width + _length * _height + _width * _height);
}

void RectPrisma::showRectPrismaInfo()
{
    std::cout << "The area is " << findArea() << '\n';
}
