const boton = document.getElementById("boton");
boton.addEventListener("click", () => {
    let lado = Math.floor(Math.random() * 100);
    let superficie = document.querySelector("#superficie");
    let ladoText = document.querySelector("#lado");
    let perimetro = document.querySelector('#perimetro');
    let volumen = document.querySelector("#volumen");
    let diagonal = document.querySelector("#diagonal");

    ladoText.innerHTML = String(lado);
    superficie.innerHTML = String(6 * (lado * lado));
    perimetro.innerHTML = String(lado * 12);
    volumen.innerHTML = String(lado * lado * lado);
    diagonal.innerHTML = String(lado * Math.sqrt(3).toFixed(2));
});
