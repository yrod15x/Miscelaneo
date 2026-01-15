/* Clase que crea un conjunto de elementos que no debe repetirse. Igual que la clase
Set() en otros lenguajes. Tiene tres métodos has(item) devuelve un booleano si 
el elemento esta en el conjunto, add(item) lo agrega y delete(item)  que lo  borra*/

class Group
{
    #items;
    constructor()
    {
        this.#items = [];
        this.size = 0;
    }
    add(item)
    {
        if(this.size == 0)
        {
            this.#items.push(item);
            this.size++;
        }
        else
        {
            for(let i = 0; i < this.size; i++)
            {
                if(this.#items[i] == item) break;
                if(i == this.size - 1 && this.#items[i] != item)
                {
                    this.#items.push(item);
                    this.size++;
                }
            }
        } 
    }
    show()
    {
        for(let item of this.#items)
        {
            console.log(item);
        }
    }
    has(item)
    {
        for(let it of this.#items)
        {
            if(it === item) return true;
        }
        return false;
    }
    delete(item)
    {
        for(let i = this.size; i >= 0; i--)
        {
            if(item === this.#items[i])
            {
                this.#items.splice(i, 1);
                this.size--;
            }
        }
    }
    //Se usa para extender la capacidad del constructor. No se llama como métodos de
    //las instancias de la clase, si no como métodos de la clase misma. Se llam desde
    //la clase.
    static fromArray(array)
    {
        let items = new Group();
        for(let item of array)
        {
            if(!items.has(item))
            {
             items.add(item);
            }
        }
        return items;
    }
}

let conjunto = new Group();

conjunto.add(4);
conjunto.add(9);
conjunto.add(5);
conjunto.add(5);

console.log(conjunto.has(6));

conjunto.delete(4);
//conjunto.show();

let nums = Group.fromArray([1, 2, 4, 5, 9, 2, 1]);
nums.show();
