pos_ingr_x = 
    #Lo hago al revés para que las cantidades de abajo se superpongan a las de arriba
    for j in range(len(cafes[i]["ingredients"])):
        cantidad = cafes[i]["ingredients"][j]["quantity"]
        col_ing = cafes[i]["ingredients"][j]["color"]
        fill(col_ing)
        rect(pos_x + margen_pincel, pos_y2 - cantidad, pos_x2 - margen_pincel * 2, pos_y2 - (pos_y2 - cantidad - pos_y))
        print(pos_y2 - (pos_y2 - cantidad - pos_y)) 
        #que altura comienza el ste ingrediente
        pos_y2 = pos_y
