"""Clase que genera una plantilla para que un objeto se mueva por pantalla
hacia la dirección del mouseusando vectores con una velocidad influida por
una aceleración aleatoria."""

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

movers:list[Mover] = []

for i in range(5):
    movers.append(Mover(WIDTH, HEIGHT))


while True:
    window.fill(background)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
            pygame.quit()

    for mover in movers:
        mover.update()
        mover.check_edges(WIDTH, HEIGHT)
        mover.show(window)        

    pygame.display.update()
    fpf_clock.tick(FPS)        

