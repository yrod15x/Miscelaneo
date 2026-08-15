"""Crea un objeto que se desplaza aleatoriamente en pantalla con tendencia hacia.
a un lado específico, usando una clase Walker"""

import sys
import pygame
from walker import Walker

#Inicia todas elementos y acciones necesarias para que funcione Pygame
pygame.init()

#Estabilizar el juego a determinados FPS
FPS = 30
fps_clock = pygame.time.Clock()

#window donde se vera el juego - Con ancho de 800px y altura de 600px
window = pygame.display.set_mode((800, 600))
pygame.display.set_caption('Random Walker')

#Colores a usar
BLANCO = (255, 255, 255)
window.fill(BLANCO) 

#Variables
walker: Walker = Walker(400, 300)

#Loop principal donde se desarrolla la logica del juego y se dibujan los assests
while True:
    #Mover el objeto a una velocidad constante sin importar la máquina
    time_passed = fps_clock.tick(FPS)
    seconds_passed = time_passed / 1000.0

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    #Dibujar objetos
    walker.walk()
    walker.show(window)

    pygame.display.update() 
    fps_clock.tick(FPS)
