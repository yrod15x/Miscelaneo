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
        void promediar();
    private:
        typedef nodo *lista;
        lista _cabeza;
        lista copiarLista(const lista otra);
};

#endif // REGISTROS_H
