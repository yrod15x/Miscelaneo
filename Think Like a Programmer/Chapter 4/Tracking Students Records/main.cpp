#include <iostream>

/* Una lista enlazada es un colección de datos. Que esta formada por nodos.
Y que se une mediante punteros internos que apuntan a las direcciones de
memoria de otros nodos. */

//Las estructuras son los elementos básicos y son llamados nodos
struct nodo
{
    int numEstudiante;
    int nota;
    nodo *siguiente;
};

typedef nodo *colEstudiante;

void agregarRegistro(colEstudiante &estudiantes, int numero, int nota)
{
    //Crea un nodo y lo agrega a la colección con sus respectivos parámetros
    nodo *nodoNuevo = new nodo;

    nodoNuevo->numEstudiante = numero;
    nodoNuevo->nota = nota;
    //El nodo creado queda como cabeza de los datos
    nodoNuevo->siguiente = estudiantes;
    estudiantes = nodoNuevo;
}

double promedioNotas(colEstudiante estudiantes)
{
    double suma = 0;
    int numEstudiantes = 0;

    //Se inicia apuntando al nodo cabeza. El array es representado por el 1er nodo
    nodo *temp = estudiantes;

    while(temp != nullptr)
    {
        suma += temp->nota;
        numEstudiantes++;
        //Permite desplazarse entre nodos apuntado al siguiente.
        temp = temp->siguiente;
    }
    return suma / numEstudiantes;
}

void imprimirRegistros(colEstudiante estudiantes)
{
    //int i = 0;
    nodo *actual = estudiantes;
    while(actual != nullptr)
    {
        std::cout << actual->numEstudiante << " : " << actual->nota << '\n';
        actual = actual->siguiente;
    }
    std::cout << "El promedio de todad las notas es " << promedioNotas(estudiantes);
}

int main()
{
    colEstudiante estudiantes;

    //Llegar los nodos con la información
    nodo *nodo1 = new nodo;
    nodo1->numEstudiante = 1001;
    nodo1->nota = 76;

    nodo *nodo2 = new nodo;
    nodo2->numEstudiante = 1003;
    nodo2->nota = 89;

    nodo *nodo3 = new nodo;
    nodo3->numEstudiante = 1006;
    nodo3->nota = 92;

    //El primer nodo tomará la cabeza la de la colección
    estudiantes = nodo1;

    //Conectar los nodos mediante su elemento(next). El NULL determina el final
    nodo1->siguiente = nodo2;
    nodo2->siguiente = nodo3;
    nodo3->siguiente = nullptr;

    //Limpiar la memoria
    nodo1 = nodo2 = nodo3 = nullptr;

    agregarRegistro(estudiantes, 1005, 35);
    imprimirRegistros(estudiantes);

    return 0;
}
