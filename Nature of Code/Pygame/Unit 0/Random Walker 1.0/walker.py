"""Clase que crea un objeto Walker"""

from random import randint, random
import pygame

class Walker:
    """Creación de objetos tipo Walker"""
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y
    def walk(self):
        """El objeto se mueve a una dirección aleatoria"""

        #Caminar en 4 direcciones
        # step_dir = randint(0, 3)
        # if step_dir == 0:
        #     self.x += 1
        # elif step_dir == 1:
        #     self.x -= 1
        # elif step_dir == 2:
        #     self.y += 1
        # elif step_dir == 3:
        #     self.y -= 1
        #Caminar en 9 direcciones
        xstep: int = randint(-1, 1)
        ystep: int = randint(-1, 1)
        self.x += xstep
        self.y += ystep                  
    def show(self, window):
        """Muestra el objeto en pantalla """
        pygame.draw.circle(window, (0, 0, 0, 100), (self.x, self.y), 2)