from random import randint

size(800, 800)
noFill()
noStroke()

fill("#004477")
rect(0, 0, width / 2,height / 2)

fill("#ff0000")
rect(width / 2, 0,width / 2,height / 2) 

fill("#6633ff")
rect(0, width / 2, width / 2,height / 2)

fill("#ff9900")
rect(width / 2,height / 2, width, height)

cuadrante = randint(1, 4)

if cuadrante == 1:
    x, y = 200, 200
    texto = "Blue"
elif cuadrante == 2:
    x, y = 600, 200
    texto = "Red"
elif cuadrante == 3:
    x, y = 200, 600
    texto = "Purple"
else:
    x, y = 600, 600
    texto = "Orange"
    
fill("#ffffff")
textSize(40)
textAlign(CENTER, CENTER)
text(texto, x, y) 
