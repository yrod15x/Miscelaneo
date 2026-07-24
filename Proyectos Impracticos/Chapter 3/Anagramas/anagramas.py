"""Programa que detecta si una palabra ingresada por el usuario es un anagrama
comparándola con una lista de palabras cargadas de un archivo"""

import sys

def cargar(archivo:str)->list:
    """Abre un archivo y devuelve una lista de palbras en minusculas"""
    try:
        with open(archivo) as in_file:
            palabras = in_file.read().strip().split('\n')
            palabras = [p.lower() for p in palabras]
            return palabras
    except IOError as e:
        print(f"{e}\n Abriendo {archivo}. Cerrando el programa.")
        sys.exit(1)

def hallar_anagramas(lista: list[str], dato:str)-> list:
    """Compara una palabra con una lista otras palabras para deterinar si
        hay anagramas. Devuelve una lista con las posibles coincidencias.
        Param: lista -> array de cadenas de texto.
               dato -> Cadena de texto a comparar.
        Return: Lista vacia o con palabras que son anagramas del parámetro dato."""
    anagramas: list[str] = []
    temp_data = dato
    temp_pal: str = ""
    for pal in palabras:
        temp_pal = pal.lower()  
        if len(pal) != len(dato):
            continue
        temp_pal = sorted(list(temp_pal))
        temp_data = sorted(list(temp_data))
        if temp_pal == temp_data:
            anagramas.append(pal)
    return anagramas        


entrada: str = input("Ingrese una palabra >> ")
palabras: list[str] = cargar("words.txt")

print(hallar_anagramas(palabras, entrada))      