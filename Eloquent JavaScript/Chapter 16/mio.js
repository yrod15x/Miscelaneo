//Clase que maneja los nieveles del juego
class Level
{
    //plan es la rejilla en formato string donde se poscionan los objetos inicialmente
    constructor(plan)
    {   //crea un array bidimensional donde cada fila tiene un array de caracteres(plan)
        let rows = plan.trim().split("\n").map(l => [...l]);
        this.height = rows.length;
        this.width = rows[0].length;
        /*Array que contendrá todos los elementos movibles del nivel con sus tipos
         y coordenadas */
        this.startActors = [];
        //array con los tipos de elementos (estáticos y actores) por línea
        this.rows = rows.map((row, y) => {
            return row.map((ch, x) => {
                /* Que tipo de elemento es (levelChars es un objeto que cuyas propiedades
                son los caracteres y sus valores asociados son sus tipos Player, Coin..).
                */
                let type = levelChars[ch];
                //Separa movibles de estáticos. Estos ultimos serán tipo String
                if(typeof type != "string")
                {
                    //Clase alterna que guardará las posciones como coordenadas
                    let pos = new Vec(x, y);
                    /* type.create es una función de las clases alternas Player, 
                    Lava, Coin que crea su tipo dentro del objeto levelChars */
                    this.startActors.push(type.create(pos, ch));
                    type = "empty"; 
                }
                return type;   
            });
        });
    }
}
//Método de la clase nivel que mira si un objeto entra en contacto con otro
Level.prototype.touches = function(pos, size, type)
{
    //Crea un halo externo al objeto para saber que celdas toca a su alrededor
    let xStart = Math.floor(pos.x);
    let xEnd = Math.ceil(pos.x + size.x);
    let yStart = Math.floor(pos.y);
    let yEnd = Math.ceil(pos.y + size.y);

    //Comprueba si el objeto toca las paredes u otro actor, mirando las celdas alrededor
    for(let y = yStart; y < yEnd; y++)
    {
        for(let x = xStart; x < xEnd; x++)
        {
            let isOutside = x < 0 || x >= this.width ||
                            y < 0 || y >= this.height;
            let here = isOutside ? "wall" : this.rows[y][x];
            if(here == type) return true;
        }
    }
    return false;
};

//Clase que maneja el cambio de posción y estado de los actores
class State
{
    constructor(level, actors, status)
    {
        this.level = level;
        this.actors = actors;
        this.status = status;
    }
    //Modfica el constructor cuando solo se necesite pasarle el nivel inicial
    static start(level)
    {
        return new State(level, level.startActors, "playing");
    }
    get player()
    {
        return this.actors.find(a => a.type == "player");
    }
}
//Método para determinar si el jugador toca la lava. (tiempo transcurrido, teclas)
State.prototype.update = function(time, keys)
{
    //Registra las nuevas posciones y estados de los actores
    let actors = this.actors.map(actor => actor.update(time, this, keys));
    let newState = new State(this.level, actors, this.status);
    //Si no esta el juego activo actualiza todo
    if (newState.status != "playing") return newState;
    //Comprueba si el actor toca la lava
    let player = newState.player;
    if(this.level.touches(player.pos, player.size, "lava"))
    {
        return new State(this.level, actors, "lost");
    }
    //Comprobar si el jugador toca otro objeto
    for(let actor of actors)
    {
        if(actor != player && overlap(actor, player))
        {
            newState = actor.collide(newState);
        }
    }
};
//Dos actores se tocan
function overlap(actor1, actor2)
{
    return actor1.pos.x + actor1.size.x > actor2.pos.x &&
           actor1.pos.x < actor2.pos.x + actor2.size.x &&
           actor1.pos.y + actor1.size.y > actor2.pos.y &&
           actor1.pos.y < actor2.pos.y + actor2.size.y;
}

//Clase que maneja las coordenadas dadas en forma de vectores
class Vec
{
    constructor(x, y)
    {
        this.x = x;
        this.y = y;
    }
    plus(other)
    {
        return new Vec(this.x + other.x, this.y + other.y);
    }
    //Escaelar veccror por una magnitud
    times(factor)
    {
        return new Vec(this.x * factor, this.y * factor);
    }
}

/*Clase que controla la posición, velocidad y tamano del jugador. Además de la
 función estática create que ayuda a crear un jugador basado en un caracter y su 
 posición en la rejilla plan de la clase Level*/ 
class Player
{
    constructor(pos, speed)
    {
        this.pos = pos;
        this.speed = speed;
    }
    get type(){return "player";}
    static create(pos)
    {
        //El alto del jugador es 1.5 por eso debe posicionarse a -0.5 para quedar en el suelo
        return new Player(pos.plus(new Vec(0, -0.5)), new Vec(0, 0));
    }
}
//Propiedad tamaño de la clase Player
Player.prototype.size = new Vec(0.8, 1.5);
//Moviento del jugador
const playerXSpeed = 7;
const gravity = 30;
const jumpSpeed = 17;

Player.prototype.update = function(time, state, keys)
{
    let xSpeed = 0;
    //moverse a derecha o izquierda
    if(keys.ArrowLeft) xSpeed -= playerXSpeed;
    if(keys.ArrowRight) xSpeed += playerXSpeed;
    let pos = this.pos;
    let movedX = pos.plus(new Vec(xSpeed * time, 0));
    //Revisar colisiones
    if(!state.level.touches(movedX, this.size, "wall"))
    {
        pos = movedX;
    }
    //Moverse verticalmente, saltar o caer
    let ySpeed = this.speed.y + time * gravity;
    let movedY = pos.plus(new Vec(xSpeed * time, 0));
    if(!state.level.touches(movedX, this.size, "wall"))
    {
        pos = movedY;
    }
    //Permite saltar si hay obstáculo
    else if(keys.ArrowUp && ySpeed> 0)
    {
        ySpeed -= jumpSpeed;
    }
    //caer
    else
    {
        ySpeed = 0;
    }
    return new Player(pos, new Vec(xSpeed, ySpeed));
};

class Lava
{
    constructor(pos, speed, reset)
    {
        this.pos = pos;
        this.speed = speed;
        this.reset = reset;
    }
    get type() {return "lava";}
    static create(pos, ch)
    {
        if(ch == "=")
        {
            //Se mueve lateralmente
            return new Lava(pos, new Vec(2, 0))
        }
        else if(ch == "|")
        {
            //Se mueve de arriba a abajo
            return new Lava(pos, new Vec(0, 2))
        }
        else if(ch == "v")
        {
            //Se mueve lateralmente pero se devuelve a su inicial al tocar eje
            return new Lava(pos, new Vec(0, 3), pos)
        }
    }
}
Lava.prototype.size = new Vec(1, 1);
//Game over si tocas colisonas con la lava 
Lava.prototype.collide = function(state)
{
    return new State(state.level, state.actors, "lost");
};
Lava.prototype.update = function(time, state)
{
    let newPos = this.pos.plus(this.speed.times(time));
    //Si no se estrella se mueve a la nueva posición 
    if(!state.level.touches(newPos, this.size, "wall"))
    {
        return new Lava(newPos, this.speed, this.reset);
    }
    //Si hay choque lava vuelve a su lugar original
    else if(this.reset)
    {
        return new Lava(this.reset, this.speed, this.reset);
    }
    //Choque, lava que rebota
    else
    {
        return new Lava(this.pos, this.speed.times(-1));
    }
};

class Coin
{
    //La moneda tendrá un movimiento de temblor
    constructor(pos, basePos, wobble)
    {
        this.pos = pos;
        this.basePos = basePos;
        this.wobble = wobble;
    }
    get type() {return "coin";}
    static create(pos)
    {
        let basePos = pos.plus(new Vec(0.2, 0.1));
        return new Coin(basePos, basePos, Math.random() * Math.PI * 2);
    }
}
Coin.prototype.size = new Vec(0.6, 0.6);
//Las monedas desaparecen al ser tocadas, nivel ganado al tocar la última moneda
Coin.prototype.collide = function(state)
{
    let filtered = state.actors.filter(a => a != this);
    let status = state.status;
    //Si no quedan monedas se gana
    if(!filtered.some(a => a.type == "coin")) status = "won";
    return new State(state.level, filtered, status);
};
//Movimiento de la moneda - Sacudido
const wobbleSpeed = 8, wobbleDist = 0.07;
Coin.prototype.update = function(time)
{
    let wobble = this.wobble + time * wobbleSpeed;
    let wobblePos = Math.sin(wobble) * wobbleDist;
    return new Coin(this.basePos.plus(new Vec(0, wobblePos)), this.basePos, wobble);
}

//Caracteres de referencia para la construcción del nivel
const levelChars = {
    ".": "empty",
    "#": "wall",
    "+": "lava",
    "@": Player,
    "o": Coin,
    "=": Lava,
    "|": Lava,
    "v": Lava, 
};

//Función asistente que crear elementos, asigna atributos y agregar nodos hijo
function elt(name, attrs, ...children)
{
    let dom = document.createElement(name);
    for(let attr of Object.keys(attrs))
    {
        dom.setAttribute(attr, attrs[attr]);
    }
    for(let child of children)
    {
        dom.appendChild(child);
    }
    return dom;
}

//Clase que muestra el juego en la página que recibe un nodo padre y como es el nivel(en cada uno de sus estados)
class DOMDisplay
{
    constructor(parent, level)
    {
        this.dom = elt("div", {class: "game"}, drawGrid(level));
        //Hace seguimiento de los actores para poder manipularlos y actualizarlos
        this.actorLayer = null;
        parent.appendChild(this.dom);
    }
    clear() {this.dom.remove();}
}
//Función de la clase que actualiza los actores en pantalla. Los borra y los vuelve a dibujar
DOMDisplay.prototype.syncState = function(state)
{
    if(this.actorLayer) this.actorLayer.remove();
    this.actorLayer = drawActors(state.actors);
    this.dom.appendChild(this.actorLayer);
    //Para estilizar el actor dependiendo del estado
    this.dom.className = `game ${state.status}`;
    this.scrollPlayerIntoView(state);
}
//Hacer posible que se pueda usar el scroll en pantalla si esta es muy pequeña
DOMDisplay.prototype.scrollPlayerIntoView = function(state)
{
    let width = this.dom.clientWidth;
    let height = this.dom.clientHeight;
    let margin = width / 3;

    //The viewport
    let left = this.dom.scrolLeft, right = left + width;
    let top = this.dom.scrollTop, bottom = top + height;

    let player = state.player;
    let center = player.pos.plus(player.size.times(0.5)).times(scale);

    if(center.x < left + margin)
    {
        this.dom.scrolLeft = center.x - margin;
    }
    else if(center.x > right - margin)
    {
        this.dom.scrolLeft = center.x + margin - width;
    }

    if(center.y < top + margin)
    {
        this.dom.scrollTop = center.y - margin;
    }
    else if(center.y > bottom - margin)
    {
        this.dom.scrollTop = center.y + margin - height;
    }
}

/*Función que reproduce el nivel en forma de tabla, tomando cada linea del string (nivel) como sus filas <tr>
Tiene un escalado para que los objetos luzcan más grandes. */
const scale = 20;

function drawGrid(level)
{
    return elt("table", {
        class: "background",
        style: `width: ${level.width * scale}px`},
        ...level.rows.map(row =>
        elt("tr", {style: `height: ${scale}px`},
            ...row.map(type => elt("td", {class: type})))
        ));
}

//Crea los actores -div- con sus dimensiones y coordenadas
function drawActors(actors)
{
    return elt("div", {}, ...actors.map(actor => {
        let rect = elt("div", {class: `actor ${actor.type}`});
        rect.style.width = `${actor.size.x * scale}px`;
        rect.style.height = `${actor.size.y * scale}px`;
        rect.style.left = `${actor.pos.x * scale}px`;
        rect.style.top = `${actor.pos.y * scale}px`;
        return rect;
    }));
}

//Registrar las teclas presionadas
function trackKeys(keys)
{
    let down = Object.create(null);
    function track(event)
    {
        //Si se presiona una tecla
        if(keys.includes(event.key))
        {
            //registra un booleano al presionar la tecla
            down[event.key] = event.type == "keydown";
            event.preventDefault();
        }
    }
    window.addEventListener("keydown", track);
    window.addEventListener("keyup", track);
    return down;
}

const arrowKeys = trackKeys(["ArroeLeft", "ArrowRight", "ArrowUp"]);

//Ayuda a correr el juego cuadro por cuadro usando la función requestAnimationFrame()
function runAnimation(frameFunc)
{
    let lastTime = null;
    function frame(time)
    {
        if(lastTime != null)
        {
            //Delimitar el tiempo max que puede correr un cuadro. Se divide por mil para volverlo segundos
            let timeStep = Math.min(time - lastTime, 100) / 1000;
            //Para la animación
            if(frameFunc(timeStep) === false) return;
        }
        lastTime = time;
        requestAnimationFrame(frame);
    }
    requestAnimationFrame(frame);
}

function runLevel(level, Display)
{
    let display = new Display(document.body, level);
    let state = State.start(level);
    let ending = 1;
    return new Promise(resolve => {
        runAnimation(time => {
            state = state.update(time, arrowKeys);
            display.syncState(state);
            if(state.status == "playing")
            {
                return true;
            }
            else if(ending > 0)
            {
                ending -= time;
                return true;
            }
            else
            {
                display.clear();
                resolve(state.status);
                return false;
            }
        });
    });
}

async function runGame(plans, Display) 
{
    for(let level = 0; level < plans.length;)
    {
        let status = await runLevel(new Level(plans[level]), Display);
        if(status == "won") level++;
    }
}