"""Carga un archivo de texto y lo regresa como una lista.
Argumentos: Archivo de texto (y su ruta si necesita)
Execepciones: IOError si no se encuntra el archivo
Devuelve: Una lista con todas las palabras del archvo en minusculas
Requiere: sys"""

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