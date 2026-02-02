from random import randint

size(2400, 1200)
background("#004477")
noFill()
stroke("#ffffff")
strokeWeight(3)

#Puntos: point(x, y)
for i in range(200):
    point(randint(0, width), randint(0, height))
    
#Triángulo: triangle( x1,y1, x2,y2, x3,y3 )
triangle(randint(0, 800),randint(0, 800), randint(0, 800),randint(0, 800), randint(0, 800),randint(0, 800))

#Ellipse: ellipse(x1,y1, width, height)
ellipse(randint(0, width),randint(0, height), randint(0, 500), randint(0, 500))

#Círculo: circle(x1,y1, diametro)
circle(randint(0, width),randint(0, height), randint(0, 1200))

#Cuadrado: square(x1,y1, lado)
square(randint(0, width),randint(0, height), randint(0, 1200))

#Quadilatero: quad( x1,y1, x2,y2, x3,y3, x4,y4 )
quad(randint(0, 800),randint(0, 800), randint(0, 800),randint(0, 800), 
     randint(0, 800),randint(0, 800), randint(0, 800),randint(0, 800))

#líneas: line(x1,y1, x2,y2)
line(randint(0, width),randint(0, height), randint(0, width),randint(0, height))
