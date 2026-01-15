"""F IN D I N G T H E M O D E
In statistics, the mode of a set of values is the value that appears most often. Write
code that processes an array of survey data, where survey takers have responded to
a question with a number in the range 1–10, to determine the mode of the data set.
For our purpose, if multiple modes exist, any may be chosen."""

from random import randint

def moda_ver1_libro(numeros: list[int])-> int:
    mostFrequent: int = 0
    highestFrequency: int = 0;
    currentFrequency: int = 0;
    numeros.sort()
    for i in range(len(numeros)):
        currentFrequency += 1
        if (i == len(numeros) - 1 or numeros[i] != numeros[i + 1]):
            if (currentFrequency > highestFrequency):
                highestFrequency = currentFrequency
                mostFrequent = numeros[i]
            currentFrequency = 0;
    return mostFrequent

def moda_ver2_libro(numeros: list[int])-> int:
    histogram: list[int] = [0 for i in range(len(numeros))]
    for i in range(len(numeros)):
        histogram[numeros[i] - 1] += 1
    mostFrequent: int = 0
    for i in range(len(numeros)):
        if histogram[i] > histogram[mostFrequent]:
            mostFrequent = i
    return mostFrequent + 1

def moda_ver_propia(numeros: list[int])-> int:
    used: list[int] = []
    frec_mayor: int = 0
    moda: int = numeros[0]
    for index, value in enumerate(numeros):
        frecuencia: int = -1
        if value not in used:
            for index2, value2 in enumerate(numeros):
                if value == value2:
                    frecuencia += 1
            used.append(value)
            if frecuencia > frec_mayor:
                frec_mayor = frecuencia
                moda = value
    return moda

datos: list[int] = [randint(1, 10) for i in range(10)]
print(*datos)
print(moda_ver_propia(datos))
print(moda_ver1_libro(datos))
print(moda_ver2_libro(datos))