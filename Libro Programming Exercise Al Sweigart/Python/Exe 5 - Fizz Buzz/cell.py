"""Clase que genera rectángulos enpantalla con un texto dentro 
(número o letra) y posee la lógica del juego FizzBuzz."""

import pygame

class Cell():
    """genera rectángulos enpantalla con un texto dentro (número o letra)"""
    def __init__(self, side: int, pos_x: int, pos_y, color: tuple, text: str, font_size: int):
        self.side = side
        self.position = pygame.math.Vector2(pos_x, pos_y)
        self.color = color
        self.text = text
        self.font_color = (0, 0, 0)
        self.font_size = font_size
        self.font = pygame.font.SysFont("Verdana", self.font_size, True)
    def fizz_buzz(self):
        if self.text != "F" or self.text != "B" or self.text != "FB":
            if int(self.text) % 15 == 0:
                self.font_color = (255, 165, 0)
                if ord(self.text[0]) >= 48 and ord(self.text[0]) <= 57:
                    self.text = "FB"
            elif int(self.text) % 3 == 0:
                self.font_color = (0, 255, 0)
                if ord(self.text[0]) >= 48 and ord(self.text[0]) <= 57:
                    self.text = "F"
            elif int(self.text) % 5 == 0:
                self.font_color = (255, 0, 0)
                if ord(self.text[0]) >= 48 and ord(self.text[0]) <= 57:
                    self.text = "B" 
    def show(self, screen):
        escala: int = 2
        self.square_text = self.font.render(self.text, True, self.font_color)
        #rectángulo tiene el último parámetro 1 para que remarcar el boder
        #Dar la ilusión de (junto con el fondo de pantalla) enmarcado
        pygame.draw.rect(screen, self.color, pygame.Rect(self.position.x, self.position.y,
        self.side, self.side), 1)
        #Para que los números de dos cifras queden centrados en comparación a los unidigitos
        if len(self.text) == 1:
            escala = 4
        screen.blit(self.square_text, (self.position.x + (self.side / 2) - (self.font_size / escala), 
        self.position.y + (self.side / 2) - (self.font_size / 2)))