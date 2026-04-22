h = 1600
w = 1200

tam_text = 150
y = random(tam_text, h / 2)
yspeed = random(10)
x = random(tam_text, w / 2)
xspeed = random(10)


def setup():
    size(h, w)
    fill("#0099ff")
    textSize(tam_text)
    
def draw():
    global y, yspeed, x, xspeed
    background(0)
    y += yspeed
    x += xspeed
    text('DVD', x, y)
    if y > height or y < 100:
        yspeed *= -1
    if x > width - 250 or x < -10:
        xspeed *= -1
    
