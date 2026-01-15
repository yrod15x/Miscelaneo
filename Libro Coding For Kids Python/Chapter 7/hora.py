#Programa que simula diferencias horarias en varias ciudades del mundo
from datetime import datetime
import time

hora: datetime = datetime.now()

ciudades = {"Berlin": 6 , "Bogota": 1 - time.daylight, "Tokio": 14, "Abu-Dhabi": 9, "Sidney": 16,}

for llave, valor in ciudades.items():
    hora_temp = hora.hour + valor
    if hora_temp >= 24:
        hora_temp -= 24 
    horas: str = str(hora_temp)
    horas = "0" + horas if hora_temp < 10 else horas
    minutos: str = "0" + str(hora.minute) if hora.minute < 10 else str(hora.minute)
    segundos: str = "0" + str(hora.second) if hora.second < 10 else str(hora.second)
    print(f"En {llave} son las {horas}:{minutos}:{segundos}")