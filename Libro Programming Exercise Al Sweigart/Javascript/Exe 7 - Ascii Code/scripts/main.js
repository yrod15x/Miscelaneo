const comentario = document.querySelector("textarea");
const boton = document.querySelector("button");
const textoAscii =  document.querySelector(".textoAscii");

boton.addEventListener("click", ()=>
{
    //La propiedad value permite extraer el contenido del textarea
    let transformado = "";
    let texto = comentario.value;
    for(let i = 0; i < texto.length; i++)
    {
        if(texto[i] === " ") 
        {
            transformado += " ";
        }
        else
        {
            transformado += (texto[i].charCodeAt(0)).toString();
            if(i < texto.length - 1 && texto[i + 1] != " ") transformado += "-";
        }   
    }
    comentario.value = "";
    textoAscii.textContent = transformado;
});