/* Utiliza una distribución de probabilidad personalizada para variar el 
tamaño de un paso dado por el aleatorio Walker. El tamaño del paso puede
 determinarse influyendo en el rango de valores elegidos.*/
 
let walker; 

function setup() {
  createCanvas(800, 600);
  walker = new Walker(5)
  background(240);
}

function draw() {
  walker.walk();
  walker.show();
}
