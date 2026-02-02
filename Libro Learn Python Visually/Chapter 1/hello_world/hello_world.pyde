from random import randint

size(500, 500)
background(randint(0, 265), 45, 67)
#stroke y strokeWeight permiten msanipular el controno de laa figuras: color y tamaño
stroke("#ffffff")
strokeWeight(3)
print("Hello world!")
#fill(color) se usa para llenar un elemento con determindado color
fill("#66efd3")
rect(50, 50, 100, 200)
fill(randint(0, 265), randint(0, 265), randint(0, 265))
rect(350, 50, 100, 150)
colorMode(HSB, 360, randint(0, 100), 100)
fill("#ff9900")
rect(200, 100, 120, 60)
noFill()
square(150, 250, 200)  

#Los colores se pueden dar en tres modos:
    #1. Hecadecimal
    #2. RGB
    #3. HSB (hue, saturation, brightness)
