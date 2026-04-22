size(1200, 800)
background(51)
noFill()
stroke("#ffffff")
strokeWeight(3)

altura = 100
translate(200, 100)

bandas = 6
rect(0, 0, 75, altura * bandas)

col_bandas = ["#ff0000", "#ff9900", "#ffff00", "#00ff00", "#0099ff", "#6633ff"]
colorMode(RGB, 100)
resetMatrix()
translate(200, 100)

rgb_bandas = [[100, 0, 0, "red"],
              [100, 60, 0, "orange"],
              [100, 100, 0, "yellow"],
              [0, 100, 0, "green"],
              [0, 60, 100, "blue"],
              [40, 20, 100, "violet"]]

for band in rgb_bandas:
    rojo = band[0] * 2
    verde = band[1] * 2
    azul = band[2] * 2
    #suma = rojo + verde + azul
    #promedio = suma / 3
    #fill(promedio, promedio, promedio)
    #rect(0, 0, suma, altura)
    fill("#ff0000")
    rect(0, 0, rojo, altura)
    fill("#00ff00")
    rect(rojo, 0, verde, altura)
    fill("#0099ff")
    rect(rojo + verde, 0, azul, altura)
    #Nombre Colores
    fill("#ffffff")
    textSize(30)
    textAlign(RIGHT)
    text(band[3], -20, 50)
    translate(0, altura)
