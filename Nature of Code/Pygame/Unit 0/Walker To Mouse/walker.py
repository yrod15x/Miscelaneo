"""Clase que crea un objeto Walker que se desplazará a la posición del ratón."""

import pygame

class Walker:
    """Implementación de objetos tipo Walker"""
    def __init__(self, x: float, y: float):
        self.x = x
        self.y = y
    def walk(self):
        """El objeto se mueve hacia el mouse"""
        #Obtener la posición del mouse 
        pos_x, pos_y = pygame.mouse.get_pos()
        if pos_x > self.x:
            self.x += 1
        else:
            self.x -= 1
        if pos_y > self.y:
            self.y += 1
        else:
            self.y -= 1       
    def show(self, window):
        """Muestra el objeto en pantalla """
        pygame.draw.circle(window, (255, 50, 20), (self.x, self.y), 2)             
