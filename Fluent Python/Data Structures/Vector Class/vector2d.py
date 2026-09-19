""" vector2d.py: una clase sencilla que demuestra algunos métodos especiales.
    Es simple por razones didácticas. Es un vector 2d que sobrecarga los 
    operadores +, * y valor absoluto."""

import math

class Vector:
    """Define una clase Vector 2D"""
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y
    def __repr__(self):
        #!r ayuda a mostrar el tipo de dato exacto al llamar al string 
        return f'Vector({self.x!r}, {self.y!r})'
    def __abs__(self):
        return math.hypot(self.x, self.y)
    def __bool__(self):
        #Revisa si el objeto es un vector si su magnitud es 0
        return bool(abs(self))
    def __add__(self, other):
        x = self.x + other.x
        y = self.y + other.x
        return Vector(x, y)
    def __mul__(self, scalar):
        return Vector(self.x * scalar, self.y * scalar)    
