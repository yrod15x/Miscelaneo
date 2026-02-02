"""Programa que simula una gráfica de un anlaizador de discos de un computador. 
Usando la función arc(posx, posy, width, height, initialAngle, closeAngle)"""

size(1800, 1500)

color_fondo = "#005487"

background(color_fondo)
stroke("#ffffff")
strokeWeight(6)

#Quarto de círculo supeior verde
fill("#00ff00")
arc(width / 2, height / 2, 1450, 1450, (PI * 2) - (PI / 3), (PI * 2) - (PI / 4.5), PIE)

#Quarto de círculo central superior azul
fill("#0000ff")
arc(width / 2, height / 2, 1150, 1150, 3.1, (PI * 2), PIE)

#Tres quartos de círculo central superior azul
fill("#0000ff")
arc(width / 2, height / 2, 1150, 1150, 3.1, (PI * 2) - (PI / 8), PIE)

#Quarto de círculo central superior morado
fill("#800080")
arc(width / 2, height / 2, 800, 800, 0, PI * 2, PIE)

#Semi-círculo central inferior rojo
fill("#ff00000")
arc(width / 2, height / 2, 800, 800, 0, PI, PIE)

#Tres quartos de círculo central superior rosado
fill("#ff69b4")
arc(width / 2, height / 2, 1150, 1150, 3.1, (PI * 2) - (PI / 3), PIE)

#Tres quartos de círculo central superior fucsia
fill("#d9027d")
arc(width / 2, height / 2, 800, 800, 3.1, (PI * 2) - (PI / 3), PIE)

#Círculo central
fill(color_fondo)
arc(width / 2, height / 2, 400, 400, 0, PI * 2)
