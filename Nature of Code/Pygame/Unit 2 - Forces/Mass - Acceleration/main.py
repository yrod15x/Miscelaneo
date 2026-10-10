""" Simulación de objetos en un lienzo de 1200 × 800 en pygame.
 *
 * En cada fotograma, aplica gravedad proporcional a la masa de cada objeto
 * para que todos caigan con la misma aceleración. Mientras el mouse está
 * presionado, también aplica una fuerza de viento hacia la derecha. Los
 * objetos actualizan su movimiento, comprueban los límites del lienzo y se
 * dibujan sobre un fondo gris oscuro.
 *
 * Requiere la biblioteca mover.py y una clase `Mover` que implemente los métodos
 * `apply_force()`, `check_edges()`, `update()` y `show()`."""

from mover import Mover
from random import randint
import pygame, sys

pygame.init()

FPS = 60
width: int = 1200
height: int = 800
fps_clock = pygame.time.Clock()

window = pygame.display.set_mode((width, height))
pygame.display.set_caption('Gravity Bouncing Objects')
bg_color = (255, 255, 255)

num_objects: int = randint(1, 5) 
masses: list[int] = [randint(1, 10) for i in range(num_objects)]
movers: list[Mover] = [Mover(masses[i], width, height) for i in range(num_objects)]
gravity: pygame.Vector2 = pygame.Vector2(0, 0.5)
wind: pygame.Vector2 = pygame.Vector2(0, 0)

while True:
    window.fill(bg_color)     
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        if event.type == pygame.MOUSEBUTTONDOWN:
            #aplicar fuerza al presionar el mouse
            if pygame.mouse.get_pressed()[0]:
                if pygame.mouse.get_pos()[0] < width / 2:
                    wind.x = 1
                elif pygame.mouse.get_pos()[0] > width / 2:
                    wind.x = -1    
                     
    for index, mover in enumerate(movers):        
    #Escalar la gravedad a la masa del objeto.Soltar 2 objetos deben caer igual.
        temp_gravity: pygame.Vector2 = pygame.Vector2(0, 0) 
        temp_gravity = gravity * masses[index]
        mover.apply_force(temp_gravity)
        mover.apply_force(wind)
        mover.update()
        mover.check_edges(width, height)
        mover.show(window)

    pygame.display.update()
    fps_clock.tick(FPS)
   