"""Ejercicio del libro Think Like A Programmer en donde se crean diferente
patrones con el caracter #"""

def piramide_invertida(tam: int)-> None:
    """Muestra un patrón de una piramide invertida de caraacteres."""
    for i in range(tamano // 2 + 1):
        for j in range(tamano - i):
            if(j < i):
                print(' ', end='')
            else:
                print('#', end='')
        print()

def rombo(tamano: int)->None:
    """Muestra un patrón de un rombo de caraacteres."""
    num_espacios = tamano // 2 + 1
    suiche: bool = False
    cont_cars: int = -1
    for i in range(tamano + 1):
        #Decide el numero de espacios y caracteres crecen o no si el rombo deciende.
        if not suiche:
            num_espacios = num_espacios - 1
            cont_cars += 2
        else:
            num_espacios = num_espacios + 1
            cont_cars -= 2
        for j in range(tamano):
            if j < num_espacios:
                print(' ', end='')
        for k in range(tamano):
            if k < cont_cars:
                print('*', end='')
        if tamano // 2 == i:
            suiche = True
            num_espacios = -1
            cont_cars = tamano + 2
        print()

def figura_especial(tamano: int) -> None:
    """Muestra un patrón de una figura especial de caraacteres."""
    pos_de = 0
    sup_izq_pos_de = tamano * 2 - 1
    sup_izq_pos_hasta = tamano * 2 - 1
    inf_der_pos_de = tamano - 1
    inf_der_pos_hasta = tamano * 2 - 1 - tamano // 2
    for i in range(tamano + 1):
        if i < tamano // 2 + 1:
            pos_hasta = i * 2
            for j in range(tamano * 2 + 1):
                #Parte A: superior izquierda
                if j <= tamano:
                    if j >= pos_de and j <= pos_hasta:
                        print('#', end='')
                    elif j <= i - 1 or j <= sup_izq_pos_de - 1:
                        print(' ', end='')
                else:
                    #Part B: Superior derecha
                    if j > sup_izq_pos_de and j <= sup_izq_pos_hasta + 1:
                        print('#', end='')
                        #print(f"({sup_izq_pos_de}, {sup_izq_pos_hasta})", end='')
                    elif j < sup_izq_pos_de  or j > sup_izq_pos_hasta:
                        print(' ', end='')
            sup_izq_pos_de -= 2
            sup_izq_pos_hasta -= 1 
            pos_de += 1
        else:
            pos_de = tamano - i
            for j in range(tamano * 2):
                #Parte B: inferior izquierda
                if j < tamano:
                    if j >= pos_de and j <= pos_hasta:
                        print('#', end='')
                    else:
                        print(' ', end='')
                else:
                    #Parte B: inferior derecha
                    if j > inf_der_pos_de  and j < inf_der_pos_hasta + 1:
                        print('#', end='')
                        #print(f"({inf_der_pos_de}, {inf_der_pos_hasta})", end='')
                    elif j <= inf_der_pos_de  or j > inf_der_pos_hasta:
                        print(' ', end='')
            pos_hasta -= 2
            inf_der_pos_de += 2 
            inf_der_pos_hasta += 1       
        print()

tamano: int = 7
figura_especial(tamano)