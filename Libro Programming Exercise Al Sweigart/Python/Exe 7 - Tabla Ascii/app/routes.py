"""Aplicacion Flask que muestra la tabla ascii por pantalla"""

from datetime import datetime
from flask import render_template
from app import app

@app.route("/")
@app.route("/index")
def index():
    """Muestra la página principal con la tabla ascii"""
    tabla_ascii: list = []
    caracter_int: int = 32
    for col in range(16):
        filas = []
        for fila in range(17):
            pareja: dict[int:str] = {}
            if caracter_int >= 127 and caracter_int <= 160:
                caracter_int += 1
                continue
            pareja[caracter_int] = chr(caracter_int)
            filas.append(pareja)
            caracter_int += 1
        tabla_ascii.append(filas)
    return render_template("index.html", titulo="Tabla Ascii", 
    tabla_ascii=tabla_ascii, annio=datetime.now().year)
