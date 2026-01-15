from app import app
from flask import render_template, flash, redirect
from random import randint, choice
from app import funciones
from app.formularios import NumeroForm

numeros = [i for i in range(51)]
#Lista que permite guardar variables o valores para usarlos entre rutas(funciones)
variables: list[int] = []
variables.append(choice(numeros))
variables.append(choice(numeros))

operacion: str = '-'
suma_resta: int =  randint(1, 2)
if suma_resta == 1:
    operacion = '+'
resultado = ""
correcto: str = ""

@app.route("/")
def index():
    numeroX = NumeroForm()
    res_num = variables[0] + variables[1] if operacion == '+' else variables[0] - variables[1]
    resultado: str = funciones.cardinal_a_ordinal(res_num)
    print(variables[0])
    print(variables[1])
    print(res_num) 
    return render_template("index.html", titulo = "Home", numero1 = variables[0],
    numeroX = numeroX, operacion = operacion, resultado = resultado, 
    numero2 = variables[1])

@app.route("/verificar", methods=['GET', 'POST'])
def verificar():
    numeroX = NumeroForm()    
    if numeroX.validate_on_submit():
        print(f"{numeroX.data["numeroX"]} -> {variables[1]}")
        #Revisar por que el num2 no se esta actualizando. Toma es el inicial
        if numeroX.data["numeroX"] == variables[1]:
            print("Correcto")
            correcto = "Correcto"
        else:
            print("Wrong")
            correcto = "Incorrecto"
        numeroX.numeroX.data = None   
    variables[0] = choice(numeros)
    variables[1] = choice(numeros)
    operacion: str = '-'
    suma_resta: int =  randint(1, 2)
    if suma_resta == 1:
        operacion = '+'
    resultado = ""
    res_num = variables[0] + variables[1] if operacion == '+' else variables[0] - variables[1]
    print(variables[0])
    print(variables[1])
    print(res_num) 
    resultado: str = funciones.cardinal_a_ordinal(abs(res_num)) 
    return render_template("index.html", titulo = "Home", numero1 = variables[0],
    numeroX = numeroX, operacion = operacion, resultado = resultado, 
    numero2 = variables[1], correcto = correcto)
