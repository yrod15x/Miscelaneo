/* Crear una promesa que después de 2 segundos produzca un mensaje o un error 
dependiendo de una probabilida de un 50%*/

/*Crear la promesa -> resolve y reject son funciones dentro de la función 
argumento que devuelven un dato (promesa) que debe tomar el constructor new Promise.

1. Crear la variable referencia y asignarla al constructor
2. Hacer las acciones para resolver la promesa y su error
3. Consumir la promesa con then y catch*/
let promesaRandom = new Promise((resolve, reject) => {
    setTimeout(() => {
        let posibilidad = Math.random();
        console.log(posibilidad);
        if(posibilidad < 0.5)
        {
            resolve("Es poisible.");
        }
        else{
            reject("No se puede.");
        }
    }, 2000);
});

promesaRandom
    .then((mensaje) => {
        console.log(mensaje);
    })
    .catch((error) => {
        console.error(error);
    });