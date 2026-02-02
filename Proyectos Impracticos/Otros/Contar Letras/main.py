#Cuenta y muestra el numero de cada letra del alfabeto que hay en un texto.

def contar_letras(text:str, letra:str)->int:
    """Cuenta numero de letras en un texto"""
    suma = 0
    for tex in text:
        if tex == letra:
            suma += 1
    return suma

TEXTO = """For each dataset, you should generate one line of output with the following
values: The dataset number as a decimal integer (start counting at one), a space, and the misspelled string. The misspelled string is the input string with the indicated character
deleted."""

ALFABETO= 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'

for t in ALFABETO:
    sum = contar_letras(TEXTO, t)
    if sum != 0:
        print(t, end=": ")
        for i in range(sum):
            print(t, end="")
        print()
