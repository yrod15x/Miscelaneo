""" Utiliza una distribución de probabilidad personalizada para variar el 
tamaño de un paso dado por el aleatorio Walker. El tamaño del paso puede
 determinarse influyendo en el rango de valores elegidos."""

import sys
import pygame
from walker import Walker

pygame.init()

FPS: int = 30
fps_clock = pygame.time.Clock()

window = pygame.display.set_mode((1200, 800))
pygame.display.set_caption("Big Steps Walker")

bg_color = (255, 255, 255)

walker: Walker = Walker(600, 400, 5)
window.fill(bg_color) 

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    walker.walk()
    walker.show(window)
    
    pygame.display.update()
    fps_clock.tick(FPS)