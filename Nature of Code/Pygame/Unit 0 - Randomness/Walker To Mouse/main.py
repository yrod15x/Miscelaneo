import pygame, sys
from walker import Walker

pygame.init()

FPS: int = 30
fps_clock = pygame.time.Clock()

window = pygame.display.set_mode((800, 600))
pygame.display.set_caption('Go to the mouse')

BLANCO = (255, 255, 255)
window.fill(BLANCO)

walker: Walker = Walker(400, 300)

while True:

    #Mover el objeto a una velocidad constante sin importar la máquina
    time_passed = fps_clock.tick(FPS)
    seconds_passed = time_passed / 1000.0
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    walker.walk()        
    walker.show(window)
    pygame.display.update()

    fps_clock.tick(FPS)