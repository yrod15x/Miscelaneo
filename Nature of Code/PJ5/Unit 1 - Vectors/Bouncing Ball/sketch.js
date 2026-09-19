
const winWidth = 800;
const winheight = 600;
let position;
let velocity;
let ballSize;  

function setup() {
  createCanvas(winWidth, winheight);
  position = createVector(random(0, winWidth), random(0, winheight));
  velocity = createVector(2.5, 2);
  ballSize = 40;
}

function draw() {
  background(51);
  position.add(velocity);

  //Rebotar en los bordes
  if(position.x > width - (ballSize / 2) || position.x < ballSize / 2){
    velocity.x *= -1; 
  }
  if(position.y > height - (ballSize / 2) || position.y < ballSize / 2){
    velocity.y *= -1; 
  }

  stroke(0);
  fill(255, 0, 0);
  circle(position.x, position.y, ballSize);
}
