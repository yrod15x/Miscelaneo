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
    if(_height == _width && _width == _length) return 6 * (_length * _length);
    return 2 * (_height * _width + _length * _height + _width * _height);
}

double RectPrisma::findPerimeter()
{
    if(_height == _width && _width == _length) return 12 * _length;
    return 2 * (_length * _width);
}

double RectPrisma::findVolume()
{
    if(_height == _width && _width == _length) return (_length * _length * _length);
    return 2 * (_length * _width * _height);
}

void RectPrisma::showRectPrismaInfo()
{
    std::cout << "The surface area is " << findArea() << '\n';
    std::cout << "The perimeter is " << findPerimeter() << '\n';
    std::cout << "The volume is " << findVolume() << '\n';
}
