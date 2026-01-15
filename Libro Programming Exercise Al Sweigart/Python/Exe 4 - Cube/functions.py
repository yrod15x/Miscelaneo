"""Colección de funciones que ayudan a crear un cubo por pantalla"""

import pygame, sys

def draw_grid( screen: pygame.Surface,  gap: int, width: int, height: int)->None:
    """Función que permite crear una rejilla de lineas de color grisaseo.
    Args:
        width (int): ancho de la ventana
        height (int): altura de la ventana
        gap (int): espacio entre columnas y filas
        screen (pygame.Surface): ventana donde se dibujara la rejilla
    """
    for col in range(height // gap):
        for row in range(width // gap):
            pygame.draw.line(screen, (230, 230, 230), (row * gap, col), (row * gap, height))
            pygame.draw.line(screen, (230, 230, 230), (row , col * gap), (width, col * gap))
    return None

def draw_square(length: int, screen: pygame.Surface, color: tuple, start_point: pygame.Vector2)-> None:
    pygame.draw.line(screen, color,(start_point.x, start_point.y), (start_point.x, start_point.y - length), 2)
    pygame.draw.line(screen, color,(start_point.x, start_point.y - length), (start_point.x + length, start_point.y - length), 2)
    pygame.draw.line(screen, color,(start_point.x + length, start_point.y - length),(start_point.x + length, start_point.y),2)
    pygame.draw.line(screen, color, (start_point.x + length, start_point.y), (start_point.x, start_point.y), 2)
    
def draw_cube(length: int, screen: pygame.Surface, color: tuple, start_point: pygame.Vector2)-> None:
    #Cuadrado frontal
    draw_square(length, screen, color, start_point)
    target_point = pygame.Vector2((start_point.x - length // 2), (start_point.y + length // 2))
    #Cuadrado posterior
    draw_square(length, screen, color, target_point)
    #Línea conectora izquierda inferior
    pygame.draw.line(screen, color, start_point, target_point, 2)
    #Línea conectora derecha inferior
    pygame.draw.line(screen, color, (start_point.x + length, start_point.y), (target_point.x + length, target_point.y), 2)
    #Línea conectora izquierda superior
    pygame.draw.line(screen, color, (start_point.x, start_point.y - length), (target_point.x, target_point.y - length), 2)
    #Línea conectora derecha superior
    pygame.draw.line(screen, color, (start_point.x + length, start_point.y - length), (target_point.x + length, target_point.y - length), 2)

def textosPantalla(texto, color, fondo, pos_x, pos_y, tam_fuente):
    """Funcion que devuelve una lista con el renderizado del texto y su rectangulo"""
    #Renderizar el texto:  render(Mensaje, antilasing, color, color de fonfo)
    datos = []
    #Configurar la fuente y su tamano
    fuente = pygame.font.SysFont('Verdana', tam_fuente)
    #Rendizar el texto con su color y fondo(opcional)
    frase = fuente.render(texto, True, color, fondo)
    #Todo texto debe estar en un rectangulo .get_rect()
    frase_rect = frase.get_rect()
    #Configurar la posicion del rectangulo para ponerlo en pantalla
    frase_rect.center = (pos_x, pos_y)
    datos.append(frase)
    datos.append(frase_rect)
    return datos    