"""Ejercicios del cápitulo 3. Uso de números y operadores aritméticos y booleanos"""

from datetime import date
from random import randint
#Cuántos años tienes 
annio_actual: int = date.today().year
anio_nacimiento: int = randint(1920, annio_actual - 1)
print(f"Usted tiene {annio_actual - anio_nacimiento} anios.")

#Qué único número usando operadores da 333 - Usar PEMDAS.
numero_magico: int = 4**4 // 4 + 4**4 + 4 * 4 - 4 + 4 % 4 + 4**(4 - 4)
print(f"4^4 // 4 + 4^4 + 4 * 4 - 4 + 4 % 4 + 4^(4 - 4) = {numero_magico}")

#Quien tiene más galletas
Mike: int = randint(1, 20)
Ania: int = randint(1, 20)
print("Mike tiene mas galletas.") if Mike >= Ania == True else print("Ania tiene mas galletas.")

#Repartir la torta
personas: int = randint(1, 1000)
pedazos: int = randint(1, 10)
print("Todos reciben pedazos iguales de torta") if personas % pedazos == 0 else print("No se pueden repartir pedazos iguales")

#Revisar la moda
cher_color_vestido: str = "rosa"
cher_color_zapatos: str = "blanco"
cher_aretes: bool = True
dionne_color_vestido: str = "morado"
dionne_color_zapatos : str= "rosa"
dionne_aretes: bool = True
print(f"Al menos una persona viste de morado? {cher_color_vestido == "morado" 
or dionne_color_vestido == "morado"}")
print(f"Al menos una persona tiene aretes? {cher_aretes  or  dionne_aretes}")
print(f"Tiene zapatos diferentes? {cher_color_zapatos != dionne_color_zapatos}")

#Laboratorio lógico
beakers: int = randint(1, 20)
tubos: int = randint(1, 30)
guantes: int = randint(1, 10)
lentes: int = randint(1, 10)
estudiantes: int = randint(1, 10)

suficientes_beakers: bool = estudiantes % beakers == 0
suficientes_guantes: bool = estudiantes % guantes == 0
suficientes_tubos: bool = estudiantes % tubos == 0
suficientes_lentes: bool = estudiantes % lentes == 0

reporte: str = f"""
Implementos:
Beakers: {beakers}
Tubos: {tubos}
Guantes: {guantes}
Lentes: {lentes}
Estudiantes: {estudiantes}
Cada estudiante tiene suficientes lentes: {suficientes_lentes}
Cada estudiante tiene suficientes beakers: {suficientes_beakers}
Cada estudiante tiene suficientes tubos: {suficientes_tubos}
Cada estudiante tiene suficientes lentes: {suficientes_lentes}
Hay suficientes lentes y guantes para cada estudiante: {suficientes_lentes and suficientes_guantes}
Hay suficientes tubos o beakers para cada estudiante: {suficientes_tubos or suficientes_beakers}
Hay suficientes lentes y beakers para cada estudiante: {suficientes_lentes and suficientes_beakers}
Hay suficienres elementos para todos: {suficientes_lentes and suficientes_guantes 
and suficientes_beakers and suficientes_tubos}
"""
print(reporte)

#Planetas en las galaxias
galaxias: dict[str, int] = {
    "Casiopea" : randint(2, 10),
    "Andromeda" : randint(2, 10),
    "Estelar" : randint(2, 10),
    "Rakon5" : randint(2, 10),
    "Lunar Ball" : randint(2, 10),
}
for nombre, valor in galaxias.items():
    factor: int = randint(1, 5)
    print(f"La galaxia {nombre} tiene {valor**factor} planetas.")

#Opciones de comida
entradas: dict[str: bool] = {
    "Ensalada de bererenjena" : randint(0, 1),
    "Picada Caribe" : randint(0, 1),
}
plato_fuerte: dict[str: bool] = {
    "Carne al carbon" : randint(0, 1),
    "Pollo a la parrilla" : randint(0, 1),
}
postres: dict[str: bool] = {
    "Helado de maracuya" : randint(0, 1),
    "Torta de banana" : randint(0, 1),
}
menu: list = [entradas, plato_fuerte, postres]
for comida in menu:
    for nombre, valor in comida.items():
        print(f"{nombre} : {bool(valor)}")