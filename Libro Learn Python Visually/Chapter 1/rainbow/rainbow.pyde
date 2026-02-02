from random import randint

size(1200, 800)
background("#005588")
noStroke()
fill("#005588")

extra = 0

for i in range(7):
    circle(width // 2, height, 1100 - extra)
    fill(randint(0, 255), randint(0, 255), randint(0, 255))
    extra += 100
    
fill("#005588")
circle(width // 2, height, 1100 - extra)
