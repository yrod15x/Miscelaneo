size(1600, 1200)
noStroke()
background(51)

tamano = 200

translate(width // 2, height // 2)
#rotate(QUARTER_PI)
scale(0.5)

#Las transformaciones solo toman efecto para lo que entre push and popMatrix
pushMatrix()
shearY(QUARTER_PI)
fill("#ff0000")
square(0, 0, tamano)
popMatrix()

fill("#ffff00")
square(tamano, 0, tamano)
