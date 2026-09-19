class Walker{
    constructor(){
        this.tx = 0;
        this.ty = 10000;
    }
    walk(){
        this.x = map(noise(this.tx), 0, 1, 0, width);
        this.y = map(noise(this.ty), 0, 1, 0, height);
        console.log(noise(this.tx));
        this.tx += 0.01;
        this.ty += 0.01;
    }
    show(){
        stroke(0);
        fill(220, 0, 0);
        circle(this.x, this.y, 10);
    }
}