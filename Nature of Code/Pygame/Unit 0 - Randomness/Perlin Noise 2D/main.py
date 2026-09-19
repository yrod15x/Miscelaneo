"""Programa que muestra por pantalla el efecto del ruído de Perlin en dos 
dimensiones (rejilla). Se toman todos los pixeles de la pantalla para cambiar
su color aleatoriamente."""

import sys
from random import randint
import pygame
import noise

pygame.init()

width, height = 1200, 800
FPS = 60
fps_clock = pygame.time.Clock()
background = (51, 51, 51)
window = pygame.display.set_mode((width, height))
pygame.display.set_caption("Perlin Noise 2D")
#Toma los pixeles de la pantalla
pixeles = pygame.PixelArray(window)
x_off = 0.0

window.fill(background)

while True:    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    for i in range(width):
        y_off = 0.0
        for j in range(height):
            noise1 = ((noise.pnoise2(x_off, y_off) + 1) / 2) * 255
            pixeles[i][j] = (noise1, randint(0, 255), randint(0, 255))
            y_off += 0.01
        x_off += 0.01            
    pygame.display.update()
    fps_clock.tick(FPS)        


