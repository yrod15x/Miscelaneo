#Recreate the story of the lady and the tiger

from random import randint

nombres = ["Max", "Luna", "Toby", "Rocky", "Nala", "Rex"]
puerta: int = randint(1, 2)
sopresa: tuple[str] = ("quien sera tu esposa", "un tigre hambriento")

intro: str = f"""De pronto despiertas bajo el abrazo gelido de la manana. Todo 
viene a tu cabeza. Has sido condenado por el simple hecho de amar a quien no 
debias: La Princesa. Y sabes que te llevaran. Iras a la Arena, donde te 
juzgaran. Tu suerte tambien sera tuya. LLaman a tu calabozo. Dos guardias posan
en tu puerta seguidos de Monje {''.join(sorted(nombres[randint(0, len(nombres)-1)]))}.\n 
Te levantas. Te diriges a la puerta. Escuchas el chirrido del metal corroido
mientras se mueven. Los soldados te toman de los brazos y mientras pasas al 
lado del monje, sientes que la textura del pergamino se desliza entre tu vestido
y tu piel. Con la cabeza  baja buscas tu suerte.\n"""

print(intro)

leer: str = input("Deseas leerlo? - (s) >> ").lower()
if leer == 's':
    print("Sabes que ella lo envio. Pero ahora tu suerte depende de su verdad.")
else:
    print("Tal vez es mejor asi. Tu suerte sigue dependiendo de ti.")

print("""Por fin llegas a la Arena. El clamor ruge y desciende desde las gradas.
Alzas tu mirada y los ves en el palco de honor. Lo que nunca llegaras a tener.
Ella acompanada de sus padres desvia sus ojos. Tal vez no quiere saberlo.
Mi amado debe abrir una de las dos puertas. Solo padre, madre y 
yo sabemos que hay detras de cada una. Me mentiria a mi misma si no le
hice saber a quien deseo mas. Si el dolor y la alegria de verlo vivo o 
la resignacion y mezquindad de mi alma.""")

if leer == 's':
    print("""\nSe que leyo mi mensaje. Sabra que lo amo de verdad.\n""")
else:
    print("""\nNo leyo mi mensaje. Siempre orugulloso de su suerte.
El sera quien dictamine nuestros destino de ahora en adelante.\n""")

print("""Una vez miras al frente. Miras tu suerte, tu destino. Dos puertas. Cada 
unacon numero. 1 a la izquierda. 2 en la otra. El Rey levanta su pulgar y los dos
gurdias detras de ti, empunan sus espadas, obligandote a caminar hacia alguna
de las dos.""")

print(f"""\nTe encaminas hacia la puerta {puerta}. Vuelves a buscar sus ojos.
Esta vez los encuentras. Otra vez intenta decirte cual abrir.""")

leer: str = input("\nQue suerte deseas? La tuya? - (s) >> ").lower()
if leer == 's':
    print(f"""Con fuerzas tomas la manija y con los ojos bien abiertos,ante ti se 
abre tu suerte. Observas con incredulidad a {sopresa[randint(1, 2)-1]}.
Al fin al cabo lo eligiste tu mismo! La amaste de verdad?""")
else:
    print(f"""Con temor tomas la manija y con los ojos bien cerrados,ante ti se 
abre tu suerte. Observas con incredulidad a {sopresa[randint(1, 2)-1]}.
De verdad te amo?""")
