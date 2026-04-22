#include <iostream>
#include <list>
#include <fstream>
#include <string>

std::list<std::string> extraerPalabrasArch(char *nomArchivo)
{
    std::ifstream palArchivo;
    std::string palabra;
    std::list<std::string> listaPalabras;

    palArchivo.open(nomArchivo);

    if(!palArchivo.is_open())
    {
        std::cout << "No se pudo abrir el archivo\n";
        return listaPalabras;
    }

    while(std::getline(palArchivo, palabra))
    {
        listaPalabras.push_back(palabra);
    }

    return listaPalabras;
}

int contarPalSinLetra(const std::list<std::string> palabras, char letra)
{
    int numPalabras = 0;
    bool hayLetra;
    for(auto &pal:palabras)
    {
        hayLetra = false;
        for(int i = 0; i < pal.size(); i++)
        {
            if(pal[i] == letra) hayLetra = true;
        }
        if(!hayLetra) numPalabras++;
    }
    return numPalabras;
}

void eliminarPalOtroTam(std::list<std::string> &palabras, int tamMax)
{
    std::list<std::string>::iterator it;
    it =  palabras.begin();
    while(it != palabras.end())
    {
        if(it->length() != tamMax)
        {
            /*Una vez borrado, erase() apunta al siguiente item.
            Para evitar que haya fuga de memoria. Como una lista anidada*/
            it = palabras.erase(it);
        }
        else
        {
            it++;
        }
    }
}

void mostrarLista(const std::list<std::string> palabras)
{
    for(auto &pal:palabras)
    {
        std::cout << pal << '\n';
    }
}

bool estaPosEnPatron(const std::list<int> &patron, int pos)
{
    //Esta la poscion(número) en la lista de numeros
    std::list<int>::const_iterator it;
    it = patron.begin();
    while(it != patron.end())
    {
        if(*it == pos)
        {
            return true;
        }
        it++;
    }
    return false;
}

bool esIgualaPatron(std::string palabra, char letra,
                    std::list<int> patron)
{
    for(int i = 0; i < palabra.length(); i++)
    {
        if(palabra[i] == letra)
        {
            //Si la posición de la letra no esta en el patrón
            if(!estaPosEnPatron(patron, i))
            {
                return false;
            }
        else
        {
            if(estaPosEnPatron(patron, i))
            {
                return false;
            }
        }
        }
    }
    return true;
}

void eliminarPalSinLetra(std::list<std::string> &palabras,
                         char letraRequerida)
{
    std::list<std::string>::const_iterator it;
    it = palabras.begin();
    while (it != palabras.end())
    {
        if (it->find(letraRequerida) == std::string::npos)
        {
            it = palabras.erase(it);
        }
        else
        {
            it++;
        }
    }
}

void eliminarPalConLetra(std::list<std::string> &palabras,
                         char letraProhibida)
{
    std::list<std::string>::const_iterator it;
    it = palabras.begin();
    while (it != palabras.end())
    {
        if (it->find(letraProhibida) != std::string::npos)
        {
            it = palabras.erase(it);
        }
        else
        {
            it++;
        }
    }
}

void patronMasFrecPoLetra(std::list<std::string> &palabras,
                         char letra, std::list<int> &patron,
                         int &contPatronMax)
{
    /* Toma la primera palabra de la lista, y cuenta cuántas otras
       palabras de la lista tienen el mismo patrón. Se borrarán de la
       lista a medida que las cuente. Luego el proceso hasta que la
       lista quede vacía
       */
       eliminarPalSinLetra(palabras, letra);
       std::list<std::string>::iterator it;
       contPatronMax = 0;
       while(palabras.size() > 0)
       {
           it = palabras.begin();
           std::list<int> patronActual;
           //Primera palabra de la lista, crear su patrón
           for(int i = 0; i < it->length(); i++)
           {
               if((*it)[i] == letra)
               {
                   patronActual.push_back(i);
               }
           }
           int contPatronActual = 1;
           it = palabras.erase(it);
           //Cuantas palabras encajan
           while(it != palabras.end())
           {
               //Si la palabra encaja en el patrón
               if(esIgualaPatron(*it, letra, patronActual))
               {
                   contPatronActual++;
                   it = palabras.erase(it);
               }
               else
               {
                   it++;
               }
           }
           if(contPatronActual > contPatronMax)
           {
               contPatronMax = contPatronActual;
               patron = patronActual;
           }
           patronActual.clear();
       }
}

void mostrarAdivinadas(bool letras[26])
{
    std::cout << "Letras adivinidas: ";
    for(int i = 0; i < 26; i++)
    {
        if(letras[i]) std::cout << char('a' - i) << " ";
    }
    std::cout << '\n';
}


void reducirPorPatron(std::list<std::string> &palabras,
                         char letraProhibida, std::list<int> &patron)
{
    std::list<std::string>::const_iterator it;
    it = palabras.begin();
    while (it != palabras.end())
    {
        if (!esIgualaPatron(*it, letraProhibida, patron))
        {
            it = palabras.erase(it);
        }
        else
        {
            it++;
        }
    }
}

int main()
{
    std::list<std::string> palabras = extraerPalabrasArch("palabras.txt");

    const int tamPalabra = 8;
    const int erroresMax = 9;
    int errores = 0;
    int contLetraUsada = 0;
    eliminarPalOtroTam(palabras, tamPalabra);
    char palRevelada[tamPalabra + 1] = "********";
    bool letrasUsadas[26];
    for(auto &letra:letrasUsadas) letra = false;
    char letraSiguiente;

    std::cout << "Palabra hasta ahora " << palRevelada << '\n';

    while(contLetraUsada < tamPalabra && errores < erroresMax)
    {
        //Pedir la letra al usuario
        std::cout << "Ingresa una letra >> ";
        std::cin >> letraSiguiente;
        //Marcar la letra como usada
        letrasUsadas[letraSiguiente - 'a'] = true;
        //Cuantas palabras puede haber en la lista sin esa letra
        int contError = contarPalSinLetra(palabras, letraSiguiente);
        std::list<int> stePatron;
        int contStePatron;
        //Cuantas palabras puede haber con esa letra.
        patronMasFrecPoLetra(palabras, letraSiguiente, stePatron, contStePatron);
        //si hay más palabras sin esa letra en una posición, elimina las que la tengan
        if(contError > contStePatron)
        {
            //Suma error
            eliminarPalConLetra(palabras, letraSiguiente);
            errores++;
        }
        //Si existen más palabras con esa letra en una posición determinada
        else
        {
            //Busca otra posición (patrón) pero se deja la letra como valida
            //La siguiente palabra a buscar debe tener esa letra
            std::list<int>::iterator it = stePatron.begin();
            while(it != stePatron.end())
            {
                contLetraUsada++;
                palRevelada[*it] = letraSiguiente;
                it++;
            }
            reducirPorPatron(palabras, letraSiguiente, stePatron);
        }
        std::cout << "Palabra hasta ahora " << palRevelada << '\n';
        mostrarAdivinadas(letrasUsadas);
    }

    return 0;
}
