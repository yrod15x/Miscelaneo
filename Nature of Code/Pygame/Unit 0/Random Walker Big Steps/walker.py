""" Utiliza una distribución de probabilidad personalizada para variar el 
tamaño de un paso dado por el aleatorio Walker. El tamaño del paso puede
 determinarse influyendo en el rango de valores elegidos."""

from random import uniform, randint
import pygame

class Walker:
    """Crea un objeto (círculo) que recorre la pantalla en base movimientos
    aleatorios creados por un algoritmo de aceptación y rechazo. """
    def __init__(self, x, y, tam):
        self.__x = x
        self.__y = y
        self.__tam = tam
    def walk(self):
        """Actualiza la posición del objeto en pantalla"""
        step: float = self.__accept_reject()
        if step < 0.8:
            vel_x = randint(-10, 10)
            vel_y = randint(-10, 10)
        else:
            vel_x = randint(-1, 1)
            vel_y = randint(-1, 1)
        self.__x += vel_x
        self.__y += vel_y        
    def show(self, window):
        """Muestra el objeto en pantalla"""
        pygame.draw.circle(window, (51, 51, 51), (self.__x, self.__y), self.__tam)
    def __accept_reject(self)->float:
        """Algoritmo de aceptación y rechazo"""
        while True:
            r1: float = uniform(-1, 1)
            r2: float = uniform(-1, 1)
            if r2 < r1 * r1 / r2:
                return r1
