/* Persistent group
Most data structures provided in a standard JavaScript environment aren’t very well 
suited for persistent use. Arrays have slice and concat methods, which allow us 
to easily create new arrays without damaging the old one. But Set, for example, 
has no methods for creating a new set with an item added or removed.
Write a new class PGroup, similar to the Group class from Chapter 6, which stores a 
set of values. Like Group, it has add, delete, and has methods. Its add method, 
however, should return a new PGroup instance with the given member added and 
leave the old one unchanged. Similarly, delete should create a new instance 
without a given member*/

class PGroup
{
    #items;
    constructor(items)
    {
        this.#items = items;
    }
    has(item)
    {
        if(this.#items.includes(item)) return true;
        return false;
    }
    add(item)
    {
        if(!this.has(item))
        {
            let nuevo = new PGroup([]);
            nuevo.#items = this.#items.concat(item);
            return nuevo;
        }
        return this;
    }
    show()
    {
        for(let item of this.#items)
        {
            console.log(item);
        }
    }
    delete(item)
    {
        if(this.has(item))
        {
            let nuevo = new PGroup([]);
            nuevo.#items = this.#items.filter(num => num != item);
            return nuevo;
        }
        return this;
    }
}

let items = new PGroup([5, 7, 8, 9]);
let otro = items.add(1);
let otro2 = otro.delete(8);
otro2.show();

