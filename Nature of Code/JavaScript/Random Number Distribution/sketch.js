/* Muestra en forma de gráfico de barras la frecuencia de aparición de números 
aleatorios*/

let contadorAleatorio = [];
let total = 20; 

function setup() {
  createCanvas(800, 600);
  for(let i = 0; i < total; i++)
  {
    contadorAleatorio[i] = 0;
  }
}

function draw() {
  background(51);
  
  let index = floor(random(contadorAleatorio.length));
  let ancho = width / contadorAleatorio.length;

  contadorAleatorio[index]++;
  stroke(255);
  fill(127);

  for(let x = 0; x < contadorAleatorio.length; x++)
  {
    rect(x * ancho,height - contadorAleatorio[x], ancho - 1,contadorAleatorio[x]);
  }
}
