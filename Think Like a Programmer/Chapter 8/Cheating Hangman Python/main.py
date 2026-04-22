import re

palabras = """Or perhaps I should look for another structure entirely Now is also the
time for me to step back to see whether there are any opportunities to learn
new techniques in solving this problem I am wondering whether there are
specialized data structures that I have not yet considered that could be helpful
 Even if I end up sticking with my original choices I could learn a lot
from the investigation"""

def palabras_sin_letra(palabra: str, letra: str)-> list[str]:
    """Extrae todas las palabras que contengan una letra determinada"""
    return re.findall(rf"\b(?!\w*{re.escape(letra)}\w*)\w+\b", palabra)

def palabras_con_letra(palabra: str, letra: str)-> list[str]:
    """Extrae todas las palabras que contengan una letra determinada"""
    return re.findall(rf"\b\w*{re.escape(letra)}+\w*\b", palabra)

list_sin_letra: list[str] = []
list_con_letra: list[str] = []

while True:
    if len(list_con_letra) == 1 or len(list_sin_letra) == 1:
        break
    letra: str = input("Ingrese una letra >> ")
    list_sin_letra = palabras_sin_letra(palabras, letra)
    list_con_letra = palabras_con_letra(palabras, letra)
    if len(list_sin_letra) > len(list_con_letra):
        print(list_sin_letra)
        palabras = " ".join(list_sin_letra)
    else:
        print(list_con_letra)
        palabras = " ".join(list_con_letra)

