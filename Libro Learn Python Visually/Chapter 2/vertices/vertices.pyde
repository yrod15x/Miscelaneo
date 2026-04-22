size(1800, 1200)

offset = 50
background("#000000")
stroke("#adadad")
strokeWeight(0.1)

#Rejilla de fondo
for col in range(height // offset):
    for fila in range(width // offset):
        line(0, fila * offset, width, fila * offset)
        line(fila * offset,0, fila * offset,height )
noFill()
strokeWeight(6)
stroke("#ff4423")
#Empieza a agregar puntos para crear una figura y conectarlos
beginShape()
vertex(100, 100)
vertex(200, 100)
vertex(200, 200)
vertex(100, 200)
endShape(CLOSE)

#Curva en forma de S. bezierVertex(ancla1, ancla2, extensión) Necesita el punto de inicio antes vertex()
beginShape()
vertex(400, 200)
bezierVertex(300,300, 500,500, 400,600)
endShape()

#Moneda China
fill("#6633ff")
beginShape()
vertex(100, 600)
bezierVertex(100,545, 145,500, 200,500)
bezierVertex(255,500, 300,545, 300,600)
bezierVertex(300,655, 255,700, 200,700)
bezierVertex(145,700, 100,655, 100,600)
beginContour()
vertex(180, 580)
vertex(180, 620)
vertex(220, 620)
vertex(220, 580)
endContour()
endShape()

beginShape()
vertex(850,230)
vertex(850,170)
bezierVertex(850,40, 970,30, 1100,30)
bezierVertex(1600,20, 1650,20, 1650,230)
endShape()
