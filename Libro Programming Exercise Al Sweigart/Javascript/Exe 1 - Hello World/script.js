/** Programa que pide el nombre al usuario. Lo busca en archivo para saber si el
nombre ya esta registrado y lo saluda de acuerdo a esta operación. Si el nombre
no existe lo actualiza en el archivo.**/

function leerNombres(nomArchivo)
{
    //Leer archivo y poner las líneas en un arreglo
    const archivo = require('fs');
    const lineas = archivo.readFileSync(nomArchivo, "utf8");
    return lineas.toString().split("\n");
}

function saludar(nombres)
{
    /*Verifica que un nombre pedido al usuario este en un archivo para saludarlo 
    y/o registrar el nombre si no es inscrito*/
    let encontrado = false;
    const leerNombre = require('readline');   
    let rl = leerNombre.createInterface(process.stdin, process.stdout)
    /*Permite pedir un dato por consola. Tocó poner la verficación del nombre
    de la esta función para hacerla funcionar*/
    rl.question("¿Cómo te llamas? >> ", (nom) => 
    {
        //Poner mayúscula inicial
        nom = nom.charAt(0).toUpperCase() + nom.substring(1);
        for(let n of nombres)
        {
            if(nom === n)
            {
                encontrado = true;
                break;
            }
        }
        rl.close();
        if(encontrado)
        {
            console.log(`¡Hola ${nom}! Es un gusto volver a hablarte.`);
        }
        else
        {
            console.log(`¡Hola ${nom}!. No te conocia. !Mucho gusto!`);
            const archivo = require("fs");
            archivo.appendFile("personas.txt", nom + '\n', (err) => 
            {
                if(err) throw err;
                console.log("¡He registrado tu nombre!")
            });
        }
    });
}

console.log("Hola, quiero se tu amigo!\n");
let nombres = leerNombres("personas.txt");
saludar(nombres);
