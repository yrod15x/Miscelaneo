import pygame, sys
from random import randint
from time import time
from cell import Cell

pygame.init()

FPS = 30
fps_clock = pygame.time.Clock()
WIDTH, HEIGHT = 1660, 1160

window = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Fizz Buzz")
background = (255, 255, 255)
size = WIDTH // 10
gap = 20
squares = []

#Crear un rectángulo que vaya pasando por cada celda de la grilla
rect_eval_x, rect_eval_y = 0, 0

#Crear grilla rectangulos
def make_grid(size_grid: int, cell_size: int)-> list:
    grid = []
    for col in range(size_grid):
        rect_rows = []
        for row in range(size_grid):
            rect_rows.append(Cell(cell_size, size * row, col * cell_size,
            (0, 0, 0), str((row + 1) + (col * size_grid)) , 80))
        grid.append(rect_rows)
    return grid

squares = make_grid(10, size)

while True:

    window.fill(background)

    time_passed = fps_clock.tick(FPS)
    seconds_passed = time_passed / 1000.0
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    #Dibujar la grilla    
    for square in squares:
        for sq in square:
            sq.show(window)
    #El rectángulo evaluador se va dibujando en cada celda
    pygame.draw.rect(window, (0, 0, 0), (rect_eval_x, rect_eval_y, size, size))
    for square in squares:
        #Evaluar cada celda a ver si hace Fizz Buzz
        for sq in square:
            if sq.position.x == rect_eval_x and sq.position.y == rect_eval_y:
                sq.fizz_buzz()
    
    pygame.display.update()

    #Moviemnto del rectángulo por toda la grilla. Baja filas al llegar
    # a la última columna. Sube al llegar final de la grilla
    rect_eval_x += size
    if rect_eval_x >= WIDTH:
        rect_eval_x = 0
        rect_eval_y += size
        if rect_eval_y >= HEIGHT:
            rect_eval_y = 0
            #reiniciar la grilla
            squares = make_grid(10, size)
    
    pygame.time.wait(1000)
       
    fps_clock.tick(FPS)
