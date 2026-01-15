#ifndef REGISTROS_H
#define REGISTROS_H


class Registros
{
    private:
        struct nodo
        {
            int id;
            int nota;
            nodo *next;
        };
    public:
        Registros();
        ~Registros();
        Registros(const Registros &otro);
        Registros& operator=(const Registros &otro);
        void agregar(int id, int nota);
        double promediar();
        void eliminar(int id);
        void mostrar();
        Registros registroEnRango(int notaMin, int notaMax);
    private:
        typedef nodo *lista;
        lista _cabeza;
        lista copiarLista(const lista otra);
        //Ayuda al destructor a limpiar el heap
        void elimiarLista(lista &listaPuntero);
};

#endif // REGISTROS_H
