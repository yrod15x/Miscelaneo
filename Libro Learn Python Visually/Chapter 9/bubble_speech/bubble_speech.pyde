size(900, 709)
paint = loadImage("paint.jpg")
image(paint, 0, 0, width, height)

def speechBuble(x, y, txt = "", txtSize = 1, type = "speech", x_offset=0):
    noStroke()
    pushMatrix()
    translate(x, y)
    #cola
    if type == "speech":
        fill(255)
        beginShape()
        vertex(5, 0)
        vertex(55, -80)
        vertex(15, -40)
        endShape(CLOSE)
    else:
        fill(255)
        circle(0 + x_offset, 0, 8)
        circle(10 + x_offset, -20, 20)
    #búrbuja
    textSize(txtSize)
    by = -85
    bw = textWidth(txt)
    pad = 20
    rect(0, by, bw+pad*2, 45, 10)
    fill(0)
    textAlign(LEFT, CENTER)
    text(txt, pad, by+pad)
    popMatrix()
    
speechBuble(190, 120, "Que pillin!", 22)
speechBuble(350, 130, "Fueron 3 veces!", 22)
speechBuble(680, 100, "Hablando M...", 22, "bubble", 50)
