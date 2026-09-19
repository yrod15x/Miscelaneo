"""Recrea un objeto rebotando contra las paredes utilizando Vectores"""

from random import randint
import sys
import pygame

pygame.init()

FPS = 60
clock = pygame.time.Clock()
background: tuple = (255, 255, 255)
WIDTH: int = 1200
HEIGHT: int =  800
ball_rad: int = 40 
position = pygame.Vector2(randint(ball_rad // 2, WIDTH - ball_rad // 2),
                          randint(ball_rad // 2, HEIGHT - ball_rad // 2))
velocity = pygame.Vector2(2, 2.5)
window = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Bouncing Ball")

while True:
    window.fill(background)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    if position.x > WIDTH - ball_rad // 2 or position.x < ball_rad // 2:
        velocity.x = -velocity.x
    if position.y > HEIGHT - ball_rad // 2 or position.y < ball_rad // 2:
        velocity.y = -velocity.y     
    pygame.draw.circle(window, (255, 0, 0), (position.x, position.y), 30)
    position += velocity
    pygame.display.update()
    clock.tick(FPS)        

