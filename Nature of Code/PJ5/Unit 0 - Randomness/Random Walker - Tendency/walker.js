class Walker{
    constructor(x, y)
    {
        this.x = x;
        this.y = y;
    }
    walk()
    {
        let tendency = random();
        let xstep = random();
        let ystep = random();
        
        if(tendency < 0.6)
        {
            this.x += xstep;
            this.y += ystep;
        }
        else if(tendency < 0.7)
        {
            this.x += xstep;
            this.y -= ystep;
        } 
        else if(tendency < 0.8)
        {
            this.x -= xstep;
            this.y -= ystep;
        }
        else 
        {
            this.x -= xstep;
            this.y += ystep;
        }
    }
    show()
    {
        stroke(255)      
        point(this.x, this.y);
    }
}