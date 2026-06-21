/* Programa que muestra pestañas creadas con JavaScript y que se ponen visibles al
hacer click en sus botones de etiqueta.*/

let cuerpo = document.querySelector("body");
let unidad = document.createElement("div");
const btnAncho = 50;

for(let i = 0; i < 4; i++)
{
    let btn = document.createElement("button");
    btn.textContent = `Tab ${i+1}`;
    btn.style.position = "absolute";
    btn.style.left = `${btnAncho * (i)}px`;
    let division = document.createElement("div");
    division.classList.add("division");
    division.style.position = "absolute";
    division.style.border = "1px solid black";
    division.style.width = 90 + "dvw";
    division.style.height = 90 + "dvh";
    division.style.marginTop = 20 + "px";
    division.style.backgroundColor = `rgb(${Math.floor(Math.random() * 255)},
    ${Math.floor(Math.random() * 255)},${Math.floor(Math.random() * 255)}`;
    division.style.left = 0;
    unidad.appendChild(btn);
    unidad.appendChild(division)
    cuerpo.appendChild(unidad);
}

let divisiones = document.querySelectorAll(".division");
let tamDivs = divisiones.length;
let botones = document.querySelectorAll("button");

botones.forEach(btn =>{
    for(let i = 0; i < tamDivs; i++)
    {
        divisiones[i].style.visibility = "visible";
    }
    btn.addEventListener("click", event =>{
        let indDivs = Number(event.target.textContent[tamDivs])-1
        for(let i = 0; i < tamDivs; i++)
        {
            if(i != indDivs) 
            {
                divisiones[i].style.visibility = "hidden";
            }
            else
            {
                divisiones[i].style.visibility = "visible";
            }
            
        }
    });
});

