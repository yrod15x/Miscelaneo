def lissajours(ang, rad1, rad2, frec1, frec2):
    x = cos(ang * frec1) * rad1
    y = sin(ang * frec2) * rad2
    return [x, y]

def setup():
    size(1200, 800)
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
    x, y = lissajours(theta, 200, 100, frec1, frec2)
    circle(x, y, 10)
