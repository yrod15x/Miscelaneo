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
        step_dir = randint(1, 100)
        if step_dir < 50:
            self.x += 1
            self.y -= 1
        elif step_dir < 60:
            self.x -= 1
            self.y -= 1
        elif step_dir < 70:
            self.y += 1
            self.x += 1
        else:
            self.y += 1
            self.x -= 1
        
                         
    def show(self, window):
        """Muestra el objeto en pantalla """
        pygame.draw.circle(window, (0, 0, 0, 100), (self.x, self.y), 2)
