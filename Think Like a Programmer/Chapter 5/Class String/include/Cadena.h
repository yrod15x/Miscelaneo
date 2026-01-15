#ifndef CADENA_H
#define CADENA_H

class Cadena
{
    public:
        Cadena();
        ~Cadena();
        Cadena(const Cadena& other);
        void agregar(char car);
        void mostrar();
        void borrar(char car);
        char caracterEn(int index);

    private:
        //Lista (array dinámico) que contendrá los caracteres.
        typedef char *Texto;
        //Toca decirle obligatoriamente que haga el arreglo dinámico con new
        Texto _cadena = new char;
        int getTamano();
};

#endif // CADENA_H
