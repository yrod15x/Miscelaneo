"""Muestra en forma de gráfico de barras la frecuencia de aparición de números 
aleatorios"""

import sys
from random import randint
import pygame

pygame.init()

FPS = 30
fps_clock = pygame.time.Clock()
WIDTH, HEIGHT = 1200, 800

ventana = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption('Distribución Números Aleatorios')

FONDO = (255, 255, 255)
total: int = 20
numeros: list[int] = [0 for i in range(total)]

while True:
    ventana.fill(FONDO)

    time_passed = fps_clock.tick(FPS)
    seconds_passed = time_passed / 1000.0
     
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    
    index_aleatorio: int = randint(0, total - 1)  
    numeros[index_aleatorio] += 2
    ancho: int = WIDTH / total
 
    for j in range(total):
        pygame.draw.rect(ventana, (127, 0, 0), 
        pygame.Rect(j * ancho, HEIGHT - numeros[j], ancho - 1, numeros[j]))    

    pygame.display.update()
    
    fps_clock.tick(FPS)