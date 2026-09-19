"""Demuestra la substracción vectorial tomando la diferencia entre dos puntos: 
la posición del mouse y el centro de la ventana."""

import sys
import pygame

pygame.init()

fps: int = 60
fps_clock = pygame.time.Clock() 
fondo: tuple(int) = (51, 51, 51)
width: int = 1200
height: int = 800

window = pygame.display.set_mode((width, height))
pygame.display.set_caption("Vector Substraction")

while True:
    window.fill(fondo)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    raton = pygame.Vector2(pygame.mouse.get_pos())
    centro = pygame.Vector2(width // 2, height // 2)
    pygame.draw.line(window, (200, 200, 200), (0, 0), (raton.x, raton.y),2)
    pygame.draw.line(window, (200, 200, 200), (0, 0), (centro.x, centro.y), 2)         
    nuevo = raton - centro
    """nuevo es un vector relativo al origen (0, 0), no una posición absoluta de
    la ventana. Por eso, para trasladar el origen al centro, se debe sumar el 
    vector al punto inicial"""
    final = centro + nuevo
    pygame.draw.line(window, (200, 0, 200), (centro.x, centro.y),
    (final.x, final.y),2) 

    pygame.display.update()
    fps_clock.tick(fps)         
    