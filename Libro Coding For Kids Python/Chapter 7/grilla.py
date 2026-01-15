tamano: int = 4

def crear_grilla(columns: int, rows: int)->str:
    """
    Pone en pantalla una grilla con los caracteres | y ---.

    Parameters:
    colums (int): El número de columnas.
    rows (int): El número de filas.

    Returns:
    str: La grilla con su respectivo tamaño.
    """
    if columns <= 0 or rows <= 0:
        return ""
    fila_par: str = " ---"
    fila_impar: str = "|"
    grill: str = ""
    for col in range(columns * 2):
        if col % 2 == 0:
            for row in range(rows):
                grill += fila_par
        else:
            for row in range(rows):
                if row == rows - 1:
                    grill += f"{fila_impar}   |"
                else:
                    grill += f"{fila_impar}   "
        grill += '\n'
    for row in range(rows):
        grill += fila_par
    return grill
    
print(crear_grilla(4, 4))