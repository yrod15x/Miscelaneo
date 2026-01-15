/** Programa que decifra un mensaje escrito en digitos  enteros **/

#include <iostream>

int main()
{
    char digitChar;
    char outputCharacter;
    enum modeType {UPPERCASE, LOWERCASE, PUNCTUATION};
    modeType mode = UPPERCASE;

    do
    {
        digitChar = std::cin.get();
        int number = (digitChar - '0');
        digitChar = std::cin.get();
        while((digitChar != 10) && (digitChar != ','))
        {
           number =  number * 10 + (digitChar - '0');
           digitChar = std::cin.get();
        }
        switch(mode)
        {
        case UPPERCASE:
            number = number % 27;
            outputCharacter = number + 'A' - 1;
            if(number == 0)
            {
                mode = LOWERCASE;
                continue;
            }
        break;
        case LOWERCASE:
            number = number % 27;
            outputCharacter = number + 'a' - 1;
            if(number == 0)
            {
                mode = PUNCTUATION;
                continue;
            }
        break;
        case PUNCTUATION:
            number = number % 9;
            switch(number)
            {
                case 1: outputCharacter = '!';
                case 2: outputCharacter = '?';
                case 3: outputCharacter = '!';
                case 4: outputCharacter = ',';
                case 5: outputCharacter = '.';
                case 6: outputCharacter = ' ';
                case 7: outputCharacter = '\"';
                case 8: outputCharacter = '\'';
            }
            if(number == 0)
            {
                mode = UPPERCASE;
                continue;
            }
            break;
        }
        std::cout << outputCharacter;
    }while(digitChar != 10);
    std::cout <<'\n';

    return 0;
}
