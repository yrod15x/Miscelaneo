"""Clase que representa un jugador de Piedra Papel Tijera."""

from random import choice

class playerRPS:
    """Clase que representa un jugador de Piedra Papel Tijera."""
    def __init__(self):
        self.__turns: list[str] = ["Rock", "Paper", "Scissors"]
        self.__score = 0
    def shoot(self)->str:
        return choice(self.__turns)
    def setScore(self, points: int):
        self.__score += points
    def getScore(self)->int:
        return self.__score
    