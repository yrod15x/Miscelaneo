"""Programa que desplega un gráfico de barras sencillo, mostrando un los
elemento de un dictionario. El cual contiene las letras del alfabeto como 
llaves y cada valor es una lista, del mismo carácter repetido, de tamaño 
igual a al número de veces que aparece la letra en una cadena de texto 
ingresada por el usuario."""

def pedir_texto()-> str:
    """Devuelve una cadena de texto verificada pedida al usario
        Returns: 
            string: Cadena de texto verificada
    """
    text: str = input("Please, load the text >> ")
    return text
def crear_grafico(text: str)->dict[str:list[str]]:
    """Devuelve un diccionario con letras del alfabeto como llaves y cada 
        valor es una lista del mismo carácter repetido el número de veces
        que aparezcan en un texto.
        Arguments:
            sting: Cadena de texto a analizar
        Returns: 
            dict[str:list[str]] = Diccionario con las letras que se repiten.
    """
    grafico: dict[str:list[str]] = {}
    letras: str = "abcdefghijklmnñopqrstuvwxyz"
    for letra in text.lower():
        if letra in letras:
            #Permite agregar una llave con un valor si no existe en el dict
            grafico.setdefault(letra, [])
            for llave, valor in grafico.items():
                if llave == letra:
                    valor.append(letra)
    return grafico
def mostrar_grafico(grafico: dict[str:list[str]])-> None:
    """Muestra un diccionario con letras del alfabeto como llaves y cada 
        valor es una lista del mismo carácter repetido el número de veces
        que aparezcan en un texto.
        Arguments: 
            dict[str:list[str]] = Diccionario con las letras que se repiten.
    """
    for llave, valor in grafico.items():
        print(f"{llave}: ", end = "")
        for val in valor:
            print(val, end =" ")
        print()

texto: str = pedir_texto()
mostrar_grafico(crear_grafico(texto))
