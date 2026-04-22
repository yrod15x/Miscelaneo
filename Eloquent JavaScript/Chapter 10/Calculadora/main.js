/* Programa que usa tres promesas para generar calculos conectados.
Se practica generación de promesas con argumnetos y encadenamiento con promesas.
Se practica async y await */

//Promesa que necesita un argumento
let sumaPromise = (num) => {
    return new Promise((resolve, reject) => {
        (isNaN(num) === false) ? resolve(num + 10) : reject(new Error("No es un numero"));
    });
};

let doblarPromise = (num) => {
    return new Promise((resolve, reject) => {
        (isNaN(num) === false) ? resolve(num * 2) : reject(new Error("No es un numero"));
    });
};

let triplicarPromise = (num) => {
    return new Promise((resolve, reject) => {
        (isNaN(num) === false) ? resolve(num * 3) : reject(new Error("No es un numero"));
    });
}

doblarPromise(3)
    .then(sumaPromise)
    .then(triplicarPromise)
    .then((res)=> {
        console.log(res);
    })
    .catch((error) => {
        console.log(error);
    });

async function calcular(num){
    const doblar = await(doblarPromise(num));
    const sumar = await(sumaPromise(doblar));
    const triple = await(triplicarPromise(sumar));

    console.log(triple);
}

calcular(3);