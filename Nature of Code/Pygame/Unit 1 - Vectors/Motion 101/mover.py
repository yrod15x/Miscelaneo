"""Clase que genera una plantilla para que un objeto se mueva por pantalla
usando vectores. """

from random import randint
import pygame

class Mover():
    """Crea objetos que se mueven en pantalla usando vectores"""
    def __init__(self, width: int, height: int):
        self.__position = pygame.Vector2(width // 2, height // 2)
        self.__velocity = pygame.Vector2(randint(-2, 2), randint(-2, 2))
    def show(self, window):
        """Muestra el objeto en pantalla"""
        pygame.draw.circle(window, (50, 0, 0), self.__position, 40)
    def update(self):
        """Actualiza la posición del objeto basado en su velocidad"""
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
    def __repr__(self):
        return f"({self.__velocity.x}, {self.__velocity.y})"                             