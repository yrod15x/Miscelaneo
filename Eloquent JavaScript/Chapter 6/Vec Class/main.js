/* Programa que crea una clase Vector con sus constructor y tres propiedades sumar, restar y mostrar.
Además de tener getter y setters para encapsular sus propiedades */

class Vector
{
    #x;
    #y;
    constructor(x, y)
    {
        this.#x = x;
        this.#y = y;
    }
    getX()
    {
        return this.#x;
    }
    getY()
    {
        return this.#y;
    }
    setX(x)
    {
        this.#x = x;
    }
    setY(y)
    {
        this.#y = y;
    }
    mostrar()
    {
        console.log(`(${this.#x}, ${this.#y})`);
    }
    sumar(vec)
    {
        let resultado = new Vector;
        resultado.setX(this.#x + vec.getX());
        resultado.setY(this.#y + vec.getY());
        return resultado;
    }
    restar(vec)
    {
        let resultado = new Vector;
        resultado.setX(this.#x - vec.getX());
        resultado.setY(this.#y - vec.getY());
        return resultado;
    }
    magnitude()
    {
        return Math.sqrt((this.#x * this.#x) + (this.#y * this.#y)).toFixed(2);
    }
}

let coordenada = new Vector(3, 4);
let coordenada2 = new Vector;
coordenada2.setX(4);
coordenada2.setY(2);
coordenada = coordenada.restar(coordenada2);

coordenada.mostrar();
console.log(coordenada2.magnitude())