function reversarArreglo(arreglo)
{
    let reversado = [];
    for(let i = arreglo.length - 1; i >= 0; i--)
    {
        reversado.push(arreglo[i]);
    }
    return reversado;
}

function revArregloCambiado(arreglo)
{
    let temp;
    for(let i = 0; i < arreglo.length / 2; i++)
    {
        temp = arreglo[i];
        arreglo[i] = arreglo[arreglo.length - 1 - i];
        arreglo[arreglo.length - 1 - i] = temp;
        //console.log(arreglo[i], arreglo[arreglo.length - 1 - i]);
    }
    return arreglo;
}

let numeros = [2, 5, 6, 3, 7, 8, 0];
let nuevo = reversarArreglo(numeros);
console.log(nuevo);
console.log(revArregloCambiado(numeros));