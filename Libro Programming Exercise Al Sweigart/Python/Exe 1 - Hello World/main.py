"""Programa que pide el nombre al usuario. Lo busca en archivo para saber si el 
nombre ya esta registrado y lo saluda de acuerdo a esta operación. Si el nombre
no existe lo actualiza en el archivo."""

def leer_archivo(archivo: str)-> list[str]:
    """Devuelve una lista de nombres contenidos en un archivo (parámetro)"""
    try:
        with open(archivo, "r", encoding="utf-8") as file_object:
            lineas = file_object.readlines()
        return lineas
    except FileNotFoundError:
        print("El archivo no existe.")
        return []

def registrar_nombre(archivo: str, nom: str)-> None:
    """Agrega un nombre al archivo de texto que es el parámetro"""
    try:
        with open(archivo, 'a', encoding = "utf-8") as file_object:
            file_object.write(f"{nom.capitalize()}\n")
    except FileNotFoundError:
        print("Archivo no existe.")

def pedir_nombre()-> str:
    """Devuelve un nombre pedido al usuario"""
    print("¡Hola, quiero se tu amigo!")
    nom:str = ""
    while nom == "":
        nom = input("¿Cómo te llamas? >> ")
        if nom == "":
            print("Creo que no escribiste tu nombre.")
    return nom.capitalize()

def te_conozco(list_nombres: list[str], nom: str) -> None:
    """Función que saluda al usario y registra su nombre sino esta en el archivo"""    
    if nom not in list_nombres:
        print(f"¡Mucho gusto {nom}! No te conocia.")
        registrar_nombre("personas.txt", nom)
    else:
        print(f"¡Hola {nom}! Es un gusto volver a hablarte.")

nombre: str = pedir_nombre()
nombres: list = leer_archivo("personas.txt")
te_conozco(nombres, nombre)
