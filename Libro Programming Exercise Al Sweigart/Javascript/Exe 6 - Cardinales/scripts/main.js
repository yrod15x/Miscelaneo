let boton = document.querySelector("button");

function capitalize(palabra)
{
    return palabra.charAt(0).toUpperCase() + palabra.slice(1);
}

function ordAcardinal(cardinal)
{
    let ord_hasta_12 = ["", "primero", "segundo", "tercero", "cuarto",
    "quinto", "sexto", "séptimo", "octavo", "noveno", "décimo"];
    let ord_decenas = ["", "décimo", "vigésimo", "trigésimo", "cuadragésimo",
    "quincuagésimo", "sexagésimo", "septuagésimo", "octagésimo", "nonagésimo"];
    let int_unidad = cardinal % 10;
    let int_decena = Math.floor(cardinal / 10);
    let separador = "";
    //Si el número es menor a 10 
    if (String(cardinal).length == 1)
    {
        return capitalize(ord_hasta_12[cardinal]);
        //Si el numero es de la excepciones
    }
    else
    {
        if (cardinal == 11) return capitalize("undécimo");
        else if (cardinal == 12) return capitalize("duodécimo");
        else if (cardinal == 100) return capitalize("centésimo");
        //Números compuestos
        else
        {
            if (int_unidad == 0) return capitalize(ord_decenas[int_decena]);
            else
            {
                separador = " ";
                return capitalize(ord_decenas[int_decena]) + separador 
                    + ord_hasta_12[int_unidad];          
            }                    
        }   
    }
    return ""    
}

boton.addEventListener("click", ()=>
{
    let numero = Math.floor(Math.random() * (100 - 1) + 1);
    let cardinal = document.querySelector(".cardinal");
    let ordinal = document.querySelector(".ordinal");
    cardinal.textContent = numero; 
    ordinal.textContent = ordAcardinal(numero);
});

