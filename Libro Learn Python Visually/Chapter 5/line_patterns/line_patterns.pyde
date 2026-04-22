size(1600, 1000)
background(0)
stroke(255)
strokeWeight(3)

#Primer Patrón
x = 50
y = 100
y2 = 50
x2 = 400
offset = 0

for i in range(1, 20):
    line(x, y + offset, x2, y2 + offset)
    offset += 50
