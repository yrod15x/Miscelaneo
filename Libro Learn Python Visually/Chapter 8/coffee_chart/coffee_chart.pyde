import json

size(1700, 1300)
background("#004477")

#objeto json
jsondata = open("coffees.json")
#convierte el objeto json en datos para que python pueda trabajar
cafes = json.load(jsondata)

x_offset, y_offset = 100, 200
pos_cup_x, pos_cup_y = 200, 100
tam = 300
margen_pincel = 5
cantidad = 0
cont = 1

for i in range(9):
    noFill()
    stroke(255)
    strokeWeight(margen_pincel)
    rect(pos_cup_x, pos_cup_y , tam, tam)
    noStroke()
    fill(255)
    textSize(35)
    text(cafes[i]["name"], pos_cup_x, pos_cup_y - 20)
    offset = 0
    #Llenar las tazas
    for j in range(len(cafes[i]["ingredients"])):
        cantidad = cafes[i]["ingredients"][j]["quantity"]
        col_ing = cafes[i]["ingredients"][j]["color"]
        fill(col_ing)
        tam_ing = tam - (tam * cantidad / 100) + cantidad / 2.5 + margen_pincel
        rect(pos_cup_x + margen_pincel, pos_cup_y + tam_ing + offset, tam - margen_pincel * 2 , 
             tam - tam_ing)
        offset -= tam - tam_ing

    x_offset = 500
    y_offset = 400
    #Filas
    if cont % 3 != 0:
        pos_cup_x += x_offset
    else:
        pos_cup_x = 200
        pos_cup_y += y_offset
    #Revisar aca las posiciones dentro destos if y else    
    cont += 1
        
        
