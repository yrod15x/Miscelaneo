const elementos = [[1, 3], [2, 4], [6, 7]];

//reduce debe llevar un acumulador y un elemento para ir uniendo
console.log(elementos.reduce((acumulador, item) => acumulador.concat(item), []));