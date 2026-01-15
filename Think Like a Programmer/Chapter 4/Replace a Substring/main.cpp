/* For our dynamically allocated strings, create a function replaceString that takes
three parameters, each of type arrayString: source, target, and replaceText.
The function replaces every occurrence of target in source with replaceText.
For example, if source points to an array containing abcdabee, target points to
ab, and replaceText points to xyz, then when the function ends, source should
point to an array containing xyzcdxyzee. */
#include <iostream>

typedef char *cadenaTexto;

int contCaracteres(cadenaTexto texto)
{
    int cont = 0;

    while(texto[cont] != 0)
    {
        cont++;
    }
    return cont;
}

bool sonIguales(cadenaTexto texto1, cadenaTexto texto2, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        if(texto1[i] != texto2[i]) return false;
    }
    return true;
}

cadenaTexto remplazar(cadenaTexto original, cadenaTexto objetivo,
                cadenaTexto remplazante)
{
    int tamOriginal = contCaracteres(original);
    int tamObjetivo = contCaracteres(objetivo);
    int tamRemplazante = contCaracteres(remplazante);
    cadenaTexto temp = new char[tamObjetivo];
    cadenaTexto tempOriginal = new char[tamOriginal + tamRemplazante];
    int contMayor = 0;

    for(int i = 0; i < tamOriginal; i++)
    {
        int cont = 0;
        for(int j = i; j < i + tamObjetivo; j++)
        {
            temp[cont] = original[j];
            cont++;
        }
        if(sonIguales(temp, objetivo, tamObjetivo))
        {
            for(int m = i; m < tamRemplazante + i; m++)
             {
                tempOriginal[contMayor] = remplazante[m - i];
                contMayor++;
             }
            //limpio el arreglo temporal;
            temp[0] = '\0';
            i++;
            continue;
        }
            tempOriginal[contMayor] = original[i];
            contMayor++;
    }
    delete[] temp;
    return tempOriginal;
}


int main()
{
    cadenaTexto original = "abcdabe";
    cadenaTexto objetivo = "ab";
    cadenaTexto remplazante = "xyz";
    int tamOriginal = contCaracteres(original);
    int tamObjetivo = contCaracteres(objetivo);
    int tamRemplazante = contCaracteres(remplazante);
    cadenaTexto textoNuevo = new char[tamOriginal + (tamRemplazante - tamObjetivo)];

    textoNuevo = remplazar(original, objetivo, remplazante);
    int tamTextNuevo = contCaracteres(textoNuevo);
    for(int i = 0; i < tamTextNuevo; i++)
    {
        std::cout << textoNuevo[i];
    }

    return 0;
}
