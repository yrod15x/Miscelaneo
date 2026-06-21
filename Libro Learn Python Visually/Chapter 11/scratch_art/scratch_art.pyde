def setup():
    size(1600, 1200)
    frameRate(20)
    background(0)
    stroke(255)
    
def draw():
    colorMode(HSB, 360, 100, 100)
    h = mouseX * 360.0 / width
    s = mouseY * 100.0 / height
    b = 100
    stroke(h, s, b)
    strokeWeight(15)
    if mousePressed and mouseButton == LEFT:
        line(mouseX, mouseY, pmouseX, pmouseY)
    
