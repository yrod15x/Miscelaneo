/* Clase base que crea los seres del ecosistema*/

class SerVivo{
    /*los parámetros del constructor son dos vectores  que poseen las 
    dimensiones donde se puede habitar */ 
    constructor(mundoW, mundoH, tamano = 5, colour, velMaxima = 1){
        this.posicion = createVector(random(mundoW.x, mundoW.y), 
                                     random(mundoH.x, mundoH.y))
        this.tamano = tamano;
        this.colour = colour;
        this.velocidad =  createVector(0, 0);
        this.aceleracion = createVector(0, 0);
        this.velMaxima = velMaxima;
        this.limVertical = mundoH;
        this.limHorizontal = mundoW;
        this.tx = 0;
        this.ty = 10000;                                    
    }
    mostrar(){
        fill(this.colour[0], this.colour[1], this.colour[2]);
        circle(this.posicion.x, this.posicion.y, this.tamano);
    }
    moverse(){
        this.limitarHabitad();
        this.aceleracion.x = map(noise(this.tx), 0, 1, -2, 2);
        this.aceleracion.y = map(noise(this.ty), 0, 1, -2, 2) 
        this.aceleracion.mult(random(2));
        this.limitarVel();
        this.velocidad.add(this.aceleracion);
        this.posicion.add(this.velocidad);
        this.tx += 0.01;
        this.ty += 0.01;        
    }
    limitarVel(){
        //debido a la aceleracción aumenta la velocidad, se debe capar. 
        if(this.velocidad.mag() > this.velMaxima){
            this.velocidad.normalize();
            this.velocidad.mult(this.velMaxima);
        }
    }
    limitarHabitad(){
        /*Si se sale de algún borde aparece en el opuesto. Se debe alterar la posición
        también para que haga el giro en la otra dirección*/
        const limRadio = this.tamano / 2;
        const maxLimX = this.limHorizontal.y - limRadio;
        const minLimX = this.limHorizontal.x + limRadio;
        const maxLimY = this.limVertical.y - limRadio;
        const minLimY = this.limVertical.x + limRadio;         
        if(Math.floor(this.posicion.x) >= maxLimX){
            this.posicion.x = maxLimX;
            this.velocidad.x *= -1;            
        }
        if(Math.floor(this.posicion.x) <= minLimX ){
            this.posicion.x = minLimX;            
            this.velocidad.x *= -1;           
        }
        if(Math.floor(this.posicion.y) >= maxLimY){
            this.posicion.y = maxLimY; 
            this.velocidad.y *= -1;
        }
        if(Math.floor(this.posicion.y) <= minLimY){
            this.posicion.y = minLimY;
            this.velocidad.y *= -1;
        }   
    }          
    
}