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
