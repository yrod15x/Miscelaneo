"""Crea un objeto que recorre la pantalla aleatoriamente usando la clase
  Walker que usael ruido de Perlin."""

from walker import Walker
import sys
import pygame

pygame.init()

FPS: int = 30
fps_lock = pygame.time.Clock()
background: tuple(int) = (255, 255, 255)
WIDTH: int = 1200
HEIGHT: int = 800

window = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Perlin Walker")
window.fill(background)
walker = Walker()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    walker.walk()
    walker.show(window)
    pygame.display.update()
    fps_lock.tick(FPS)        



