/* Rellenar todos los pixeles de una ventana (perlin noise 2d es un grilla)
usando el ruido de perlin*/
let xoff = 0.0;

function setup() {
  createCanvas(800, 600);
}
/* xoff - yoff permiten ir cambiando el rango del ruido para dar aleatoriedad
más suave, al ir aumentando su valor poco a poco */ 
function draw() {
  background(51);
  loadPixels();
  for(let x = 0; x < width; x++){
    let yoff = 0.0;
    for(let y = 0; y < height; y++){
      /*Toma cada pixel de la ventana. Cada uno es un array de tamaño 4
      compuesto por red, blue, gree, alpha*/
      let index = (x + y * width) * 16;
      noiseDetail(4, 0.5);
      let bright = map(noise(xoff, yoff), 0, 1, 0, 255);      
      pixels[index] = bright;
      pixels[index + 1] = bright;
      pixels[index + 2] = (bright, bright, random(255));
      pixels[index + 3] = 255;
      yoff += 0.01; 
    }
    xoff += 0.01; 
  }
  updatePixels();
}
