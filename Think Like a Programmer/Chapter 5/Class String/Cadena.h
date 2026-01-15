#ifndef CADENA_H
#define CADENA_H
#include <string>

class Cadena
{
    public:
        Cadena();
        Cadena(const std::string &otra);
        ~Cadena();
        Cadena(Cadena &otra);
        void agregar(char car);
        void mostrar();
        void concadenar(Cadena &otra);
        char caracterEn(int index);
        int getTamano();
        Cadena& operator=(const Cadena rhs);
        char& operator[](int index);
        void borrar(int inicio, int limFinal);

    private:
        //Lista (array dinámico) que contendrá los caracteres.
        typedef char *Texto;
        //Toca decirle obligatoriamente que haga el arreglo dinámico con new
        Texto _cadena = new char;
        void _rellenar(Texto &temp, int tamano);
};

#endif // CADENA_H
