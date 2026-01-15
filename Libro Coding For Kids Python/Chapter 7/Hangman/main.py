from random import randint

def extraer_elemento(elementos: dict) -> list[str]:
    escogido: int = randint(1, len(elementos))
    cont: int = 1
    info: list[str] = []
    for key, value in elementos.items():
        if cont == escogido:
            info.append(key)
            info.append(value[randint(1, len(value))-1])
            break
        cont += 1
    return info

def generar_espacios(palabra:str)-> str:
    espacios: str = ""
    for car in palabra:
        if car == " ":
            espacios += "_ "
        else:
            espacios += car + " "
    return espacios

def poner_letras(caracter: str, palabra: str, buscada:str)-> str:
    buscada = list(buscada)
    for i in range(len(palabra)):
        if palabra[i] == caracter:
            buscada[i] = caracter
    return "".join(buscada)

categorias: dict[str:list[str]] = {
    "colores": ["rojo", "azul", " verde"],
    "numeros": ["uno", "diez", "veinte"],
}

info: list[str] = extraer_elemento(categorias)
pal_buscada: str = info[1]
letras_correctas:str = " " * len(pal_buscada)
turnos: int = 0
usadas: list[str] = []

muneco: list[str] = list("( -_•)︻デ═一 --")
partes: str = ""

print("**** Bienvenido al Juego ****")
print()

while True:
    print(generar_espacios(letras_correctas))
    opcion = input("letra >> ")
    if opcion not in usadas:
        if opcion in pal_buscada:
            letras_correctas = poner_letras(opcion, pal_buscada, letras_correctas)
        else:
            #Pintar el muneco en pantalla
            partes += muneco[turnos]
            turnos += 1
    else:
        print("Letra ya usada. Intentar de nuevo.")
        continue
    print(partes)
    if letras_correctas == pal_buscada:
        print("You won")
        break
    if turnos == len(muneco):
        print("You lost")
        break
    usadas.append(opcion)
    

