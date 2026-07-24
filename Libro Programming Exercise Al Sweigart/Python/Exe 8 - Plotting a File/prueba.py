import matplotlib.pyplot as plt
from random import randint

def crear_archivo():
    """Crea un archivos con una coordenada en cada línea"""
    x = [i for i in range(10)]
    y = [randint(1, 20) for i in range(10)]
    with open("coordenadas.txt", "w", encoding="utf-8") as archivo:
        for i in range(10):
            coordenada: str = f"{str(x[i])} {str(y[i])}\n"
            archivo.write(coordenada)
    return

def extraer_datos(nom_archivo:str)-> list[list[int]]:
    """Devuelve una lista con coordenadas extraidas de un archivo"""
    with open(nom_archivo, "r", encoding="utf-8") as archivo:
        lineas = archivo.readlines()
    datos = []
    for linea in lineas:
        datos.append(str(linea).split()) 
    for data in datos:
        data[0] = int(data[0])
        data[1] = int(data[1])    
    return datos   

crear_archivo()
datos = extraer_datos("coordenadas.txt")
x = [datos[i][0] for i in range(len(datos))]
y = [datos[i][1] for i in range(len(datos))]

figura, puntos = plt.subplots()

puntos.plot(x, y)

plt.savefig("./app/static/images/imagen.png")
plt.show()
plt.close(figura)