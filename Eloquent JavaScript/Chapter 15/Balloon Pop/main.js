/* Programa que permite inflar o desinflar un globo en pantalla, usando las teclas de arriba o abajo. 
Cuando llega a un limite explota.*/

let globo = document.querySelector("p");
let aire =  10;

window.addEventListener("keydown", (event) =>{
    if(event.key == "ArrowUp")
    {
        globo.style.fontSize = aire + "px";
        aire += 5;
        if(aire === 200)
        {
            globo.textContent = "\uD83D\uDCA5";
        }
    }
    event.preventDefault();
});

window.addEventListener("keydown", (event) => {
    if(event.key == "ArrowDown")
    {
        globo.style.fontSize = aire + "px";
        aire -= 5;
    }
    event.preventDefault();
})