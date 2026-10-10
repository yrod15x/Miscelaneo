let movers = []; 

function setup() {
  createCanvas(800, 600);
  for(let i = 0; i < 5; i++)
  {
    movers[i] = new Mover();
  }
  
}

function draw() {
  background(51);

  for(let mover of movers)
  {
    mover.update();
    mover.checkEdges();
    mover.show();
  } 

}
