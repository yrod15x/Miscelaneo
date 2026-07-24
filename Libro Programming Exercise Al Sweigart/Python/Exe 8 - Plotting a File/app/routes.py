"""Archvio que maneja las funciones que estan conectadas a cada dirección web 
de la aplicación"""

from app import app
from flask import render_template, request
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

@app.route("/")
@app.route("/index")
def index():
    """Renderiza la página principal donde se muestra la función gráficada"""
    return render_template("index.html")

@app.route("/graficar", methods=['POST'])
def graficar():
    crear_archivo()
    datos = extraer_datos("coordenadas.txt")
    x = [datos[i][0] for i in range(len(datos))]
    y = [datos[i][1] for i in range(len(datos))]

    figura, puntos = plt.subplots()

    puntos.plot(x, y)

    plt.savefig("./app/static/images/imagen.png")
    #plt.show()
    plt.close(figura)
    #Activa la visualización de la imagen en el html que tiene una condición
    #con Jinja {% if not visto %} hidden {% endif %}
    visto = True
    return render_template("index.html", visto=visto)