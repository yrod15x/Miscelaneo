/* Caminante que va hacia donde esta el mouse*/

let walker;

function setup() {
  createCanvas(800, 600);
  background(51);
  walker = new Walker(200, 200);
}

function draw() {
  walker.walk();
  walker.show();
}
