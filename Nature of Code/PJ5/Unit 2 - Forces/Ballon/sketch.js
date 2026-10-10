let ballon;

function setup() {
  createCanvas(400, 400);
  ballon = new Balloon;
}

function draw() {
  background(51);
  ballon.update();
  ballon.checkEdges();
  ballon.show();
  if(mouseIsPressed){
    let wind = createVector(0.1, 0);
    ballon.applyForce(wind);
  }
}

