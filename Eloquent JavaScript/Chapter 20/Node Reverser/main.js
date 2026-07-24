//Da vuelta a un string que se pone como argumento en la terminal.

import {reverser} from "./reverser.mjs";

//Indice 2 tiene el primer argumento del comando en terminal
let argument = process.argv[2];

console.log(reverser(argument));