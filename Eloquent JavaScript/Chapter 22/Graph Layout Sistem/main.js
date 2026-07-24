//Simulación de visualización de un sistema de Grafos

class Vec {
  constructor(x, y) {
    this.x = x; this.y = y;
  }
  plus(other) {
    return new Vec(this.x + other.x, this.y + other.y);
  }
  minus(other) {
    return new Vec(this.x - other.x, this.y - other.y);
  }
  times(factor) {
    return new Vec(this.x * factor, this.y * factor);
  }
  get length() {
    return Math.sqrt(this.x * this.x + this.y * this.y);
  }
}

class Graph{
    #nodes = [];
    get size(){
        return this.#nodes.length;
    }
    addNode(){
        let id = this.#nodes.length;
        this.#nodes.push(new Set());
        return id;
    }
    addEdge(nodeA, nodeB){
        this.#nodes[nodeA].add(nodeB);
        this.#nodes[nodeB].add(nodeA);
    }
    neighbors(node){
        return this.#nodes[node];
    }
}
//Devuelve una arreglo de grafos poscionados de forma aleatoria 
function randomLayout(graph)
{
    let layout = [];
    for(let i = 0; i < graph.size; i++)
    {
        layout.push(new Vec(Math.random() * 1000, Math.random() * 1000));
    }
    return layout;
}

function gridGraph(size){
    let grid = new Graph();
    for(let y = 0; y < size; y++)
    {
        for(let x = 0; x < size; x++)
        {
            let id = grid.addNode();
            if(x > 0) grid.addEdge(id, id - 1);
            if(y > 0) grid.addEdge(id, id - size);
        }
    }
    return grid;
}
