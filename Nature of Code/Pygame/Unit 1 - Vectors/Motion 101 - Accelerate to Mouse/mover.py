"""Clase que genera una plantilla para que un objeto se mueva por pantalla
hacia la dirección del mouseusando vectores con una velocidad influida por
una aceleración aleatoria."""

from random import randint, uniform
import pygame

class Mover():
    """Crea objetos que se mueven en pantalla usando vectores"""
    def __init__(self, width: int, height: int):
        self.__size = 40
        self.__position = pygame.Vector2(randint(self.__size, width // 2), randint(self.__size, height // 2))
        self.__velocity = pygame.Vector2(0, 0)
        self.__acceleration = pygame.Vector2(0, 0)
        #Variable que permite virar y acelear hacia al mouse
        self.__dir = pygame.Vector2(0, 0)
        self.__top_speed = 10
        self.__color: tuple(int) = (randint(0, 255), randint(0, 255), 0)
        self.__scale = uniform(0, 1)
    def show(self, window):
        """Muestra el objeto en pantalla"""
        pygame.draw.circle(window, self.__color, self.__position, self.__size)
    def update(self):
        """Actualiza la posición del objeto basado en su velocidad"""
        mouse = pygame.Vector2(pygame.mouse.get_pos())
        #calcular la dirección para que se mueva hacia el mouse
        self.__dir = mouse - self.__position
        #Normailizar y escalar
        self.__dir = self.__dir.normalize() * self.__scale        
        self.__acceleration = self.__dir
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
