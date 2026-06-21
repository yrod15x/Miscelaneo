def setup():
    size(1800, 1200)
    background(51)
    noLoop()
    
swatches = ["#ff0000", "#ff9900", "#ffff00", "#00ff00", "#0099ff", "#6633ff"]
brushcolor = swatches[2]
brushShape = ROUND
brushsize = 3
painting = False
paintmode = "free"
palette = 120

def draw():
    #print(frameCount)
    global painting, paintmode
    if mouseX < palette:
        paintmode = "select"
    else:
        paintmode = "free"
    if paintmode == "free":
        if painting:
            stroke(brushcolor)
            strokeCap(brushShape)
            strokeWeight(brushsize)
            line(mouseX, mouseY, pmouseX, pmouseY)
        elif frameCount > 1:
            painting = True
    noStroke()
    fill(255)
    rect(0, 0, palette, height)
    for i, swatch in enumerate(swatches):
        sx = int(i % 2) * palette / 2
        sy = int(i / 2) * palette / 2
        fill(swatch)
        square(sx, sy, palette / 2)
    fill(0)
    textSize(40)
    text("CLEAR", 5, height - 12)
            
def mousePressed():
    if mouseButton == LEFT:
        loop()
    if mouseButton == LEFT and mouseX < palette and mouseY < 180:
        global brushcolor
        #sToma el color del pixel en el que se hace click o que esta en esas coordendas
        brushcolor = get(mouseX, mouseY)

def mouseReleased():
    if mouseButton == LEFT:
        global painting
        painting = False
        noLoop()

def mouseWheel(e):
    global brushsize, paintmode
    paintmode = "select"
    brushsize += e.count
    if brushsize < 3:
        brushsize = 3
    if brushsize < 45:
        brushsize = 45
    redraw()
    
def mouseClicked():
        if (mouseX > 0 and mouseX < palette) and (mouseY >= height - 52 and mouseY <= height):
            noStroke()
            fill(51)
            rect(palette, 0, width, height)
        redraw()
            
