Programa que decifra un mensaje escrito en digitos  enterso separados por espacios u otro
símbolo. Pero se leen comotipo carácter. Se van procesando uno a uno y se formán números más
grandes si son registrados así. La decodificación se efectua dependiendo de tres modos:
mayúsculas, minúsculas y signos de puntación. Si son los dos primeros modos, el número se
divide por 27 y su remante se toma como la letra correspodiente en su orden en el alfabeto
(a -> 1, b -> 2 ...) Dependiendo del modo o estado en  que se halle el programa. Si el remanente
 es cero (0) se cambia de modo: de mayúscula a minúsculas y de la útlma a puntuación. Si el
número dividido por 9 es cero, y se está en modo puntuación se pasa de este a mayúsculas.
Los signos de puntuación se obtienen del restante de dividir el número entre 9 y se mira una
tabla con correspondencias de signo a números.
