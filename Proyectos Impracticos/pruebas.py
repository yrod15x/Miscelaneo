#Probar strings[index:] and strings[:index]

palabra = 'gato'
rev_palabra = palabra[::-1]

#Va mostrando la palabra de izq a der, quitando las letras 0 hasta el valor de i
#gato - ato - to - o
for i in range(len(palabra)):
   print(palabra[i:])

#Va mosntrando la palabra de der a izq, quitando las letras desde el final hasta 0
#otag - ota - ot - o   
for i in range(len(rev_palabra)):
   print(rev_palabra[:len(rev_palabra)-i])
    