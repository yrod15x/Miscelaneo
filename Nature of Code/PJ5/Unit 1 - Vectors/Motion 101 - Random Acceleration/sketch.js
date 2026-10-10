let mover; 

function setup() {
  createCanvas(800, 600);
  mover = new Mover();
}

function draw() {
  background(51);

  mover.update();
  mover.checkEdges();
  mover.show();

}
