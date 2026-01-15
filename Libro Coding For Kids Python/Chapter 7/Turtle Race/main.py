"""Programa que pone varios sprites en pantalla y los mueve horizontalmente 
para ver cuál llega primero al final de la pantalla. (meta)"""

import pygame, sys

pygame.init()

FPS = 60
fps_clock = pygame.time.Clock()
WIDTH, HEIGHT = 2400, 1550

screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Turtle Race")

fondo = (0, 154, 23)

#4 corredores extraidos de una lista de imagenes cargadas del archivo.
racers = []
#Posciones iniciales y luego se aumenta en la coordenada y para situarlos
pos = pygame.Vector2(-50, 20)
pos_racers = [] 
for i in range(4):
    racer = []
    for i in range(24):
        racer.append(pygame.image.load(f"w{i}.png").convert_alpha())
    pos_racers.append((pos.x, pos.y))
    racers.append(racer)
    pos.y += 400


#Controla el indice de la imagen dentro de la lista (racer)
frame_index = 0


#Pistas
color_pista = (175, 98, 98)
pistas = []
offset_pista = 50
for i in range(4):
    pistas.append(pygame.Rect(0, offset_pista, WIDTH, 250))
    offset_pista += 400

while True:
    screen.fill(fondo)

    #Mover el objeto a una velocidad constante sin importar la máquina
    time_passed = fps_clock.tick(FPS)
    seconds_passed = time_passed / 1000.0

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    #Cambia el indice para ir cambiando la imagen cada cuadro. 
    #Cuando llega al tamano de la lista se reinicia (0)
    frame_index = (frame_index + 1) % len(racer)
    
    for pista in pistas:
        pygame.draw.rect(screen, color_pista, pista)
    for i in range(4):
        screen.blit(racers[i][frame_index], pos_racers[i])

    pygame.display.update()

    #pos_racer.x += 2

    fps_clock.tick(FPS)