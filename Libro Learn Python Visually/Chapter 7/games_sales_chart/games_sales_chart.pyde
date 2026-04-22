from random import choice
size(2400, 1400)
background(51)

datos = loadStrings("videogames.csv")
pos_x, pos_y = 0, 50
offset = -50
colores = ["#ff0000", "#ff9900", "#bbffaa", "#00ff00", "#0099ff", "#6633ff", "#aa00ee",
           "#7899aa", "#aa9278", "#cafa98", "#0bfc00", "#75eecd", "#dd9099", "#eebbaa", 
           "#7899aa", "#aa9278", "#cafa98", "#1bfc00", "#75eecd", "#dd9099", "#eebbaa"]

for data in datos[1:]:
    linea = data.split(",")
    fill(choice(colores))
    rect(pos_x, pos_y + offset, float(linea[9]) * 25, pos_y)
    fill("#000000")
    textSize(30)
    text(linea[0], pos_x + 20, pos_y + offset + 35)
    offset += 50
