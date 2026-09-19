let walker;
function setup() {
  createCanvas(800, 600);
  walker = new Walker();
  background(21);
}

function draw() {
  
  walker.walk();
  walker.show();
}
