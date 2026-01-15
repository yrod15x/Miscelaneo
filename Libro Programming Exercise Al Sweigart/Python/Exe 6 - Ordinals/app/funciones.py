#Funciones que servirán para hacer operacines dentro de los demás archivos

def cardinal_a_ordinal(ordinal: int)-> str:
    card_hasta_12: list[str] = ["", "primero", "segundo", "tercero", "cuarto",
    "quinto", "sexto", "séptimo", "octavo", "noveno", "décimo"]
    card_decenas: list[str] = ["", "décimo", "vigésimo", "trigésimo", "cuadragésimo",
    "quincuagésimo", "sexagésimo", "septuagésimo", "octagésimo", "nonagésimo"]
    int_unidad: int = ordinal % 10
    int_decena: int = ordinal // 10
    separador: str = ""
    #Si el número es menor a 10 
    if len(str(ordinal)) == 1:
        return card_hasta_12[ordinal].capitalize()
    #Si el numero es de la excepciones
    else:
        if ordinal == 11:
            return "undécimo".capitalize()
        elif ordinal == 12:
            return "duodécimo".capitalize()
        elif ordinal == 100:
            return "centésimo".capitalize()
    #Números compuestos
        else:
            if int_unidad == 0:
                return card_decenas[int_decena].capitalize()
            else:
                if int_unidad > 2:
                    separador = " "
                return card_decenas[int_decena].capitalize() + separador + card_hasta_12[int_unidad]
    return ""
