class Walker{
    constructor(x, y){
        this.x = x;
        this.y = y;
    }
    walk(){
        if(mouseX > this.x){
            this.x++;          
        }
        else{
            this.x--;
        }
        if(mouseY > this.y){
                this.y++;
        }
        else{
            this.y--;
        }
    }
    show(){
        stroke(255);
        circle(this.x, this.y, 10);
    }
}