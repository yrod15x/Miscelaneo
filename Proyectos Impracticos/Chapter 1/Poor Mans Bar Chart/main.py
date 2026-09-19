"""Programa que desplega un gráfico de barras sencillo, mostrando un los
elemento de un dictionario. El cual contiene las letras del alfabeto como 
llaves y cada valor es una lista, del mismo carácter repetido, de tamaño 
igual a al número de veces que aparece la letra en una cadena de texto 
ingresada por el usuario."""

from googletrans import Translator
import asyncio 

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

def pedir_idioma()-> str:
    """Pide el idioma del texto entre algunas posibilidades
       Return:
            str: la abreviación del idioma.
    """
    idiomas: list[str] = ["en", "es"]
    mensaje: str = "Choose and type the abbreviation for the text to print >> "
    while True:
        print(*idiomas)
        idioma: str = input(mensaje)
        if idioma in idiomas:
            return idioma
        print("Incorrect Language")     
#Se debe usar programación asíncrona para que funcione el traductor
async def traducir(texto_a_traducir: str):
    """Traduce un texto a otro idioma.
        Arguments:
            str: Tetxto a traducir.
        Return:
            str: Texto traducido.
    """
    idioma: str = pedir_idioma()
    traductor = Translator()    
    texto_traducido: str = await traductor.translate(texto_a_traducir, dest=idioma)
    print(texto_traducido)
    return texto_traducido.text


texto: str = asyncio.run(traducir(pedir_texto()))
mostrar_grafico(crear_grafico(texto))
