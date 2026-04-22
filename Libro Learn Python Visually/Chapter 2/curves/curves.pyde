size(1600, 1200)

#Cargar la imagen de una grilla de líneas
grilla = loadImage("grid.png")
image(grilla, 0, 0, width, height)
noFill()
strokeWeight(3)

"""CATMULL-ROM SPLINE"""
#Línea diagonal
stroke("#0099ff")
line(200,150, 1400,1050)
#Curva amarilla
curveTightness(0)
stroke("#ffff00")
curve(0,600, 200,150, 1400,1050, 1600, 600)
#Curva anaranjada
stroke("#ff9900")
curve(0,100, 0,600, 200,150, 1400,1050)  
curve(200,100, 1400,1050, 1600,600, 1600,800)

"""CURVA DE BEZIER"""
stroke("#ff99ff")
cp1x, cp1y = 280, 280
cp2x, cp2y = 280, 280
bezier(1400,150, cp1x,cp1y, cp2x,cp2y, 200,1050)  
