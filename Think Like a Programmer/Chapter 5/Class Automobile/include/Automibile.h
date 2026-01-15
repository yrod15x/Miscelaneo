#ifndef AUTOMIBILE_H
#define AUTOMIBILE_H
#include <iostream>

class Automibile
{
    public:
        Automibile();
        Automibile(std::string nombre, std::string modelo, int annio);
        void setNombre(std::string nombre);
        void setModelo(std::string modelo);
        void setAnnio(int annio);
        int getAnnio();
        std::string getNombre();
        std::string getModelo();
        void descripcion();
        int getEdad();

    private:
        std::string _nombre;
        std::string _modelo;
        int _annio;

};

#endif // AUTOMIBILE_H
