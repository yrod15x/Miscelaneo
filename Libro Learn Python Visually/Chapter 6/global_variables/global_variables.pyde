y = 0

def setup():
    size(800, 600)
    background(51)
    noFill()
    stroke(255)
    strokeWeight(3)

def draw():
    global y
    background(51)
    circle(height / 2, y, 50)
    y += 1
