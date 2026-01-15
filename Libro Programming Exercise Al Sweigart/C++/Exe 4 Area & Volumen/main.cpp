/* Programa que usa una clase RectPrisma para hallar el área, el volumen y el perímetro
de un prisma rectángular o un cubo (todos sus lados iguales) */

#include <iostream>
#include "cube.h"

int main()
{
    RectPrisma cubo(4, 6, 8);

    cubo.showRectPrismaInfo();

    return 0;
}
