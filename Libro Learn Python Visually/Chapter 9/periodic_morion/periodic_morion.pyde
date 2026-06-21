def setup():
    size(1600, 1200)

radio = 400
theta = 1
period = 3.1
puntos_ellipse = []
puntos_spiral = []
puntos_circle = []
puntos_sinus = []
sin_x = -800

def draw():
    global theta, sin_x
    background(51)
    noFill()
    strokeWeight(4)
    stroke(211, 211, 211, 10)
    line(width / 2, height / 2, width / 2, 0)
    line(0, height / 2, width, height / 2)
    #voltear el eje y para que tenga la misma estructura del plano cartesiano
    scale(1, -1)
    translate(0, -height)
    #reposicionar el origen
    translate(width/2, height/2)

    circle(0, 0, radio * 2)
    # stroke(255)
    # pushMatrix()
    # #Rota en ángulo de 1 radian (57.3)
    # rotate(theta)
    # line(0, 0, radio, 0)
    # popMatrix()
    
    noStroke()
    fill(255)
    #Círculo completo
    x, y = circlePoint(theta, radio)
    puntos_circle.append([x, y])
    circle(x, y, 20)
    #Espiral
    x, y = circlePoint(theta, frameCount * 0.1)
    puntos_spiral.append([x, y])
    circle(x, y, 20)
    #ellipse
    x, y = ellipsePoint(theta, radio * 1.5, radio)
    puntos_ellipse.append([x, y])
    circle(x, y, 20)
    #movimiento de seno
    amplitud = radio
    y = sin(theta) * amplitud
    puntos_sinus.append([sin_x, y])
    circle(sin_x, y, 20)
    sin_x += 1
    if sin_x > width / 2:
        sin_x = 0
    #Martillo con resorte
    y = sin(theta) * amplitud
    noFill()
    stroke(255)
    strokeJoin(ROUND)
    bends = 35
    beginShape()
    for i in range(bends):
        vx = 30 + 60 * (i % 2 - 1)
        vy = 300 - (300 - y) / (bends - 1) * i
        vertex(vx, vy)
    endShape()
    rect(-100, y - 80, 200, 80)
    
    theta += TAU / (frameRate * period)
    printPath(puntos_circle)
    printPath(puntos_ellipse, 1)
    printPath(puntos_spiral, 2)
    printPath(puntos_sinus, 3)
    
def circlePoint(angle, rad):
    x = cos(angle) * rad
    y = sin(angle) * rad
    return [x, y]

def ellipsePoint(angulo, hor_rad, ver_rad):
    x = cos(angulo) * hor_rad
    y = sin(angulo) * ver_rad
    return [x, y]

def printPath(puntos, colour = 0):
    for pts in puntos:
        if colour == 1:
            stroke(255, 0, 0, 100)
        elif colour == 2:
            stroke(0, 255, 0, 100)
        elif colour == 3:
            stroke(0, 0, 255, 100)
        else:
            stroke(255, 255, 255, 100)    
        point(pts[0], pts[1])
