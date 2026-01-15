from random import choice, randint
from time import sleep

separador = '-' * 30

#Postres y Personas
nombres: list[str] = ["Luigi", "Mario", "Peach", "Bowser", "Toad", "Yoshi"]
postres: list[str] = ["galleta", "pastel", "pie", "helado", "malteada", "flan"]

for nom in nombres:
    postre: str = choice(postres)
    articulo: str = "el"
    if postre[-1] == 'a':
        articulo = "la"
    print(f"Me llamo {nom} y me gusta {articulo} {postre}.")

print(separador)

#Hula Hoops
condicion: list[str] = ["atletico", "no atletico", "mayor", "joven"]
personas: list[str] = [choice(condicion) for i in range(10)]
num_personas_cancha: int = 0
num_personas_subiBaja: int = 0
for persona in personas:
    if persona == "atletico" or persona == "joven":
        num_personas_subiBaja += 1
    else:
        num_personas_cancha += 1
la_s_1, la_s_2 = 's', 's'
if num_personas_cancha == 1:
    la_s_1 = ''
if num_personas_subiBaja == 1:
    la_s_2 = ''
print(f"Hay {num_personas_cancha} persona{la_s_1} en la cancha.")
print(f"Hay {num_personas_subiBaja} persona{la_s_2} en el subi-baja.")

print(separador)

#De Patitas

def mostrar(info: list[dict[str: int]])-> int:
    patas: int = 0
    for animal in info:
        for key, value in animal.items():
            patas += value
    return patas

sin_patas: list[dict[str: int]] = [{"serpiente" : randint(1, 50)}, {"tiburon" : randint(1, 50)},
{"delfin" : randint(1, 50)}]
bipedos: list[dict[str: int]] = [{"pinguino" : randint(1, 50)}, {"avestruz" : randint(1, 50)},
{"canguro" : randint(1, 50)}]
cuadrupedos: list[dict[str: int]] = [{"leon" : randint(1, 50)}, {"alce" : randint(1, 50)},
{"bisonte" : randint(1, 50)}]
print(f"El numero de animales sin patas es {mostrar(sin_patas)}")
print(f"El numero de animales con dos patas es {mostrar(bipedos)}")
print(f"El numero de animales con 4 patas es {mostrar(cuadrupedos)}")

print(separador)

#Contraseña correcta
password: int = randint(1, 5)
guess: int = -1
while guess != password:
    print("Hackeado el sistema...")
    sleep(1)
    guess = randint(1, 5)
    if guess == password:
        print(f"Su contrasena es {password}.")
        print(" @ Acceso Permitido @")

print(separador)

#Adivina el número
turno: int = 0
incognito: int = randint(1, 10)
while(turno != incognito):
    if turno < incognito:
        print(f"{turno} es bajo.")
        turno = randint(turno, 10)
    elif turno > incognito:
        print(f"{turno} es alto.")
        turno = randint(1, turno)
    if(turno == incognito):
        print(f"Acertado. El numero desconocido es {incognito}")
    sleep(1)

print(separador)

#Numero de vocales
texto: str = "lorem ipsum voleiat bacorum pottis biggues anfarat"
vocal_cont:dict[str:int] = {}
vocales: list[str] = ['a', 'e', 'i', 'o', 'u']
for vocal in vocales:
    vocal_cont[vocal] = 0
for letter in texto:
    if letter in vocales:
        vocal_cont[letter] += 1
print(vocal_cont)

print(separador)

#Galletad de chocolate
galletas: list[str] = ["r3", "c8", "c3", "r6", "c9", "r7", "r23"]
num_galletas: int = 0
for galleta in galletas:
    if galleta[0] == 'c':
        num_galletas += int(galleta[1])
print(f"Hay un total de {num_galletas} de chocolate")

