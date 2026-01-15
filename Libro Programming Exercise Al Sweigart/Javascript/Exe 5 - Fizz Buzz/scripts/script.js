const btnNumAleatorio = document.getElementById("generate");
//Habilitar los botones de opción
const btnsOpcion = document.getElementsByName("option");
const puntaje = document.querySelector(".score");
let tiempo = document.querySelector(".timer");
const puntos = document.querySelector("#puntos");
const btnReload = document.getElementById("reload");

function actualizarBotones(onOff, color = "#f9f7f1")
{
    for(let btn of btnsOpcion)
    {
        btn.disabled = onOff;
        btn.style.backgroundColor = color;
    }
}

function actualizar(boton, num, numDivisor)
{
    boton.onclick = () => {
        if(num %  numDivisor == 0)
        {
            puntaje.textContent = (Number(puntaje.textContent) + 1);
            boton.style.backgroundColor = "green";
        }
        else
        {
            puntaje.textContent = (Number(puntaje.textContent) - 1);
            boton.style.backgroundColor = "red";
        }
        for(let btn of btnsOpcion)
        {
            btn.disabled = true;
        }
    };

}

function generarNumero()
{
    let numero;
    do{
        numero = Math.floor(Math.random() * 100);
    }while(numero == 0);
    return numero;
}

var numero = generarNumero();
var timer;
//Pone el número aleatorio en pantalla.
btnNumAleatorio.addEventListener("click", () => 
{
    //Hacer que el número no sea 0
    numero = generarNumero();
    let numText = document.querySelector(".numero");
    numText.textContent = numero;

    actualizarBotones(false);
    
    actualizar(btnsOpcion[0], numero, 3);
    actualizar(btnsOpcion[1], numero, 5);
    actualizar(btnsOpcion[2], numero, 15);
    btnsOpcion[3].onclick = () => {
        if(numero % 3 != 0 && numero % 5 != 0)
        {
            puntaje.textContent = (Number(puntaje.textContent) + 1);
            btnsOpcion[3].style.backgroundColor = "green";
        }
        else
        {
            puntaje.textContent = (Number(puntaje.textContent) - 1);
            btnsOpcion[3].style.backgroundColor = "red";
        }
        for(let btn of btnsOpcion)
        {
            btn.disabled = true;
        }
    };
});

let tiempoSegundos = ()=>
{
    let segundos = 59;
    timer = setInterval(()=> {
        tiempo.textContent = segundos.toString();
        if(segundos == 0)
        {
            clearInterval(timer);
            actualizarBotones(true, "black");
            btnNumAleatorio.style.backgroundColor = "black";
            btnNumAleatorio.disabled = true;
            puntos.textContent = `You got ${puntaje.innerText} points.`;
            btnReload.style.backgroundColor = "#f9f7f1";
            btnReload.disabled = false;
        }
        segundos--;
    }, 1000)
}
tiempoSegundos();

btnReload.addEventListener("click", () => {
    location.reload();
});

