#Programa que toma un archivo de texto y cambia la linea con menor cantidad de caracteres
#Con la linea de mayor numero de los mismos

def leer_lineas(nom_archivo):
    with open('texto.txt') as file_object:
        lineas = file_object.readlines()
    return lineas

def mayor_menor(lineas):
    nueva_lineas = ""
    num_caracteres = [len(c) for c in lineas]
    for i, val in enumerate(lineas):
        if i == num_caracteres.index(min(num_caracteres)):
            nueva_lineas += (lineas[num_caracteres.index(max(num_caracteres))])
        elif i == num_caracteres.index(max(num_caracteres)):
            nueva_lineas+= (lineas[num_caracteres.index(min(num_caracteres))])
        else:
            nueva_lineas += val

    return nueva_lineas

lineas = leer_lineas('texto.txt')
print(mayor_menor(lineas))

