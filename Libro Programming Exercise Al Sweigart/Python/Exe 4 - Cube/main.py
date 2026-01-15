"""Programa que genera un cubo en escala en pygame. Usa un slider para controlar 
su tamaño. Además se muestra sus dimensiones como área y perímetro."""

import sys
from math import sqrt
import pygame
import pygame_widgets
from pygame_widgets.slider import Slider

from functions import draw_grid, draw_cube, textosPantalla

pygame.init()

WIDTH, HEIGHT = 2400, 1400
WHITE, BLACK = (255, 255, 255), (0, 0, 0)
FPS = 30
fps_clock = pygame.time.Clock()
gap = 24
length = 24
object_gap = 100
start_point = pygame.Vector2(WIDTH // 2 - object_gap, HEIGHT// 2 + object_gap)
tam_fuente = 56


window = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Cube")
slider_width = 1000
slider_position = pygame.Vector2(WIDTH // 2 - (slider_width // 2), 
                                 HEIGHT - (object_gap + (object_gap // 2)))
slider = Slider(window, WIDTH // 2 - object_gap * 5, HEIGHT - object_gap - (object_gap // 2),
                slider_width, 40, min=0, max=120, step=1, colour=BLACK)

min_text_slider = textosPantalla('0', BLACK, WHITE, slider_position.x, slider_position.y + object_gap, 
                                 tam_fuente)
max_text_slider = textosPantalla('120', BLACK, WHITE, slider_position.x + slider_width, 
                                 slider_position.y + object_gap, tam_fuente)

while True:
    window.fill(WHITE)
    time_passed = fps_clock.tick(FPS)
    seconds_passed = time_passed / 1000.0
    events = pygame.event.get()
    for event in events:
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    draw_grid(window, gap, WIDTH, HEIGHT)
    cube_length = slider.getValue() 
    draw_cube(cube_length * 5, window, (0, 0, 0), start_point)
    #Textos en pantalla
    window.blit(min_text_slider[0], min_text_slider[1])
    window.blit(max_text_slider[0], max_text_slider[1])
    cube_length_text = textosPantalla("Length: " + str(cube_length), BLACK, WHITE,
                       object_gap * 3, object_gap * 4, tam_fuente)
    cube_area_text = textosPantalla("Area: " + str((cube_length * cube_length) * 6), 
                      BLACK, WHITE, object_gap * 3, object_gap * 5, tam_fuente)
    cube_volume_text = textosPantalla("Volume: " + str( cube_length * cube_length * cube_length), 
                      BLACK, WHITE, object_gap * 3, object_gap * 6, tam_fuente)
    cube_diagonal_text = textosPantalla("Diagonal: " + str(round(cube_length * sqrt(3), 2)), 
                      BLACK, WHITE, object_gap * 3, object_gap * 7, tam_fuente)
    cube_perimeter_text = textosPantalla("Perimeter: " + str(cube_length * 12), 
                      BLACK, WHITE, object_gap * 3, object_gap * 8, tam_fuente)
    window.blit(cube_length_text[0], cube_length_text[1])
    window.blit(cube_area_text[0], cube_area_text[1])
    window.blit(cube_volume_text[0], cube_volume_text[1])
    window.blit(cube_diagonal_text[0], cube_diagonal_text[1])
    window.blit(cube_perimeter_text[0], cube_perimeter_text[1])
    pygame_widgets.update(events)       
    pygame.display.update()
    fps_clock.tick(FPS)
  