from random import randint, choice, shuffle

#números de la loteria
numeros: list[int] = []
for i in range(20):
    num: int = randint(10, 99)
    if num not in numeros:
        numeros.append(num)
print(f"Los numeros para ganarse la loteria son: {
    [choice(numeros) for i in range(4)]}")

print("---------------------------------------")

#Vimos las mismas nubes
num_const: int = randint(2, 10)
temp: list[int]  = [randint(100000, 999999) for i in range(num_const)]
constelacionesA: list[int] = temp[:]
shuffle(temp)
constelacionesB = temp[:]
const_vista: int = randint(2, num_const)
if constelacionesA[const_vista - 1] == constelacionesB[const_vista - 1]:
    print("Vimos la misma constelacion.")
else:
    print("Las constelaciones eran diferentes.")

print("---------------------------------------")

#Idioma aleatorio
items: list[str] = ["tennis", "pan", "carro", "ventana", "grulla"]
palabras: list[str] = [item[::-1] for item in items]
for item in items:
    print(f"{item.capitalize()} en nuestro idioma se dice {choice(palabras)}.")

print("---------------------------------------")

#Desfile de mascotas
mascotas: list[str] = ["Max", "Luna", "Toby", "Rocky", "Nala", "Rex"]
indice: int = randint(0, len(mascotas) - 1)
mascota: str = mascotas[indice]
mascotas.remove(mascotas[indice])
print(f"{mascota} ha sido eliminado del desfile.")
indice = randint(0, len(mascotas) - 1)
mascota = mascotas.pop(indice)
#Permite insertar un item en una determinada posición en la lista
mascotas[0:0] = [mascota]
print(f"{mascotas[0]} ha sido movido al inicio del desfile.")
mascotas[randint(0, len(mascotas))-1:2] = ["Purro", "Gatuno"]
print(f"Hay nuevas mascotas: {mascotas}.")

print("---------------------------------------")

#Si pasará
annio: int = randint(2080, 3000)
if annio % 2 == 0:
    print(f"""Es {annio}. Actualmente tengo {annio - 1984} annios. Mi mascota
se llama {mascotas[randint(0, len(mascotas))-1]}. {(items[randint(0, len(items)-1)]).capitalize()} se lleva todo mi tiempo. Creo que este annio es par.""")
else:
    print(f"Este annio {annio} es impar. Y es mejor no hablar. Es mala suerte.")

#Separar frutas y verduras
cesta: list[str] = ["cebollas", "apio", "peras", "lulos", "ajies"]
frutas:  list[str] = cesta[2:4]
verduras: list[str] = cesta[0:2]
verduras.append(cesta[-1])
print(frutas)
print(verduras)