"""Crea un objeto que recorre la pantalla aleatoriamente usando la clase
  Walker que usa el ruido de Perlin."""

import pygame
import noise
             
class Walker():
    """Crea un objeto que recorre la pantalla aleatoriamente 
    ruido de Perlin."""
    def __init__(self):
        self.tx = 0
        self.ty = 10000 
        self.x = 0
        self.y = 0     
    def walk(self):
        """Mueve el objeto con ruido Perlin"""           
        noise1 = (noise.pnoise1(self.tx) + 1) / 2
        noise2 = (noise.pnoise1(self.ty) + 1) / 2           
        self.x = noise1 * 1200
        self.y = noise2 * 800
        self.tx += 0.01
        self.ty += 0.015      
    def show(self, window):
        """Muestra el objeto en pantalla """
        pygame.draw.circle(window, (255, 0, 0), (int(self.x),
        int(self.y)), 10)
