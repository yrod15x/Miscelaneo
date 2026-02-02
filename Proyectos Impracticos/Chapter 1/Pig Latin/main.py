"""Pig latin: You take the first letter of a word (e.g. Hello = H) and use the last letters
(e.Hello = ello) and add 'ay' to the first letter (e.g. Hello = Ello hay). 
Words that start with a vowel (A, E, I, O, U) simply have "ay" appended 
to the end of the word. """

def pig_latin(palabra:str)->str:
    """Traduce una palabra a PigLatin"""
    if palabra[0] in CONSONANTES:
        latino = palabra[1:] + palabra[0] + 'ay'
    else:
        latino = palabra[1:] +  'ay'
    return latino

CONSONANTES = 'bcdfghjklmnpqrstvwxyz'
word = input().lower()
word = word.split()
texto = []

for w in word:
    texto.append(pig_latin(w))

texto = " ".join(texto)
print(texto)
