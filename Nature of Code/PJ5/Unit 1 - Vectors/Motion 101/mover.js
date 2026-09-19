class Mover{
    constructor(){
        this.position = createVector(random(width), random(height));
        this.velocity = createVector(random(-2, 2), random(-2, 2));
    }
    update(){
        this.position.add(this.velocity);
    }
    show(){
        stroke(0);
        strokeWeight(2);
        fill(197);
        circle(this.position.x, this.position.y, 48);
    }
    checkEdges(){
        //Si se sale de algún borde aparece en el opuesto
        if(this.position.x > width){
            this.position.x = 0;
        }
        else if(this.position.x < 0){
            this.position.x = width;
        }
        if(this.position.y > height){
            this.position.y = 0;
        }
        else if(this.position.y < 0){
            this.position.y = height;
        }   
    }
}