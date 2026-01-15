function preAppend(valor, lista)
{
    let temp = {
        value: valor,
        rest: lista,
    }
    return temp;
}
function arrayToList(array)
{
    array.reverse();
    let nodo = {
        value: array[0],
        rest: null,
    }
    for(let val of array)
    {
        nodo = preAppend(val, nodo);
    }
    return nodo;
}

function listToArray(lista)
{
    let array = [];
    let nodo = {
        value: lista.value,
        rest: lista.rest,
    };
    while(nodo.rest != null)
    {
        array.push(nodo.value);
        nodo = nodo.rest;
    }
    return array;
}

function printList(lista)
{
    let nodo = {
        value: lista.value,
        rest: lista.rest,
    };
    while(nodo.rest != null)
    {
        console.log(nodo.value);
        nodo = nodo.rest;
    }
}

function nth(lista, index)
{
    let nodo = {
        value: lista.value,
        rest: lista.rest,
    };
    let cont = 0;
    let value;
    while(nodo.rest != null)
    {
        if(cont == index)
        {
            value = nodo.value;
            break;
        }
        nodo = nodo.rest;
        cont++;
    }
    return value;
}

let numbers = [2, 5, 9, 7];
let lista = arrayToList(numbers);
printList(lista);
console.log(listToArray(lista));
console.log(nth(lista, 6));