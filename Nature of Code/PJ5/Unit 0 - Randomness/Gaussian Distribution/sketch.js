/*Muestra la distribución gausiana (randomGaussian()) poniendo varios círculos
 en pantalla,  alterando la desviación estandar con un slider. */

let slider;

function setup() {
  createCanvas(800, 400);
  frameRate(30);
  background(220);
  slider = createSlider(0, 100);
  slider.position(10, 420);
  slider.size(200);
}

function draw() {
  let desvStandard = slider.value();
  let x = randomGaussian(320, desvStandard);
  noStroke();
  fill(random(255), random(255), random(255), 10);
  circle(x, 120, 30);
}
