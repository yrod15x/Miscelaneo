"""Muestra la distribución gausiana (randomGaussian()) poniendo varios círculos
 en pantalla."""

from random import gauss, randint
import sys
import pygame

pygame.init()

FPS = 30
fps_clock = pygame.time.Clock()

window = pygame.display.set_mode((1200, 800))
pygame.display.set_caption("Gaussian Distribution")
window.fill((0, 0, 0))
radius = 30 

while True:  
    seconds_passed = fps_clock.tick(FPS) / 1000.0
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()  
    posX: float  = gauss(520, 160)
    #Pygame no acepta alpha en la figura, se necesita crear una superfice, hacerla
    # transparente y poner la figura encima de ella. 
    circle_surf = pygame.Surface((radius * 2, radius * 2), pygame.SRCALPHA)
    pygame.draw.circle(circle_surf, (randint(0, 255), randint(0, 255), randint(0, 255), 10),
                      (radius, radius), radius)
    window.blit(circle_surf, (posX - radius, 380 - radius))

    pygame.display.update()
   
