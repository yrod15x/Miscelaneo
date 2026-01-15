function contarCaracteres(texto, caracter)
{
    let contador = 0;
    for(let i = 0; i < texto.length; i++)
    {
        if(texto[i] == caracter) contador += 1;
    }
    return contador;
}

numCaracteres = contarCaracteres("La mujer estaba sentada en la puerta", 'a')
console.log(numCaracteres);