/*Demuestra la substracción vectorial tomando la diferencia entre dos puntos; 
la posición del mouse y el centro de la ventana */

function setup() {
  createCanvas(800, 600);
}

function draw() {
  background(51);
  let raton = createVector(mouseX, mouseY);
  let centro = createVector(width / 2, height / 2);

  stroke(200);
  strokeWeight(4);
  line(0, 0, raton.x, raton.y);
  line(0, 0, centro.x, centro.y);
  raton.sub(centro);
  stroke(255, 0, 0);
  //como el nuevo vector debe empezar donde acaba el segundo se debe trasladar el orígen 
  translate(width / 2, height / 2);
  line(0, 0, raton.x, raton.y);
}
