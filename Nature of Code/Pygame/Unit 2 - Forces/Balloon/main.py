"""Mueve un objeto tipo globo de helio que sube y rebota con el tope de una
ventana. Si se oprime el mouse se simula la fuerza del viento aplicada al globo."""

import sys
from random import randint
import pygame
from balloon import Balloon


pygame.init()

FPS = 60
fps_clock = pygame.time.Clock()
bg_color = (51, 51, 51)
width: int = 1200
height: int = 800

window = pygame.display.set_mode((width, height))
pygame.display.set_caption("Balloon")

ballon = Balloon(width, height)
wind = pygame.Vector2(1, 0)

while True:
    window.fill(bg_color)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        if event.type == pygame.MOUSEBUTTONDOWN:
            #aplicar fuerza al presionar el mouse
            if pygame.mouse.get_pressed()[0]:
                #Randomizar la posición del viento
                win_dir: int = randint(0, 1)
                if win_dir == 0:
                    wind *= -1     
                ballon.apply_force(wind)  
    ballon.update()
    ballon.check_borders(width)
    ballon.show(window)        

    pygame.display.update()
    fps_clock.tick(FPS)             
