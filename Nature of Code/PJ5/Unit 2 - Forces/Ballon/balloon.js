class Balloon{
    constructor(){
        this.position = createVector(random(20, width - 20), height - 20);
        this.velocity = createVector(0, 0);
        this.acceleration = createVector(0, 0);
    }
    update(){
        this.capSpeed();
        this.acceleration.y = -0.01;
        this.velocity.add(this.acceleration);        
        this.position.add(this.velocity);
        this.acceleration.mult(0);
    }
    show(){
        noStroke();
        fill(255, 255, 0);
        circle(this.position.x, this.position.y, 40);
    }
    checkEdges(){
        if(this.position.y <= 20){
            this.acceleration.y = 1;
            this.velocity.add(this.acceleration);
        }
        if(this.position.x >= width - 20){
            this.position.x = width - 20;
            this.velocity.x = 0;
        }
    }
    capSpeed(){
        if(this.acceleration.mag > 2){
            this.velocity.setMag(2);
        }
    }
    applyForce(force){
        this.acceleration.add(force);
    }
}
