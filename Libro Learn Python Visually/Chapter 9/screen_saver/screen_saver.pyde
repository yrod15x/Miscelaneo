def lissajours(ang, rad1, rad2, frec1, frec2):
    x = cos(ang * frec1) * rad1
    y = sin(ang * frec2) * rad2
    return [x, y]

def setup():
    size(1600, 1200)
    frameRate(30)
    background(51)
    fill(255)
    noStroke()
    
theta = 0
period = 10
frec1, frec2 = random(1, 5), random(1, 5)

def draw():
    global theta, frec1, frec2
    theta += TAU / (frameRate * period)
    scale(1, -1)
    translate(width /2, height / 2 - height)
    for i in range(10):
        t = theta + i / 15.0
        x1, y1 = lissajours(t, 700, 250, frec1, frec2)
        x2, y2 = lissajours(t, 250, 220, frec1, frec2)
        fill(0x55000000)
        noStroke()
        #Cuadrado opaco que va ocultando las líneas para dar efecto de fade
        rect(-width / 2, -height/2, width, height)
        colorMode(HSB, 360, 100, 100)
        hue = (frameCount + i * 15) % 360
        strokeWeight(7)
        stroke(hue, 100, 100)
        line(x1, y1, x2, y2)
