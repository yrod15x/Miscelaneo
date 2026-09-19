/* Calcula la magnitud de un vector entre el ratón y el centro del canvas,
visualizándola como una barra en la parte superior de la pantalla. */ 

function setup() {
  createCanvas(800, 600);
}

function draw() {
  background(51);

  let raton = createVector(mouseX, mouseY);
  let centro = createVector(width / 2, height / 2);

  raton.sub(centro);
  let magnitud = raton.mag();
  fill(255, 0, 0);
  rect(0, 0, magnitud, 20);
  stroke(255);
  translate(width / 2, height / 2);
  line(0, 0, raton.x, raton.y);
}
