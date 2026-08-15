class Walker{
    constructor(x, y)
    {
        this.x = x;
        this.y = y;
    }
    walk()
    {
        //Caminar en 4 direcciones
        /* let stepDir = floor(random(0, 4));
        switch(stepDir)
        {
            case 0:
                this.x += 1;
            break;
            case 1:
                this.x -= 1;
            break;
            case 2:
                this.y += 1;
            break;
            case 3:
                this.y -= 1;
            break;    
        } */

        //Caminar en 9 direcciones, X y Y pueden moverse -1, 0, 1
        let xstep = floor(random(3)) - 1;
        let ystep = floor(random(3)) - 1;

        //Caminar en cualquier dirección pero en distancias decimales entre -1 y 1
        /* 
        let xstep = random(-1, 1);
        let ystep = random(-1, 1); 
        */
        
        this.x += xstep;
        this.y += ystep;
    }
    show()
    {
        stroke(255)      
        point(this.x, this.y);
    }
}