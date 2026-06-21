class Picture
{
    constructor(width, height, pixels)
    {
        this.width = width;
        this.height = height;
        this.pixels = pixels;
    }
    static empty(width, height, color)
    {
        //Inicializar un array vacio y llenarlo con un valor
        let pixels = new Array(width * height).fill(color);
        return new Picture(width, height, pixels);
    }
    pixel(x, y)
    {
        return this.pixels[x + y * this.width];
    }
    draw(pixels)
    {
        //copiar todo el array 
        let copy = this.pixels.slice();
        for(let {x, y, color} of pixels)
        {
            copy[x + y * this.width] = color;
        }
        return new Picture(this.width, this.height, copy);
    }
}

function updateState(state, action)
{
    return {...state, ...action};
}

//Crea elementos con propiedades y elemntos hijos si los hay
function elt(type, props, ...children)
{
    let dom = document.createElement(type);
    if(props) Object.assign(dom, props);
    for(let child of children)
    {
        if(typeof child != "string") dom.appendChild(child);
        else dom.appendChild(document.createTextNode(child));
    }
    return dom; 
}

const scale = 10;
class PictureCanvas
{
    constructor(picture, pointerDown)
    {
        //Crea un elemnto canvas con dos propiedades hacer click o tocar la pantalla
        this.dom = elt("canvas", {
            onmousedown: event => this.mouse(event, pointerDown),
            ontouchstart: event => this.touch(event, pointerDown) 
        });
        this.syncState(picture);
    }
    syncState(picture)
    {
        if(this.picture == picture) return;
        this.picture = picture;
        drawPicture(this.picture, this.dom, scale);
    }
}