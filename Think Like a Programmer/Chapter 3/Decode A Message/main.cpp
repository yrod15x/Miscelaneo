/** Programa que decifra un mensaje escrito en digitos  enteros **/

#include <iostream>


char devolverCaracter(int numero, char modo)
{
    /**
     * Convierte un nuúmero a un caracter Ascii.
     *
     * @param numero. Entero a dividir por 27 o 9.
     " @param modo. Caracter señala el modo actual: u -> mayúsculas, l -> minúsculas,
              p -> puntuación.
     * @return Devuelve un caracter Ascii en mayúsculas, minúsculas o signo de puntuación.
     */
    char caracter;
    int restante = numero % 9;;
    switch(modo)
    {
        case 'u':
            caracter = char(numero % 27 + 64);
        break;
        case 'l':
            caracter = char(numero % 27 + 96);
        break;
        case 'p':
            if(restante == 1) caracter = '!';
            else if(restante == 2) caracter = '?';
            else if(restante == 1) caracter = '!';
            else if(restante == 3) caracter = ',';
            else if(restante == 4) caracter = '.';
            else if(restante == 5) caracter = ' ';
            else if(restante == 6) caracter = ';';
            else if(restante == 7) caracter = '\"';
            else if(restante == 4) caracter = '\'';
        break;
    }
    return caracter;
}

void cambiarModo(char &modo, int number)
{
    /**
     * Cambia un caracter a otro mediante una operación matemática. u -> l, l -> p, p -> u
     *
     * @param numero. Entero a dividir por 27 o 9.
     " @param modo. Caracter señala el modo actual: u -> mayúsculas, l -> minúsculas,
              p -> puntuación.
     */
        switch(modo)
        {
            if(number % 27 == 0)
            {
                case 'u':
                case 'U':
                    modo = 'l';
                break;
                case 'l':
                case 'L':
                    modo = 'p';
                break;
            }
            if(number % 9 == 0)
            {
                case 'p':
                case 'P':
                    modo = 'u';
                break;
            }
        }

}

void decifrarMensaje(char *mensaje)
{
    int index = 0;
    int number = 0;
    char modo = 'u';
    do
    {
        if(mensaje[index] >= 48 and mensaje[index] <= 57)
        {
            number = number * 10 + mensaje[index] - '0';
        }
        else
        {
            if(modo == 'u' || modo == 'l')
            {
                if(number % 27 != 0)
                {
                    std::cout << devolverCaracter(number, modo);
                }
                else
                {
                    cambiarModo(modo, number);
                }
            }
            else if(modo == 'p')
            {
                if(number % 9 != 0)
                {
                    std::cout << devolverCaracter(number, modo);
                }
                else
                {
                    cambiarModo(modo, number);
                }
            }
            number = 0;

        }
        index++;

    }while(mensaje[index] != '\0');
}

char *leerMensaje()
{
    /**
     * Lee caracteres de un texto en pantalla y los almacena.
     * @return Devuelve un  un puntero dinámico con los carácteres individuales de un texto.
     */
    char *mensaje = new char;
    char caracter;
    int cont = 0;
    while(caracter != 10)
    {
        caracter = std::cin.get();
        mensaje[cont] = caracter;
        cont++;
        if(caracter == 10)
        {
           mensaje[cont] = ',';
        }
    }

    return mensaje;
}

int main()
{

    std::cout << "*** Decifrador de Mensajes ***\n\n";
    std::cout << "Ingrese los digitos de su mensaje. Use espacios >> ";
    //char *mensaje = "18,12312,171,763,98423,1208,216,11,500,18,241,0,32,20620,27,10,\0";
    char *mensaje = leerMensaje();
    decifrarMensaje(mensaje);

    return 0;
}
