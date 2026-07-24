let fecha = document.querySelector(".fecha");
let dat = new Date();
fecha.textContent = dat.getFullYear();
const btn = document.querySelector("button");

function contarPalabra(palabra, texto)
{  
    let cont = 0;
    for(let pal of texto)
    {
        if(pal === palabra) cont++;
    }    
    return cont;  
}

function frecuencia(texto, signo)
{
    texto = texto.toLowerCase();
    let textoCrudo = texto.replace(/[^\w\s]+/g, "");
    let pals = textoCrudo.split(" ");  
    let palestat = "";
    let data = {};

    if(signo === ">")
    {
        let estat = 0;
        for(let pal of pals)
        {
            let cont = contarPalabra(pal, pals);
            if(cont > estat)
            {
                estat = cont;
                palestat = pal;
            }    
        }
        data["palabra"] = palestat;
        data["contador"] = estat;
    }
    else if(signo === "<")
    {
        let estat = texto.length;
        for(let pal of pals)
        {
            let cont = contarPalabra(pal, pals);
            if(cont < estat)
            {
                estat = cont;
                palestat = pal;
            }    
        }
        data["palabra"] = palestat;
        data["contador"] = estat;
    }    
    return data; 
}

btn.addEventListener("click", () =>
{
    //Para que no recargue la página enseguida
    event.preventDefault();
    const archivo = document.querySelector("input");
    const lector = new FileReader();
    let contenido;
    let texto = document.querySelector(".texto");
    let numPalbras = document.querySelector(".num-palabras");
    let masFrecuente = document.querySelector(".mas-frecuente");
    let menosFrecuente = document.querySelector(".menos-frecuente");
    let masAparicion = document.querySelector(".mas-apariciones");
    let menosAparicion = document.querySelector(".menos-apariciones");
    let infos = document.querySelector(".datos").style.visibility = "visible";
    console.log(infos);
    
    //Una vez se lea el archivo, este acción cargará su contenido .
    lector.addEventListener("load", (event) =>
    {
        //Acceder al contenido del archivo
        let contenido = event.target.result;
        texto.textContent = contenido;
        numPalbras.textContent = contenido.length;
        let masfrec = frecuencia(contenido, ">");
        let menfrec = frecuencia(contenido, "<");
        masFrecuente.textContent = masfrec.palabra;        
        menosFrecuente.textContent = menfrec.palabra;
        masAparicion.textContent = masfrec.contador;
        menosAparicion.textContent = menfrec.contador;
          
          
    });
    lector.readAsText(archivo.files[0]);
});



