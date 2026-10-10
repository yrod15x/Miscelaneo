"""Clase con un objeto tipo globo de helio que sube y rebota con el tope de una
ventana. Si se oprime el mouse se simula la fuerza del viento aplicada al globo."""

from random import randint
import pygame

class Balloon():
    """Simula un objeto que sube con aceleración a un tope superior y rebota 
    con una fuerza inversa. Su movimiento horizontal puede ser afectado por otra 
    fuerza. """
    def __init__(self, width: int, height: int):
        self.__radio = 40
        self.__position = pygame.Vector2(randint(0, width), height - 40)
        self.__velocity = pygame.Vector2(0, 0)
        self.__acceleration = pygame.Vector2(0, 0)
        self.__top_speed = 2        
    def update(self):
        """Mueve el objeto por pantalla"""
        self.cap_speed()
        self.__acceleration.y = -0.01
        self.__velocity += self.__acceleration
        self.__position += self.__velocity
        #Se necesita reiniciar la aceleración para que puedan actuar varias fuerzas en el objeto
        self.__acceleration *= 0
    def cap_speed(self):
        """Limita la velocidad a un tope. length() es la magnitud"""
        if self.__velocity.length() > 2:
            self.__velocity = self.__velocity.normalize() * self.__top_speed
    def show(self, window):
        """Muestra el objeto en pantalla"""
        pygame.draw.circle(window, (255, 255, 0), self.__position, self.__radio)
    def check_borders(self, width):
        """Revisa que el objeto no se salga del borde"""
        if self.__position.y <= self.__radio:
            #Invierte la fuerza vertical y la aplica a la velocidad
            self.__acceleration.y = 1
            self.__velocity += self.__acceleration
        if self.__position.x > width:
            self.__position.x = 0
        elif self.__position.x < 0:
            self.__position.x = width
    def apply_force(self, force: pygame.Vector2):
        """Aplica una fuerza a la aceleración del objeto"""
        self.__acceleration += force        
