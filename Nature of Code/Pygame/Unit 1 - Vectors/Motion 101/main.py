"""Muestra un objeto que se mueve por la pantalla y aparece en el extremo
opuesto si desaparece por un lado"""

import sys
import pygame
from mover import Mover

pygame.init()

WIDTH: int = 1200
HEIGHT: int = 800
FPS = 60
fpf_clock = pygame.time.Clock()
background: tuple(int) = (51, 51, 51)

window = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Mover")

mover: Mover = Mover(WIDTH, HEIGHT)
print(mover)

while True:
    window.fill(background)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
            pygame.quit()

    mover.update()
    mover.check_edges(WIDTH, HEIGHT)
    mover.show(window)        

    pygame.display.update()
    fpf_clock.tick(FPS)        

