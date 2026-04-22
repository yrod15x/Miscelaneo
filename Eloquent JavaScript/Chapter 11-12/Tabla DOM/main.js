/* Crear un programa que muestre en una tabla los datos de un objeto*/

let tabla = document.querySelector("table");

let montanas = [
    {"Nombre" : "Kilinmajaro", "Altura" : 5890, "Lugar" : "Tanzania"},
    {"Nombre" : "Everest", "Altura" : 8900, "Lugar" : "Nepal"},
    {"Nombre" : "Sierra Nevada", "Altura" : 5600, "Lugar" : "Colombia",}
];
let cont = 0;
let fila = document.createElement("tr");

for(let prop in montanas[0])
{
    let cabeza = document.createElement("th");
    cabeza.innerHTML = prop;
    fila.appendChild(cabeza);
}
tabla.append(fila);
for(let montana of montanas)
{
    let fila = document.createElement("tr");
    for(let prop in montana)
    {
        let info = document.createElement("td");
        info.innerHTML = montana[prop];
        fila.appendChild(info);
    }
    tabla.appendChild(fila);
    cont++;
}

console.log(tabla);