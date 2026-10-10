/* Clase que genera una plantilla para que un objeto se mueva por pantalla
usando vectores con una velocidad constante.*/

class Mover{
    constructor(){
        this.position = createVector(random(width), random(height));
        this.velocity = createVector(0, 0);
        this.acceleration = createVector(-0.0001, 0.01);
        this.topSpeed = 10;
    }
    update(){
        this.position.add(this.velocity);
        this.velocity.limit(this.topSpeed);
        this.velocity.add(this.acceleration);
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
    /*Permite que la velocidad no supere un valor demasiado grande al ir
    agregando la acceleración */
    limit(max){
        if(this.velocity.mag() > this.topSpeed)
        {
            //Pone la magnitud en 1, luego lo multiplica por el valor escalar
            this.velocity.normalize();
            this.velocity.mult(max);
        }
    }
}
