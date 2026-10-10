/* Clase que genera una plantilla para que un objeto se mueve hacia el mouse
usando vectores con una aceleración constante. EL objeto debe cambiar su dirección
restando la posición del mouse con la propia.*/

class Mover{
    constructor(){
        this.position = createVector(random(width), random(height));
        this.velocity = createVector(0, 0);
        this.acceleration = createVector(0, 0);
        this.topSpeed = 10;
        this.color =  [random(255), random(255), 100]
        this.accScale = random(0, 1);
    }
    update(){
        let mouse = createVector(mouseX, mouseY);
        //Calcular la dirección hacia al mouse. Se necesita un método estático para generar un
        // vector nuevo 
        let dir = p5.Vector.sub(mouse, this.position);
        //Para poder tener una aceleración controlada, se debe normalizar y multiplicar por un escalar
        dir.normalize();
        dir.mult(this.accScale);
        this.acceleration = dir;
        this.velocity.add(this.acceleration);
        this.velocity.limit(this.topSpeed);  
        this.position.add(this.velocity);       
    }
    show(){
        stroke(0);
        strokeWeight(2);
        fill(this.color[0], this.color[1], this.color[2]);
        circle(this.position.x, this.position.y, 35);
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
