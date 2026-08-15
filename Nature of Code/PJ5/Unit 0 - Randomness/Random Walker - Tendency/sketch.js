/* Crea un objeto que se desplaza aleatoriamente en pantalla con tendencia hacia.
a un lado específico, usando una clase Walker*/

let walker;

function setup() {
  createCanvas(800, 600);
  walker = new Walker(400, 300);
  background(51);
}

function draw() {
  
  walker.walk();
  walker.show();
}
