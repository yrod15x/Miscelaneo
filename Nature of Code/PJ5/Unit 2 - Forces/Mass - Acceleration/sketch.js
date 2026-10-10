/**
 * Simulación de tres objetos en un lienzo de 800 × 600.
 *
 * En cada fotograma, aplica gravedad proporcional a la masa de cada objeto
 * para que todos caigan con la misma aceleración. Mientras el mouse está
 * presionado, también aplica una fuerza de viento hacia la derecha. Los
 * objetos actualizan su movimiento, comprueban los límites del lienzo y se
 * dibujan sobre un fondo gris oscuro.
 *
 * Requiere la biblioteca p5.js y una clase `Mover` que implemente los métodos
 * `applyForce()`, `checkEdges()`, `update()` y `show()`.
 */

let movers = [];

function setup() {
  createCanvas(800, 600);
  for(let i = 0; i < 3; i++){
    movers[i] = new Mover(random(1, 10));
  }  
  forceWalls = createVector(5, 0); 
 }

function draw() {
  background(51);
  let gravity = createVector(0, 0.1);
  //Gravedad
  for(let mover of movers){
    //Escalar la gravedad de acuerdo a la masa del objeto. Si sueltas 2 objetos deben caer igual. 
    let tempGravity = p5.Vector.mult(gravity, mover.mass);  
    mover.applyForce(tempGravity);
    //Viento al aplicar el mouse. Depende de donde este el ratón así sopla el viento 
    if(mouseIsPressed){
      let wind = createVector(0, 0);
      (mouseX < width / 2) ? wind.x = 0.1 : wind.x = -0.1;
      mover.applyForce(wind);
    }
        
    mover.checkEdges();
    mover.update();
    mover.show();
  }  
}
