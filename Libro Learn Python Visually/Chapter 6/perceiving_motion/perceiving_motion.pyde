def setup():
    size(800, 600)
    background(51)
    noFill()
    stroke(255)
    strokeWeight(3)
    frameRate(8)

def draw():
    background(51)
    hide = frameCount % 8
    if hide == 0:
        circle(400, 100, 100)
    if hide == 1:
        circle(520, 150, 100)
    if hide == 2:
        circle(570, 270, 100)
    if hide == 3:
        circle(520, 390, 100)
    if hide == 4:
        circle(400, 440, 100)
    if hide == 5:
        circle(280, 390, 100)
    if hide == 6:
        circle(230, 270, 100)
    if hide == 7:
        circle(280, 150, 100)
