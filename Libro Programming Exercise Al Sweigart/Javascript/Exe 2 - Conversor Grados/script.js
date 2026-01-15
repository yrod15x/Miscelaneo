var temperatura = document.querySelector("#temp");

function calcular()
{
    let grados_iniciales = document.getElementById("grados_iniciales");
    let grados_finales = document.getElementById("grados_finales");
    let text_res = document.querySelector(".resultado");
    let grado = document.querySelector(".tipo");
    let resultado;

    if(grados_iniciales.value === "Celsius" && grados_finales.value === "Farenheit")
    {
        resultado = Number(temperatura.value) * (1.8) + 32;
        grado.innerHTML = "F°";
    }
    else if(grados_iniciales.value === "Farenheit" && grados_finales.value === "Celsius")
    {
        resultado = (Number(temperatura.value) - 32) / 1.8;
        grado.innerHTML = "C°";
    }
    text_res.innerText = resultado.toFixed(2);
    //console.log(grado.innerHTML);
    //console.log(resultado.toFixed(2));
}

function noCargar()
{
    //Evita que el formulario recargue
    event.preventDefault();
}