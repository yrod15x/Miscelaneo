"""Encuentra Palindromos en un archivo de texto"""

import cargarArchivo

palabras = cargarArchivo.cargar('words.txt')
palindromos = []

for pal in palabras:
    if len(pal) > 1 and pal == pal[::-1]:
        palindromos.append(pal)

print(f'Se encontraron {len(palindromos)} palindromos en el archivo.')
#* Splat operator toma una lista y muestra su contenido sin brakets 
print(*palindromos)