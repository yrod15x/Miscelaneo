/*If you’ve learned about binary numbers and how to convert from decimal
to binary, try writing programs to do that conversions(but you can assume
the numbers are small enough to be stored in a standard C++ int)*/

#include <iostream>

const int MAX_RANGE = 21474999;


void deceBinario(int number)
{
    if(number >= (MAX_RANGE * -1) && number <= MAX_RANGE)
    {
        char *numBinario = new char;
        int index = 0;
        bool esNegativo = false;

        if(number < 0) esNegativo = true;
        number = abs(number);

        while(number > 0)
        {
            numBinario[index] = ('0' + (number % 2));
            number = number / 2;
            index++;
        }

        if(esNegativo) std::cout << '-';

        for(int i = index -1; i >= 0; i--)
        {
            std::cout << numBinario[i];
        }
    }
    else
    {
        std::cout << "Numero excede los limites posibles.\n";
    }

    std::cout << '\n';
}

int main()
{
    deceBinario(21474999);
    return 0;
}
