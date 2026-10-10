"""Clase que genera una plantilla para que un objeto se mueva por pantalla
usando vectores con una velocidad constante. """

from random import randint
import pygame

class Mover():
    """Crea objetos que se mueven en pantalla usando vectores"""
    def __init__(self, width: int, height: int):
        self.__size = 40
        self.__position = pygame.Vector2(randint(self.__size, width // 2), randint(self.__size, height // 2))
        self.__velocity = pygame.Vector2(0, 0)
        self.__acceleration = pygame.Vector2(-0.001, 0.01)
        self.__top_speed = 10
    def show(self, window):
        """Muestra el objeto en pantalla"""
        pygame.draw.circle(window, (150, 0, 0), self.__position, self.__size)
    def update(self):
        """Actualiza la posición del objeto basado en su velocidad"""
        self.__velocity += self.__acceleration
        self.limit()
        self.__position += self.__velocity
    def check_edges(self, width: int, height: int):
        """Hace que el objeto aparezca en el lado opuesto"""
        if self.__position.x > width:
            self.__position.x = 0
        elif self.__position.x < 0:
            self.__position.x = width
        if self.__position.y > height:
            self.__position.y = 0
        elif self.__position.y < 0:
            self.__position.y = height
    def limit(self):
        """Limita la velocidad a un tope. length() es la magnitud"""
        if self.__velocity.length() > self.__top_speed:
            self.__velocity = self.__velocity.normalize() * self.__top_speed         
    def __repr__(self):
        return f"({self.__velocity.x}, {self.__velocity.y})"                             
