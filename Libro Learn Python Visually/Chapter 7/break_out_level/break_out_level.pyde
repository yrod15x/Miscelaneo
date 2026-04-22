from random import choice
size(1200, 800) 
   
background(0)
stroke(255)
strokeWeight(2)
colores = ["#ff0000", "#ff9900", "#ffff00", "#00ff00", "#0099ff", "#6633ff", "#000000",
           "#ff9910", "#339920", "#fafb08", "#abfc00", "#4545cd", "#bbcc00", "#000000"]

bricks = []
brick_w, brick_h = 300, 50
pos_x, pos_y = 0, 0
cols, rows = 8, 4
#Poner colores aleatorios
for i in range(cols):
    row = []
    for j in range(rows):
        row.append(choice(colores))
    bricks.append(row)
#Mostrar los ladrillos    
for i in range(cols):
    for j in range(rows):
        fill(bricks[i][j])
        if bricks[i][j] != "#000000":
            rect(pos_x, pos_y, brick_w, brick_h)
        pos_x += brick_w
    pos_y += brick_h
    pos_x = 0
        
fill("#ffffff")
circle(800, 600, 40)
rect(500, 700, brick_w, brick_h)        
