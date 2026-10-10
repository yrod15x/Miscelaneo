class Mover{
    constructor(mass){
        this.mass = mass;
        //Tomar la masa como escala para radio el radio del objeto mass = pi*r^2. 10 para escalar  
        this.radio = sqrt(this.mass) * 10;
        this.position = createVector(random(this.radio * 2, width), 
        random(this.radio * 2, height / 2));
        this.velocity = createVector(0, 0);
        this.acceleration = createVector(0, 0);        
    }
    applyForce(force){
        //2nda ley de Newton f = m * a
        let tempForce = p5.Vector.div(force, this.mass);        
        this.acceleration.add(tempForce);
    }
    update(){
        this.velocity.add(this.acceleration);
        this.position.add(this.velocity);
        //Limpiar la aceleración para que no se acumule
        this.acceleration.mult(0);
    }
    show(){
        stroke(0);
        fill(175);
        circle(this.position.x, this.position.y, this.radio * 2);
    }
    checkEdges(){
        //Rebotar en los bordes, como son vectores se debe actualizar posición y velocidad 
        if(this.position.x > width - this.radio){
            this.position.x = width - this.radio;
            this.velocity.x *= -1;
        }else if(this.position.x < this.radio){
            this.position.x = this.radio;
            this.velocity.x *= -1;
        }
        if(this.position.y > height - this.radio){
            this.position.y = height - this.radio;
            this.velocity.y *= -1;
        }
    }
}