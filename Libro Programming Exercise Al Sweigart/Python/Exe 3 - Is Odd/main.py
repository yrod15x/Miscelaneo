"""Programa que expresa si un número es par o impar. Incluye funciones para 
establecer si un texto tiene igualmente un número es par o impar de carácteres"""

from random import randint

def is_even_odd(num: int) -> bool:
    """Programa que expresa si un número es par o impar
    Args: number (int): número entero
    Returns: bool: verdadero si par."""
    return num % 2 == 0

def print_info() -> None:
    """Imprime si un si un número es par o impar"""
    number = randint(1, 100000)
    if is_even_odd(number):
        print(f"{number} is and even number")
    else:
        print(f"{number} is and odd number")

for i in range(5):
    print_info()
