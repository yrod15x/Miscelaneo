/* Aplicación que simula un ecosistema acuático y aereo donde hay peces en 
el agua y un ave que vuela y busca zambullirse para alimentarse.*/

let pez;
let mundoPezW;
let mundoPezH;  

function setup() {
  createCanvas(1200, 700);
  mundoPezW = createVector(0, width);
  mundoPezH = createVector(height - height / 3, height);
  pez = new SerVivo(mundoPezW, mundoPezH, 20, [255, 165, 0]);
}

function draw() {
  background(51);
  //El agua
  noStroke();
  fill(0, 0, 180);
  rect(0, height - height / 3, width, height);
  //pescado
  pez.moverse();
  pez.mostrar();
}
