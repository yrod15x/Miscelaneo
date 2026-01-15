/* Write a function compareRobots that takes two robots (and their starting memory). 
It should generate 100 tasks and let each of the robots solve each of these tasks.*/

const roads = ["Alice's House-Bob's House", "Alice's House-Cabin",
    "Alice's House-Post Office", "Bob's House-Town Hall",
    "Daria's House-Ernie's House", "Daria's House-Town Hall",
    "Ernie's House-Grete's House", "Grete's House-Farm",
    "Grete's House-Shop", "Marketplace-Farm",
    "Marketplace-Post Office", "Marketplace-Shop",
    "Marketplace-Town Hall", "Shop-Town Hall"
];

function buildGraph(edges)
{
    /*Crea un objeto con las conecciones entre todos los nodos. Caminos que unen lugares.
    Toma una lista de con las conexiones separaras por -*/
    let graph = Object.create(null);
    function addEdge(from, to)
    {
        if(from in graph)
        {
            graph[from].push(to);
        }
        else
        {
            graph[from] = [to];
        }
    }
    for(let [from, to] of edges.map(r => r.split("-")))
    {
        addEdge(from, to);
        addEdge(to, from);
    }
    return graph;
}

const roadGraph = buildGraph(roads);

class VillageState
{
    /*Devuelve el nuevo estado del pueblo una vez los paquetes son entregados y el robot se ha
    movido. Es decir cuál es la nueva posción del robot y los paquetes que falta por entregar.*/
    constructor(place, parcels)
    {
        this.place = place;
        this.parcels = parcels;
    }
    move(destination)
    {
        //Si no existe un camino que conecte no hay cambio.
        if(!roadGraph[this.place].includes(destination))
        {
            return this;
        }
        else
        {
            //Mueve al robot(map) y entrega los paquetes(filter): Sacalos del array.
            let parcels = this.parcels.map(p => {
            if (p.place != this.place) return p;
            return {place: destination, address: p.address};
            }).filter(p => p.place != p.address);
            return new VillageState(destination, parcels);
        }
    }
}

/*Función que hace que el robot entregue todos los paquetes. Teniendo en cuenta los lugares 
del pueblo antes (state)  después de entregar(memory). robot es una función que devuelve
el lugar donde debe moverse como objeto.*/
function runRobot(state, robot, memory)
{
    for(let turn = 0;; turn++)
    {
        //Cuantos turnos empleó para entregar el paquete
        if(state.parcels.length == 0)
        {
            //console.log(`Done in ${turn} turns`);
            return turn;
        }
        //Donde debe ir el robot
        let action = robot(state, memory);
        //Estado del pueblo una vez visitado determinado lugar.
        state = state.move(action.direction);
        //(Donde esta el robot)
        memory = action.memory;
        //console.log(`Moved to ${action.direction}`);
    }
}

/*POSIBLES SOLUCIONES: 
1. Aleaotoria. 
2. Ruta conectada. 
3. Buscar la ruta más corta
*/

//Funciones aleatoria para simular y comprobar los movimientos. Determinar donde ir.
function randomPick(array)
{
    let choice = Math.floor(Math.random() * array.length);
    return array[choice];
}

//1. Crear los viajes del robot de manera aleatoria
function randomRobot(state)
{
    return {direction: randomPick(roadGraph[state.place])};
}

//2. Crear los viajes mediante una ruta que conecta todo el pueblo
const mailRoute = [
  "Alice's House", "Cabin", "Alice's House", "Bob's House",
  "Town Hall", "Daria's House", "Ernie's House",
  "Grete's House", "Shop", "Grete's House", "Farm",
  "Marketplace", "Post Office"
];

/* Cada vez que deje un paquete la ruta (los lugares a visitar) se va acortando 
de  1 en 1 (slice(1)). Y este lugar donde se dejó el paquete queda como inicio de la 
nueva ruta*/
function routeRobot(state, memory)
{
    //Carga la ruta en el inicio del viaje del robot
    if(memory.length == 0)
    {
        memory = mailRoute;
    }
    return {direction: memory[0], memory: memory.slice(1)};
}

//3. Buscando la ruta más rápida dentro de varias posiblidades.
/* Crea varias rutas descartando las que no partan de donde esta el robot, ni 
las que pasan por un mismo lugar dos veces. Va explorando varias rutas llegando
al siguiente y mirando si es el objetivo */
function findRoute(graph, from, to) {
  let work = [{at: from, route: []}];
  for (let i = 0; i < work.length; i++) {
    let {at, route} = work[i];
    for (let place of graph[at]) {
      if (place == to) return route.concat(place);
      if (!work.some(w => w.at == place)) {
        work.push({at: place, route: route.concat(place)});
      }
    }
  }
}

/* Encuentra la ruta donde recoger el paquete y a donde llevarla. Partiendo siempre de
la primera en fila.*/
function goalOrientedRobot({place, parcels}, route) {
  if (route.length == 0) {
    let parcel = parcels[0];
    if (parcel.place != place) {
      route = findRoute(roadGraph, place, parcel.place);
    } else {
      route = findRoute(roadGraph, place, parcel.address);
    }
  }
  return {direction: route[0], memory: route.slice(1)};
}

/* Crear cuantos paquetes y a donde entregarlos. Siempre inicia desde el Post Office */
VillageState.random = function(parcelCount = 5)
{
    //Tareas. Ex -> [Alice house - farm]
    let parcels = [];
    for(let i = 0; i < parcelCount; i++)
    {
        let address = randomPick(Object.keys(roadGraph));
        //Para que no llegue al mismo lugar donde sale
        let place;
        do
        {
            place = randomPick(Object.keys(roadGraph));
        }while(place == address);
        parcels.push({place, address});
    }
    return new VillageState("Post Office", parcels);
};


function compareRobots(routeRobot, [], randomRobot, [])
{
    let robot1Sum = 0;
    let robot2Sum = 0;
    let tareas = VillageState.random();
    
    for(let i = 0; i < 100; i++)
    {
        robot1Sum += runRobot(tareas, routeRobot, []);
        robot2Sum += runRobot(tareas, randomRobot, [])
    }
    console.log(`El promedio del turnos del robot 1 es ${robot1Sum / 100}`);
    console.log(`El promedio del turnos del robot 1 es ${robot2Sum / 100}`);
}

compareRobots(routeRobot, [], randomRobot, []);