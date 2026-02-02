/* Muestra como se manejan las excepciones en JS.

1. Arrojar el error a otra función con throw mediante un objeto Error y un mensaje.
2. Verificar si hay algún error y manejarlo mediante try (permite la siguiente acción).
   y catch(error) (maneja el error enviado desde throw). error es una instancia de Error.
*/

//1. Arrojar el error.
function queDireccion(pregunta)
{
    let resultado = prompt(pregunta);
    if(resultado.toLocaleLowerCase() === "izquierda") return "I";
    if(resultado.toLocaleLowerCase() === "derecha") return "D";
    throw new Error("Direccion Invalida: " + resultado);
}

function mirar()
{
    if(queDireccion("¿Cuál ruta?") === "I")
    {
        return "¡Mira una casa!";
    }
    else
    {
        return "¡Mira dos osos!";
    }
}

//2. Verificar si hay algún error y manejarlo.
try
{
    console.log("You see a ", mirar());
}catch(error)
{
    console.error("Ha habido un error" + error);
}

