#Programa que usa una clase para leer un archivo y mostrar la suma de los kilos que reportan los productos

from LeerDatos import *

productos = LeerDatos()

productos.leer_archivo("archivo.txt")
productos.suma_valores()