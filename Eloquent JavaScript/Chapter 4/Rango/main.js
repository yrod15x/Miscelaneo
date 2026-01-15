/* Crear una programa con dos funciones rango(inicio, fin, paso) y suma(arreglo).
La primera devuelve un arreglo de números que estan entre dos limites.
La segunda suma todos los números de un arreglo. */

function rango(inicio, fin, paso = 1)
{
    let numeros = [];
    for(let i = inicio; i <= fin; i += paso)
    {
        numeros.push(i);
    }
    return numeros;
}

function suma(numeros)
{
    let resultado = 0;
    for(let num of numeros)
    {
        resultado += num;
    }
    return resultado;
}

console.log(suma(rango(1, 10)));