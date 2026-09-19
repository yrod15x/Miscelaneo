"""Calcula la magnitud de un vector entre el ratón y el centro del canvas,
visualizándola como una barra en la parte superior de la pantalla."""

import sys
import pygame

pygame.init()

WIDTH: int = 1200
HEIGHT: int = 800
FPS: int = 60
FPS_CLOCK = pygame.time.Clock()
FONDO: tuple(int) = (51, 51, 51)

window = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Vector Maginitude")

while True:
    window.fill(FONDO)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    raton = pygame.Vector2(pygame.mouse.get_pos())
    centro = pygame.Vector2(WIDTH / 2, HEIGHT / 2)
    raton -= centro
    magnitud = raton.magnitude()
    rect = [0, 0, magnitud, 20]

    pygame.draw.rect(window, (255, 0, 0), rect)
    pygame.draw.line(window, (0, 255, 0), centro, raton + centro, 3)        

    pygame.display.update()
    FPS_CLOCK.tick(FPS)  
