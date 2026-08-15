/* Utiliza una distribución de probabilidad personalizada para variar el 
tamaño de un paso dado por el aleatorio Walker. El tamaño del paso puede
determinarse influyendo en el rango de valores elegidos.*/

class Walker{
    constructor(tam){
        this.x = width / 2;
        this.y = height / 2;
        this.tam = tam;
    }
    walk(){
        let velx;
        let vely;
        let step = this.#acceptReject();
        if(step < 0.8){
            velx = random(-10, 10);
            vely = random(-10, 10);
        }
        else{
            velx = random(-1 * step, 1 * step);
            vely = random(-1 * step, 1 * step);
        }
        this.x += velx;
        this.y += vely;
    }
    show(){
        noStroke();
        stroke(0);
        fill(51);
        if(this.x > width) this.x = 0;
        if(this.y > height) this.y = 0;
        if(this.x < 0) this.x = width - this.tam;
        if(this.y < 0) this.y = height - this.tam;
        circle(this.x, this.y, this.tam);
    }
    /*/Permite escoger la probabilidad que un número salga más
     que otro en un proceso aleatorio. */
    #acceptReject(){
        let r1 = 0;
        let r2 = 1;
        while(r2 > r1 * r1 / r1){
            r1 = random(1);
            r2 = random(1);
        }
        return r1;
    }
}