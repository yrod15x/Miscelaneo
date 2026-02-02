"""Buscar parejas de palindromos en un archivo de texto - NURSES RUN"""
#En los palindromos en pareja una de la palbras una es el NUCLEO y la otra una secuencia palindromica
 
import cargarArchivo

def encuentra_palindromos_parejas():
    """Encuentra parejas de palindromos"""
    palabras_archivo = cargarArchivo.cargar('words.txt')
    lista_palindromos = []
    palabras = set(palabras_archivo) #se usa un set para que sea mas rapida la busqueda
    for pal in palabras:
        final = len(pal)                      #Determina los indices para rebanar la palabra
        palabra_reversa = pal[::-1]    #Reversar la palabra que va ser comparada como palindromo
        if final > 1:                            #No buscar palabras con una sola letra
            for i in range(final):           #Letras que formen palabra complemento del palindromo
                #Buscar si el nucleo del palindromo esta en la primera palabra
                #Agregar palabra (sliced) y su reversa (sliced) si esta ultima es palindromo.
                if pal[i:] == palabra_reversa[:final-i] and palabra_reversa[final-i:] in palabras:
                    lista_palindromos.append((pal, palabra_reversa[final-i:]))
                #Buscar si el nucleo del palindromo esta en la segunda palabra
                if pal[:i] == palabra_reversa[final-i:] and palabra_reversa[:final-i] in palabras:
                   lista_palindromos.append((palabra_reversa[:final-i], pal)) 
    return lista_palindromos

palindromos_par = sorted(encuentra_palindromos_parejas())

for nucleo, secuencia in palindromos_par:
    print(f'{nucleo} {secuencia}')