"""Representa un objeto circular que se mueve por el lienzo mediante
  vectores de posición, velocidad y aceleración. 
  La masa determina el radio del objeto. Las fuerzas aplicadas modifican
  su aceleración según la segunda ley de Newton (a = F / m)."""

from math import sqrt
from random import randint
import pygame  

class Mover:
    """Move un objeto por pantalla"""
    def __init__(self, mass: float, scr_width: int, scr_height: int):
      #Masa y radio determinan el tamano del objeto = pi*r^2. 100 para escalar
      self.__mass = mass
      self.__radio = sqrt(self.__mass * 200)
      self.__position = pygame.Vector2(randint(int(self.__radio), scr_width - int(self.__radio)),
      randint(int(self.__radio), scr_height // 2))
      self.__velocity = pygame.Vector2(0, 0)
      self.__acceleration = pygame.Vector2(0, 0)
    def apply_force(self, force: pygame.Vector2):
      """Modifica la aceleración mediante la sSegunda ley de Newton f=m*a"""
      temp_force = pygame.Vector2(0, 0)
      temp_force = force / self.__mass
      self.__acceleration += temp_force
    def update(self):
      """Mueve el objeto por pantalla"""
      self.__velocity += self.__acceleration
      self.__position += self.__velocity
      #Limpiar la aceleración para que no se acumule en el tiempo
      self.__acceleration *= 0
    def show(self, window: pygame.Surface):
      """Muestra el objeto en pantalla"""
      pygame.draw.circle(window, (23, 93, 173), self.__position, self.__radio)
    def check_edges(self, scr_width, scr_height):
      """El objeto no salga de los bordes, cambia la dirección de la velocidad"""
      if self.__position.x < self.__radio:
        self.__position.x = self.__radio
        self.__velocity.x *= -1
      elif self.__position.x > scr_width - self.__radio:
        self.__position.x = scr_width - self.__radio
        self.__velocity.x *= -1
      if self.__position.y < self.__radio:
        self.__position.y = self.__radio
        self.__velocity.y *= -1
      elif self.__position.y > scr_height - self.__radio:
        self.__position.y = scr_height - self.__radio
        self.__velocity.y *= -1                   